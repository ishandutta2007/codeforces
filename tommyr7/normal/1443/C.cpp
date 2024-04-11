#include <bits/stdc++.h>
using namespace std;
#define Maxn 200007
int T,n;
int a[Maxn],b[Maxn];
bool check(int x)
{
    long long ans=0LL;
    for (int i=1;i<=n;i++)
        if (a[i]>x) ans+=b[i];
    return (ans<=x);
}
void solve()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for (int i=1;i<=n;i++)
        scanf("%d",&b[i]);
    int lx=0,rx=1000000000;
    while (rx-lx>1)
    {
        int mid=(lx+rx)/2;
        if (check(mid)) rx=mid; else lx=mid;
    }
    if (check(lx)) printf("%d\n",lx); else printf("%d\n",rx);
}
int main()
{
    scanf("%d",&T);
    while (T--) solve();
    return 0;
}