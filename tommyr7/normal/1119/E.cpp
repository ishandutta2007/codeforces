#include <bits/stdc++.h>
#define Maxn 300007
using namespace std;
int n;
long long a[Maxn];
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    long long ans=0LL,tmp=0LL;
    for (int i=1;i<=n;i++)
    {
        long long now=min((long long)a[i]/2,tmp);
        ans+=now;
        tmp-=now;
        a[i]-=2LL*now;
        if (a[i]>=3)
        {
            tmp+=a[i]%3;
            ans+=a[i]/3;
        } else tmp+=a[i];
    }
    printf("%lld\n",ans);
    return 0;
}