#include <bits/stdc++.h>
using namespace std;
#define Maxn 200007
int n;
long long a[Maxn];
int b[Maxn];
int que[Maxn],stk=0;
int anss[Maxn],tot=0;
long long ans=0LL;
int last[Maxn],pre[Maxn],other[Maxn],cnt=0;
void insert(int u,int v)
{
    other[++cnt]=v,pre[cnt]=last[u],last[u]=cnt;
}
void dfs(int u)
{
    for (int q=last[u];q;q=pre[q])
    {
        int v=other[q];
        dfs(v);
        if (a[v]<0) que[++stk]=v; else
        {
            a[u]+=a[v];
            anss[++tot]=v;
        }
    }
    ans+=a[u];
    if (b[u]==-1) anss[++tot]=u;
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&b[i]);
        if (b[i]!=-1) insert(b[i],i);
    }
    for (int i=1;i<=n;i++)
    {
        if (b[i]==-1) dfs(i);
        for (int j=stk;j;j--)
            anss[++tot]=que[j];
        stk=0;
    }
    printf("%lld\n",ans);
    for (int i=1;i<=tot;i++)
        printf("%d ",anss[i]);
    printf("\n");
    return 0;
}