#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<math.h>
#include<string>
#include<time.h>
#include<bitset>
#include<vector>
#include<memory>
#include<utility>
#include<stdio.h>
#include<sstream>
#include<fstream>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
char a[100005][15];
int block=500;
int dp[100005][15][2];
int n,m,k;
int limitx;
void dfs(int x,int y)
{
    if ((x<=0)||(x>n)||(y<=0)||(y>m))
    {
        dp[x][y][0]=x;
        dp[x][y][1]=y;
        return;
    }
    if (dp[x][y][0]!=-2) return;
    dp[x][y][0]=-1;
    dp[x][y][1]=-1;
    if (a[x][y]=='^')
    {
        if (x-1==limitx)
        {
            dp[x][y][0]=x-1;
            dp[x][y][1]=y;
        }
        else
        {
            dfs(x-1,y);
            dp[x][y][0]=dp[x-1][y][0];
            dp[x][y][1]=dp[x-1][y][1];
        }
    }
    else if (a[x][y]=='<')
    {
        dfs(x,y-1);
        dp[x][y][0]=dp[x][y-1][0];
        dp[x][y][1]=dp[x][y-1][1];
    }
    else if (a[x][y]=='>')
    {
        dfs(x,y+1);
        dp[x][y][0]=dp[x][y+1][0];
        dp[x][y][1]=dp[x][y+1][1];
    }
    else
    {
        dp[x][y][0]=x;
        dp[x][y][1]=y;
    }
}
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    scanf("%d%d%d",&n,&m,&k);
    int i;
    memset(a,'\0',sizeof(a));
    for (i=1;i<=100000;i++)
    {
        if (i<=n) scanf("%s",a[i]+1);
        if (i%block==0)
        {
            limitx=i-block;
            int j;
            for (j=limitx+1;j<=i;j++)
            {
                int k;
                for (k=1;k<=m;k++)
                {
                    dp[j][k][0]=-2;
                }
            }
            for (j=limitx+1;j<=i;j++)
            {
                int k;
                for (k=1;k<=m;k++)
                {
                    dfs(j,k);
                }
            }
        }
    }
    for (i=0;i<k;i++)
    {
        static char oper[5];
        scanf("%s",oper);
        int x,y;
        scanf("%d%d",&x,&y);
        if (oper[0]=='A')
        {
            for (;;)
            {
                if ((x<=0)||(x>n)||(y<=0)||(y>m)) break;
                int tx=dp[x][y][0];
                int ty=dp[x][y][1];
                x=tx;
                y=ty;
            }
            printf("%d %d\n",x,y);
        }
        else
        {
            static char change[5];
            scanf("%s",change);
            a[x][y]=change[0];
            limitx=(x-1)/block*block;
            int t=limitx+block;
            int j;
            for (j=limitx+1;j<=t;j++)
            {
                int k;
                for (k=1;k<=m;k++)
                {
                    dp[j][k][0]=-2;
                }
            }
            for (j=limitx+1;j<=t;j++)
            {
                int k;
                for (k=1;k<=m;k++)
                {
                    dfs(j,k);
                }
            }
        }
    }
    return 0;
}