#include <bits/stdc++.h>
#define modp 1000000007
#define Maxn 200007
using namespace std;
int n;
long long val[Maxn];
int last[Maxn],pre[Maxn],other[Maxn],cnt=0;
int dep[Maxn];
int ans=0;
vector<pair<long long,int> >que[Maxn];
long long gcd(long long x,long long y)
{
    return y==0LL?x:gcd(y,x%y);
}
void insert(int u,int v)
{
    other[++cnt]=v,pre[cnt]=last[u],last[u]=cnt;
}
void dfs(int u,int fa)
{
    for (int q=last[u];q;q=pre[q])
    {
        int v=other[q];
        if (v!=fa)
        {
            dep[v]=dep[u]+1;
            que[v].push_back(make_pair(val[v],dep[v]));
            long long tmp=val[v];
            int pos=dep[v];
            for (int i=0;i<(int)que[u].size();i++)
            {
                long long now=gcd(val[v],que[u][i].first);
                if (now!=tmp)
                {
                    ans=(ans+1LL*(tmp%modp)*(pos-que[u][i].second))%modp;
                    tmp=now;
                    pos=que[u][i].second;
                    que[v].push_back(make_pair(now,pos));
                }
            }
            ans=(ans+1LL*(tmp%modp)*(pos+1))%modp;
            dfs(v,u);
        }
    }
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%lld",&val[i]);
    for (int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        insert(u,v),insert(v,u);
    }
    que[1].push_back(make_pair(val[1],0));
    ans=(ans+val[1])%modp;
    dfs(1,-1);
    printf("%d\n",ans);
    return 0;
}