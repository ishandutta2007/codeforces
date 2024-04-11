#include <bits/stdc++.h>
using namespace std;
#define Maxn 200007
int n,k,m;
int a[Maxn];
bool check(long long x)
{
    long long tmp=0LL;
    for (int i=1;i<=m;i++)
        if (a[i]<x) tmp+=x-a[i];
    return (tmp<=k);
}
int main()
{
    scanf("%d%d",&n,&k);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    m=(n+1)/2;
    for (int i=1;i<=m;i++)
        a[i]=a[i+m-1];
    long long lx=1LL*a[1],rx=2000000000LL;
    while (rx-lx>1)
    {
        long long mid=(lx+rx)/2;
        if (check(mid)) lx=mid; else rx=mid;
    }
    if (check(rx)) printf("%lld\n",rx); else printf("%lld\n",lx);
}