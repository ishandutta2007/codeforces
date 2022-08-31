/*input
4 6
1 2
1 3
1 4
2 3
2 4
3 4

*/
     
#include<iostream>
using namespace std;

#define SIZE 20

bool map[SIZE][SIZE],F;
long long f[1<<SIZE][SIZE],res=0;

int main()
{
    int n,m,i,j,k,l,x,y;
    scanf("%d%d",&n,&m);
    for (i=0;i<m;i++)
    {
        scanf("%d%d",&x,&y);
        x--;y--;
        if (x>y)
           swap(x,y);
        map[x][y]=map[y][x]=1;
        f[(1<<x)+(1<<y)][y]=1;
    }
    
    for (i=7;i<(1<<n);i++)
    {
        F=1;
        for (j=0;j<n;j++)
            if (i&(1<<j) && f[i][j]==0)
            {
               if (F)
               {
                  F=0;
                  k=j;
                  continue;
               }
               for (l=k+1;l<n;l++)
               {
                   if (i&(1<<l) && map[j][l])
                      f[i][j]+=f[i-(1<<j)][l];
               }
               if (map[k][j])
                  res+=f[i][j];
            }
    }
    printf("%lld\n",res/2);
}