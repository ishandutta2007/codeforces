#include <bits/stdc++.h>
#define Maxn 2000007
#define modp 998244353
using namespace std;
int last[Maxn],other[Maxn],pre[Maxn],cnt=0;
int n,ans=0,inv=(modp+1)/2;
int f[Maxn];
// f[u] means the posibility that u is free for matching
void insert(int u,int v)
{
    other[++cnt]=v,pre[cnt]=last[u],last[u]=cnt;
}
void dfs(int u,int fa)
{
    f[u]=1;
    for (int q=last[u];q;q=pre[q])
    {
        int v=other[q];
        if (v!=fa)
        {
            dfs(v,u);
            int tmp=(modp+1-(1LL*inv*f[v])%modp)%modp;
            f[u]=(1LL*f[u]*tmp)%modp;
        }
    }
    ans=(ans+1-f[u]+modp)%modp;
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        insert(u,v),insert(v,u);
    }
    dfs(1,-1);
    for (int i=1;i<=n;i++)
        ans=(2LL*ans)%modp;
    printf("%d\n",(ans+modp)%modp);
    return 0;
}