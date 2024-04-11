#include <bits/stdc++.h>
using namespace std;
#define Maxn 100007
int T,n,k,z;
int a[Maxn];
void solve()
{
    scanf("%d%d%d",&n,&k,&z);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    long long ans=0LL;
    for (int i=min(z,k/2);i>=0;i--)
    {
        long long tmp=0LL;
        for (int j=1;j<=k-2*i+1;j++)
            tmp+=a[j];
        int mx=0;
        for (int j=1;j<=k-2*i+1;j++)
            mx=max(mx,a[j]+a[j+1]);
        tmp+=1LL*i*mx;
        ans=max(ans,tmp);
    }
    printf("%lld\n",ans);
}
int main()
{
    scanf("%d",&T);
    while (T--) solve();
    return 0;
}