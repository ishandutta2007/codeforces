#include<bits/stdc++.h>
using namespace std;
const int max_n=2e5+5;
int End[max_n<<1],Last[max_n],Next[max_n<<1],e;
inline void add_edge(int x,int y)
{
    End[++e]=y;
    Next[e]=Last[x];
    Last[x]=e;
    End[++e]=x;
    Next[e]=Last[y];
    Last[y]=e;
}
int dep[max_n],dp[max_n][3];
void dfs(int x,int fa)
{
    /*
    dp[x][0]: x unsatisfied
    dp[x][1]: x satisfied without adding an edge to x
    dp[x][2]: x satisfied by adding an edge to x
    */
    /*
    dp[x][0] <- sum of {dp[y][1],dp[y][2]} for all sons y
    dp[x][1] <- sum of dp[y][2] for some son(s) y and dp[y][1] for other sons y
    dp[x][2] <- sum of min{dp[y][0],dp[y][1],dp[y][2]} for all sons y and 1
    */
    dep[x]=dep[fa]+1;
    dp[x][2]=1;
    bool flag=false;
    for(int i=Last[x];i;i=Next[i])
    {
        int y=End[i];
        if(y!=fa)
        {
            dfs(y,x);
            dp[x][0]+=min(dp[y][1],dp[y][2]);
            dp[x][2]+=min(min(dp[y][0],dp[y][1]),dp[y][2]);
            if(dp[y][2]<=dp[y][1])
            {
                dp[x][1]+=dp[y][2];
                flag=true;
            }
            else
                dp[x][1]+=dp[y][1];
        }
    }
    if(!flag)
    {
        int delta=1e9;
        for(int i=Last[x];i;i=Next[i])
        {
            int y=End[i];
            if(y!=fa)
                delta=min(delta,dp[y][2]-dp[y][1]);
        }
        dp[x][1]+=delta;
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n-1;++i)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        add_edge(u,v);
    }
    dep[0]=-1;
    dfs(1,0);
    int ans=0;
    for(int i=1;i<=n;++i)
    {
        if(dep[i]==2)
            ans+=min(min(dp[i][0],dp[i][1]),dp[i][2]);
    }
    printf("%d\n",ans);
    return 0;
}