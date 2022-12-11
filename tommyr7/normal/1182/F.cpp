#include <bits/stdc++.h>
using namespace std;
int T,a,b,p,q;
long long calc(long long n,long long a,long long b,long long c)
{
    if (a==0) return 1LL*(n+1)*(b/c);
    else if (b>=c)
    {
        long long res=1LL*(n+1)*(b/c);
        res+=calc(n,a,b%c,c);
        return res;
    } else if (a>=c)
    {
        long long res=(1LL*(n+1)*n*(a/c))/2;
        res+=calc(n,a%c,b,c);
        return res;
    } else
    {
        long long res=1LL*n*((1LL*a*n+b)/c);
        res-=calc((1LL*a*n+b)/c-1,c,c-b-1,a);
        return res;
    }
}
bool check(int now,int a,int b)
{
    if (now==q) return true;
    long long cnt=0LL;
    cnt+=calc(b,2*p,q+now,2*q)-calc(b,2*p,q-now-1,2*q);
    cnt-=calc(a-1,2*p,q+now,2*q)-calc(a-1,2*p,q-now-1,2*q);
    return cnt>0LL;
}
int main()
{
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d%d%d",&a,&b,&p,&q);
        int lx=0,rx=q;
        while (rx-lx>1)
        {
            int mid=(lx+rx)/2;
            if (check(mid,a,b)) rx=mid; else lx=mid;
        }
        int now;
        if (check(lx,a,b)) now=lx; else now=rx;
        lx=a,rx=b;
        while (rx-lx>1)
        {
            int mid=(lx+rx)/2;
            if (check(now,a,mid)) rx=mid; else lx=mid;
        }
        if (check(now,a,lx)) printf("%d\n",lx); else printf("%d\n",rx);
    }
    return 0;
}