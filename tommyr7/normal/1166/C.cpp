#include <bits/stdc++.h>
#define Maxn 200007
using namespace std;
int n,cnt=0;
int a[Maxn],b[Maxn];
int find1(int x)
{
    if (b[1]>x) return 0;
    int lx=1,rx=cnt;
    while (rx-lx>1)
    {
        int mid=(lx+rx)/2;
        if (b[mid]<=x) lx=mid; else rx=mid;
    }
    if (b[rx]<x) return rx; else return lx;
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if (a[i]>0) b[++cnt]=a[i];
        if (a[i]<0) b[++cnt]=-a[i];
    }
    long long ans=0LL;
    sort(b+1,b+cnt+1);
    for (int i=2;i<=cnt;i++)
        ans+=i-1-find1((b[i]-1)/2);
    printf("%lld\n",ans);
    return 0;
}