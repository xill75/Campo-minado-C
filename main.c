#include<stdio.h>
#include <stdlib.h>
#include <time.h>



//Requisitos:
//- Tabuleiro de 15x15 *
//- Nível de dificuldade: 20% a 70% de minas *
//- Distribuição Aleatória das minas*
//- Início aleatória nas bordas do tabuleiro*
//- A cada rodada pode se mover pelas células adjacentes apenas *
//- Desenvolvido em linguagem C *


//- 0=Casa vazia ,1=Casa com mina,3=Casa do jogador

void imprimeMatriz (int matriz[15][15]);
void spawn(int matriz [15] [15],int *pos_linha, int *pos_coluna);

int main (void ){
    int matriz[15][15];//variavel matriz
    int i,j;//contador de interação
    int dificuldade;
    int casas_com_mina;
    int detona_pe=0;//mina explode *bumm*
    int pos_linha=0;//posição linha
    int pos_coluna=0;//posição coluna
    int player;

    srand(time(NULL));//utilizado para o randomizador funcionar

    spawn(matriz,&pos_linha,&pos_coluna);//Invoca  a função spawn



    for(i=0;i<15;i++)//zerado a matriz para a realização da geração de minas,player e casa vazias
        for(j=0;j<15;j++)
            matriz[i][j]=0;



    printf("Insira a dificuldade desejada(entre 2 e 7): ");
    scanf("%d", &dificuldade);

    casas_com_mina=225*((float)dificuldade/10);//realiza calculo para definir gerador de minas 225=15*15=n total de casas



    for (i = 0; i < casas_com_mina; i++) //gerador de minas
        matriz [rand() % 15] [rand() % 15] = 1;//define se a casa sera uma mina





    matriz[pos_linha][pos_coluna]=3;



    while(detona_pe==0) {  //Codigo para o funcionamento do andar do player sobre a matriz

        imprimeMatriz(matriz);
        printf("\nComandos:\n\nesquerda: 1\ncima: 2\nbaixo: 3\ndireita: 4");
        printf("\n\njogada: ");
        scanf("%d", &player);



        if (player == 1)//movimento para esquerda,e checa se movimento pode ser realizado(vale para todos)
            if (pos_coluna > 0) {
                matriz [pos_linha] [pos_coluna] = 2;
                pos_coluna--;
            }
            else{
                printf("\nMovimento invalido\n");
                continue;

            }

        else if (player == 4)//movimento direita
            if (pos_coluna < 14){
                matriz [pos_linha] [pos_coluna] = 2;
                pos_coluna++;}
            else{
                printf("\nMovimento invalido\n");
                continue;

            }

       else if (player == 2) //movimento para baixo
            if (pos_linha > 0){
                matriz [pos_linha] [pos_coluna] = 2;
                pos_linha--;
            }
            else{
                printf("\nMovimento invalido\n");
                continue;

            }

       else if (player == 3)//movimento para cima
           if(pos_linha <14) {
               matriz [pos_linha] [pos_coluna] = 2;
               pos_linha++;
           }
           else{
               printf("\nMovimento invalido\n");
               continue;
           }
           else
               printf("insira um numero valido!!");//caso a pessoa adicione um valor não contado o programa ira dar esta mensagem

       if(matriz[pos_linha][pos_coluna]==1){
           printf("\nVoce morreu vacilao\n");//indentifica se o player pissou em uma mina e finaliza o jogo caso sim
           detona_pe=1;
           break;}
       matriz[pos_linha] [pos_coluna]=3;
    }
}

void imprimeMatriz (int matriz[15][15])//Realiza a impressão da tabela númerica tabuleiro mostrando as linhas e colunas//
{
    int i, j;// i=linha e j=coluna

    printf("\n ");

    for (i = 0; i < 15; i++) {


        for (j = 0; j < 15; j++) {
            if (matriz[i][j] == 2) {
                printf("%2c", '0');//Caminho percorido
            }
            else if(matriz [i] [j]==3)
            {
              printf("%2c", '@');//localização do player
            }
            /*
                else if(matriz [i] [j]==1)
            {
                printf("%2c", 'M');//mostrar as minas
            }
                */
            else {
                printf("%2c", 'x');//Restante do tabuleiro
            }


        }
        printf("\n ");






    }


}

void spawn(int matriz [15] [15],int *pos_linha, int *pos_coluna)//Realiza o spawn do player nas bordas *=ponteiro
{
    int i, j, spawn;

    srand(time(NULL));


    for(i = 0; i < 15; i++)
        for (j = 0; j < 15; j++)
            matriz [i] [j] = 0;

    j = 1;

    //Borda Superior
    for (i = 0; i < 15; i++, j++)
        matriz [0] [i] = j;

    //Borda Direita
    for (i = 1; i < 15; i++, j++)
        matriz [i] [14] = j;

    //Borda Inferior
    for (i = 13; i >= 0; i--, j++)
        matriz [14] [i] = j;

    //Borda Esquerda
    for (i = 13; i > 0; i--,j++)
        matriz [i] [0] = j;

    spawn = rand () % 55;//Randomiza o spawn



    for (i = 0; i < 15; i++)
    {
        for (j = 0; j < 15; j++)
        {
            if (matriz [i] [j] == spawn)
            {
                *pos_linha = i;
                *pos_coluna = j;
                break;
            }
        }
    }




}




