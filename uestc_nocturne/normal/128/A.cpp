#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long LL;
int dp[10][10][102];
int dx[]={-1,-1,-1,0,0,0,1,1,1};
int dy[]={-1,0,1,-1,0,1,-1,0,1};
int ex,ey,can[120][10][10];
int dfs(int x,int y,int t)
{
    if(x==ex&&y==ey)return 1;
    if(dp[x][y][t]!=-1)return dp[x][y][t];
//  printf("%d %d %d\n",x,y,t);
    dp[x][y][t]=0;if(t>90)return 0;
    for(int i=0;i<9;i++)
    {
        int tx=x+dx[i];
        int ty=y+dy[i];
        if(tx<0||tx>=8)continue;
        if(ty<0||ty>=8)continue;
        if(!can[t][tx][ty])continue;
        if(!can[t+1][tx][ty])continue;
        if(dfs(tx,ty,t+1))
        {
            dp[x][y][t]=1;
            return 1;
        }
    }
    return dp[x][y][t];
}
char map[120][120];
int i,j,k;
int main()
{
    while(~scanf("%s",map[0]))
    {
        for(i=1;i<8;i++)
        scanf("%s",map[i]);
        memset(dp,-1,sizeof(dp));
        ex=0;ey=7;
        for(i=0;i<100;i++)
        {
            for(j=0;j<8;j++)
            for(k=0;k<8;k++)
            {
                if(j>=i&&map[j-i][k]=='S')
                can[i][j][k]=0;
                else can[i][j][k]=1;
            }
        }
        if(dfs(7,0,0))puts("WIN");
        else puts("LOSE");
    }
}