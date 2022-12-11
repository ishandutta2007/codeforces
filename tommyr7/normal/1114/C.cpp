#include <bits/stdc++.h>
using namespace std;
long long n,x;
long long calc(long long n,long long x,long long d)
{
    int cnt=0;
    while (x%d==0)
    {
        ++cnt;
        x/=d;
    }
    long long res=0;
    while (n>0)
    {
        n/=d;
        res+=n;
    }
    return (res/cnt);
}
int main()
{
    scanf("%lld%lld",&n,&x);
    long long ans=2000000000000000000LL;
    long long now=x;
    for (long long i=2;1LL*i*i<=x;i++)
        if (now%i==0)
        {
            ans=min(ans,calc(n,x,i));
            while (now%i==0) now/=i;
        }
    if (now!=1) ans=min(ans,calc(n,x,now));
    printf("%lld\n",ans);
    return 0;
}