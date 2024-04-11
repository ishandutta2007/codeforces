#include <bits/stdc++.h>
#define Maxn 300007
using namespace std;
int a[Maxn],b[Maxn];
pair<int,int> x[Maxn];
int n,m;
long long ans[Maxn];
void calc(int u,int v)
{
    ans[u]-=min(a[u]+b[v],a[v]+b[u]);
    ans[v]-=min(a[u]+b[v],a[v]+b[u]);
}
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
    {
        scanf("%d%d",&a[i],&b[i]);
        x[i]=make_pair(a[i]-b[i],i);
    }
    memset(ans,0,sizeof(ans));
    sort(x+1,x+n+1);
    long long sum1=0,sum2=0;
    for (int i=1;i<=n;i++)
        sum2+=b[i];
    for (int i=1;i<=n;i++)
    {
        sum2-=b[x[i].second];
        ans[x[i].second]+=sum1+sum2+1LL*a[x[i].second]*(n-i)+1LL*b[x[i].second]*(i-1);
        sum1+=a[x[i].second];
    }
    for (int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        calc(u,v);
    }
    for (int i=1;i<=n;i++)
        printf("%lld ",ans[i]);
    printf("\n");
    return 0;
}