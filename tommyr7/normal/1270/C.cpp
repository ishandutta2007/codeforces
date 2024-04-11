#include <bits/stdc++.h>
using namespace std;
#define Maxn 100007
int T,n,a[Maxn];
void solve()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    long long x,y;
    x=0LL;
    for (int i=1;i<=n;i++)
        x^=a[i];
    y=x;
    for (int i=1;i<=n;i++)
        y+=a[i];
    printf("%d\n",2);
    printf("%lld %lld\n",x,y);
}
int main()
{
    scanf("%d",&T);
    while (T--) solve();
    return 0;
}