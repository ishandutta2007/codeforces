#include <bits/stdc++.h>
using namespace std;
const int Maxn=300005;
struct edg
{
    int nxt,to,w;
}edge[2*Maxn];
int val[Maxn],head[Maxn],cnt,n;
long long dp[Maxn],ans;
void add(int x,int y,int w)
{
    edge[++cnt]=(edg){head[x],y,w};
    head[x]=cnt;
}
void dfs(int u,int fa)
{
    dp[u]=val[u];
    for(int i=head[u];i;i=edge[i].nxt)
    {
        int to=edge[i].to;
        if(to!=fa)
        {
            dfs(to,u);
            ans=max(ans,dp[u]+dp[to]-edge[i].w);
            dp[u]=max(dp[u],dp[to]-edge[i].w+val[u]);
        }
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&val[i]),ans=max(ans,(long long)val[i]);
    for(int i=1;i<n;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c);
        add(b,a,c);
    }
    dfs(1,0);
    printf("%lld",ans);
    return 0;
}