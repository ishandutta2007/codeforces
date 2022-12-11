#include <bits/stdc++.h>
using namespace std;
#define Maxn 107
int T,n,u,v;
int a[Maxn];
void solve()
{
    scanf("%d%d%d",&n,&u,&v);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int mx=0;
    for (int i=1;i<n;i++)
        mx=max(mx,abs(a[i]-a[i+1]));
    if (mx>1) printf("%d\n",0);
    else if (mx==1) printf("%d\n",min(u,v));
    else printf("%d\n",min(v+v,u+v));
}
int main()
{
    scanf("%d",&T);
    while (T--) solve();
    return 0;
}