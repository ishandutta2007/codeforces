#include <bits/stdc++.h>
#define Maxn 100007
using namespace std;
int n;
long long s[Maxn],sum[Maxn];
int q;
int calc(long long x)
{
    if (x<s[1]) return 0;
    if (x>=s[n]) return n;
    int lx=1,rx=n;
    while (rx-lx>1)
    {
        int mid=(lx+rx)/2;
        if (s[mid]<=x) lx=mid; else rx=mid;
    }
    if (s[rx]<=x) return rx; else return lx;
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%lld",&s[i]);
    sort(s+1,s+n+1);
    for (int i=1;i<n;i++)
        s[i]=s[i+1]-s[i];
    s[n]=1000000000000000007LL;
    sort(s+1,s+n+1);
    sum[0]=0LL;
    for (int i=1;i<=n;i++)
        sum[i]=sum[i-1]+s[i];
    scanf("%d",&q);
    while (q--)
    {
        long long lx,rx;
        scanf("%lld%lld",&lx,&rx);
        long long x=rx-lx+1;
        int tmp=calc(x);
        long long ans=sum[tmp]+1LL*x*(n-tmp);
        printf("%lld\n",ans);
    }
    return 0;
}