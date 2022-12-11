#include <bits/stdc++.h>
using namespace std;
#define Maxn 300007
int n,k,p;
int a[Maxn];
long long ans=0LL;
map<int,int> mp;
int calc(int x)
{
    int res=(1LL*x*x)%p;
    res=(1LL*res*res)%p;
    res=(res+p-(1LL*k*x)%p)%p;
    return res;
}
int main()
{
    scanf("%d%d%d",&n,&p,&k);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    mp.clear();
    for (int i=1;i<=n;i++)
    {
        int t=calc(a[i]);
        ans+=mp[t];
        ++mp[t];
    }
    printf("%lld\n",ans);
    return 0;
}