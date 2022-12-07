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
struct edge
{
    int y;
    edge * next;
};
edge * new_edge()
{
    static edge a[600005];
    static int top=0;
    return &a[top++];
}
edge * li[300005];
void inserts(int x,int y)
{
    edge * t=new_edge();
    t->y=y;
    t->next=li[x];
    li[x]=t;
}
void insert_edge(int x,int y)
{
    inserts(x,y);
    inserts(y,x);
}
const int modo=998244353;
int vis[300005];
int temp[300005];
int mul1[300005];
int mul2[300005];
int dp[300005][3];
void dfs(int x)
{
    vis[x]=1;
    edge * t;
    for (t=li[x];t!=0;t=t->next)
    {
        if (vis[t->y]==1)
        {
            continue;
        }
        dfs(t->y);
    }
    dp[x][1]=1;
    dp[x][2]=1;
    for (t=li[x];t!=0;t=t->next)
    {
        if (vis[t->y]==1)
        {
            continue;
        }
        dp[x][1]=(long long)dp[x][1]*(dp[t->y][0]*2%modo+dp[t->y][2])%modo;
        dp[x][2]=(long long)dp[x][2]*(dp[t->y][0]+dp[t->y][2])%modo;
    }
    int cnt=0;
    for (t=li[x];t!=0;t=t->next)
    {
        if (vis[t->y]==1)
        {
            continue;
        }
        temp[cnt++]=t->y;
    }
    int i;
    mul1[0]=1;
    for (i=0;i<cnt;i++)
    {
        mul1[i+1]=(long long)mul1[i]*(dp[temp[i]][0]*2%modo+dp[temp[i]][2])%modo;
    }
    mul2[cnt]=1;
    for (i=cnt-1;i>=0;i--)
    {
        mul2[i]=(long long)mul2[i+1]*(dp[temp[i]][0]*2%modo+dp[temp[i]][2])%modo;
    }
    for (i=0;i<cnt;i++)
    {
        dp[x][0]=(dp[x][0]+(long long)mul1[i]*mul2[i+1]%modo*dp[temp[i]][1])%modo;
    }
    vis[x]=2;
}
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    scanf("%d",&n);
    int i;
    for (i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        x--;
        y--;
        insert_edge(x,y);
    }
    dfs(0);
    printf("%d\n",(dp[0][0]+dp[0][2])%modo);
    return 0;
}