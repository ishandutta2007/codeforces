
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define forii for(int i=1;i<=n;++i)
#define forji for(int j=1;j<=n;++j)
#define forij for(int i=1;i<=m;++i)
#define forjj for(int j=1;j<=m;++j)
ll cnt[500005],a[500005];
int32_t main()
{
    ll n,m,q;
    scanf("%lld%lld%lld",&n,&m,&q);
    forii
    {
        ll tmp;
        scanf("%lld",&tmp);
        a[i]=cnt[tmp]*m+tmp;
        cnt[tmp]++;
    }
    sort(a+1,a+1+n);
    forii a[i]-=i;
    while(q--)
    {
        ll t;
        scanf("%lld",&t);
        t-=n;
        if(t>a[n])
        {
            printf("%lld\n",(t+n-1)%m+1);
            continue;
        }
        ll p = upper_bound(a+1,a+1+n,t-1)-a-1;
        printf("%lld\n",(p+t-1)%m+1);
    }
}