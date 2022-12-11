#include <bits/stdc++.h>
using namespace std;
#define Maxn 30007
int T,n;
int a[Maxn],x[Maxn],y[Maxn];
void solve()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    bool flag=true;
    x[1]=a[1],y[1]=0;
    for (int i=2;i<=n;i++)
    {
        x[i]=min(x[i-1],a[i]-y[i-1]);
        y[i]=a[i]-x[i];
        if (x[i]<0||y[i]<0) flag=false;
    }
    if (flag) printf("YES\n"); else printf("NO\n");
}
int main()
{
    scanf("%d",&T);
    while (T--) solve();
    return 0;
}