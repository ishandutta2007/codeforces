#include <bits/stdc++.h>
using namespace std;
#define Maxn 5007
int T,n;
long long a[Maxn],cnt[Maxn];
void solve()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        cnt[i]=0;
    }
    long long ans=0LL;
    for (int i=1;i<=n;i++)
    {
        long long tmp=max(cnt[i],a[i]-1LL);
        ans+=tmp-cnt[i];
        for (int j=i+2;j<=i+a[i]&&j<=n;j++)
            ++cnt[j];
        if (i+1<=n) cnt[i+1]+=tmp-(a[i]-1LL);
    }
    printf("%lld\n",ans);
}
int main()
{
    scanf("%d",&T);
    while (T--) solve();
    return 0;
}