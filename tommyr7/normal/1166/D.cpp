#include <bits/stdc++.h>
using namespace std;
int T;
long long a,b,m;
void work()
{
    scanf("%lld%lld%lld",&a,&b,&m);
    if (a==b)
    {
        printf("%d %lld\n",1,a);
        return;
    }
    if (a+m>=b&&b>=a)
    {
        printf("%d %lld %lld\n",2,a,b);
        return;
    }
    long long now=1LL;
    int ans=0;
    for (int i=2;i<=50;i++)
    {
        if (b/now>=a+1&&(b+now-1)/now<=a+m)
        {
            ans=i;
            break;
        }
        now=2LL*now;
    }
    if (ans==0) printf("%d\n",-1); else
    {
        printf("%d ",ans);
        long long cnt=b/now-a;
        long long r=b-1LL*(cnt+a)*now;
        long long sum=a;
        printf("%lld ",a);
        now/=2;
        for (int i=1;i<ans;i++)
        {
            long long x=sum+cnt;
            if (r>=now&&r!=0)
            {
                ++x;
                r-=now;
            }
            printf("%lld ",x);
            sum+=x;
            now/=2;
        }
        printf("\n");
    }
}
int main()
{
    scanf("%d",&T);
    while (T--) work();
    return 0;
}