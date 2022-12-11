#include <bits/stdc++.h>
#define Maxn 200007
using namespace std;
int T,n,a[Maxn];
void solve()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int ans=0;
    for (int i=1;i<n;i++)
    {
        if (abs(a[i]-a[i+1])>=2) ans=i;
    }
    if (ans==0) printf("NO\n");
    else
    {
        printf("YES\n");
        printf("%d %d\n",ans,ans+1);
    }
}
int main()
{
    scanf("%d",&T);
    while (T--) solve();
    return 0;
}