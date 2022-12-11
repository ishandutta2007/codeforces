#include <bits/stdc++.h>
using namespace std;
int T,n;
long long l1,r1,l2,r2,k;
long long tmp1,tmp2;
void solve()
{
    scanf("%d%lld",&n,&k);
    scanf("%lld%lld",&l1,&r1);
    scanf("%lld%lld",&l2,&r2);
    if (r1<l2)
    {
        tmp1=l2-r1;
        tmp2=r2-l1;
    } else if (r2<l1)
    {
        tmp1=l1-r2;
        tmp2=r1-l2;
    } else
    {
        tmp1=0;
        long long mn=min(r1,r2)-max(l1,l2);
        long long mx=max(r1,r2)-min(l1,l2);
        k-=1LL*n*mn;
        tmp2=mx-mn;
    }
    if (k<=0LL) printf("%d\n",0); else
    {
        long long ans=1000000000000000000LL;
        for (int i=1;i<=n;i++)
        {
            long long tmp=1LL*i*tmp1;
            if (1LL*tmp2*i>=k) tmp+=k; else tmp+=k+k-1LL*tmp2*i;
            ans=min(ans,tmp);
        }
        printf("%lld\n",ans);
    }
}
int main()
{
    scanf("%d",&T);
    while (T--) solve();
    return 0;
}