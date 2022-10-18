#include<bits/stdc++.h>

using namespace std;

int main()
{
    char c[4][4];
    scanf("%c%c%c%c%*c%c%c%c%c%*c%c%c%c%c%*c%c%c%c%c",
          &c[0][0],&c[0][1],&c[0][2],&c[0][3],
          &c[1][0],&c[1][1],&c[1][2],&c[1][3],
          &c[2][0],&c[2][1],&c[2][2],&c[2][3],
          &c[3][0],&c[3][1],&c[3][2],&c[3][3]);
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if((((c[i  ][j  ]=='#')?1:0)+
                ((c[i+1][j  ]=='#')?1:0)+
                ((c[i  ][j+1]=='#')?1:0)+
                ((c[i+1][j+1]=='#')?1:0))!=2)
                return printf("YES"),0;
    printf("NO");
}