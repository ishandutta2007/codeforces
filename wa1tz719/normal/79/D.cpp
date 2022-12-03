#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<math.h>
#include<time.h>
#include<vector>
#include<bitset>
#include<memory>
#include<utility>
#include<fstream>
#include<stdio.h>
#include<sstream>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
int dp[1<<20];
int a[10005];
int dist[10005];
int b[105];
int l,n,k;
void bfs(int x)
{
    memset(dist,-1,sizeof(dist));
    int i;
    static int que[10005];
    int front=0,rail=1;
    que[0]=x;
    dist[x]=0;
    for (;front<rail;front++)
    {
        int now=que[front];
        for (i=0;i<l;i++)
        {
            if (now-b[i]>=0)
            {
                if (dist[now-b[i]]==-1)
                {
                    dist[now-b[i]]=dist[now]+1;
                    que[rail++]=now-b[i];
                }
            }
            if (now+b[i]<=n)
            {
                if (dist[now+b[i]]==-1)
                {
                    dist[now+b[i]]=dist[now]+1;
                    que[rail++]=now+b[i];
                }
            }
        }
    }
}
int c[105];
int dis[25][25];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    scanf("%d%d%d",&n,&k,&l);
    int i;
    for (i=0;i<k;i++)
    {
        int x;
        scanf("%d",&x);
        a[x-1]^=1;
        a[x]^=1;
    }
    for (i=0;i<l;i++)
    {
        scanf("%d",&b[i]);
    }
    int sum=0;
    for (i=0;i<=n;i++)
    {
        if (a[i]==1)
        {
            c[sum++]=i;
        }
    }
    for (i=0;i<sum;i++)
    {
        bfs(c[i]);
        int j;
        for (j=0;j<sum;j++)
        {
            dis[i][j]=dist[c[j]];
        }
    }
    memset(dp,-1,sizeof(dp));
    dp[0]=0;
    for (i=0;i<(1<<sum);i++)
    {
        if (dp[i]==-1) continue;
        int j;
        for (j=0;j<sum;j++)
        {
            if ((1<<j)&i) continue;
            break;
        }
        int k;
        for (k=j+1;k<sum;k++)
        {
            if ((1<<k)&i) continue;
            if (dis[j][k]==-1) continue;
            if ((dp[i^(1<<j)^(1<<k)]==-1)||(dp[i^(1<<j)^(1<<k)]>dp[i]+dis[j][k]))
            {
                dp[i^(1<<j)^(1<<k)]=dp[i]+dis[j][k];
            }
        }
    }
    printf("%d\n",dp[(1<<sum)-1]);
    return 0;
}