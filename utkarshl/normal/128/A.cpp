#include"stdio.h"
int reachable[20][8][8]={{{0}}};
int main()
{
        char inp[8][10];
        for(int i=7;i>=0;i--)scanf("%s",inp[i]);
        reachable[0][0][0]=1;
        for(int t=1;t<20;t++)
                for(int i=0;i<8;i++)
                        for(int j=0;j<8;j++)
                        {
                                if(!(i+t-1<8 && inp[i+t-1][j]=='S'))
                                        if(!(i+t<8 && inp[i+t][j]=='S'))
                                                for(int l=i-1;l<i+2&&reachable[t][i][j]==0;l++)
                                                        for(int m=j-1;m<2+j&&reachable[t][i][j]==0;m++)
                                                                if(l>=0&&l<8&&m>=0&&m<8&&reachable[t-1][l][m])reachable[t][i][j]=1;
                        }
        printf(reachable[19][7][7]?"WIN":"LOSE");
}