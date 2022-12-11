#include <bits/stdc++.h>
#define modp 1000000007
int x;
long long n;
int power(int a,int b)
{
    int res=1,now=a,left=b;
    while (left>0)
    {
        if (left%2==1) res=(1LL*res*now)%modp;
        left/=2;
        now=(1LL*now*now)%modp;
    }
    return res;
}
int calc(int p)
{
    long long now=0;
    long long tmp=n;
    while (tmp>0)
    {
        tmp/=p;
        now+=tmp;
    }
    now%=(modp-1);
    return power(p,(int)now);
}
int main()
{
    scanf("%d%lld",&x,&n);
    int ans=1;
    for (int i=2;1LL*i*i<=x;i++)
        if (x%i==0)
        {
            while (x%i==0) x/=i;
            ans=(1LL*ans*calc(i))%modp;
        }
    if (x!=1) ans=(1LL*ans*calc(x))%modp;
    printf("%d\n",ans);
    return 0;
}