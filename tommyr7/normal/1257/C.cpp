#include <bits/stdc++.h>
using namespace std;
#define Maxn 200007
int T,n;
int a[Maxn],vis[Maxn];
void solve()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for (int i=1;i<=n;i++)
        vis[i]=0;
    int ans=n+1;
    int pos=1;
    int cnt=0;
    for (int i=1;i<=n;i++)
    {
        while (pos<=n&&cnt==0)
        {
            vis[a[pos]]++;
            if (vis[a[pos]]==2) ++cnt;
            ++pos;
        }
        if (cnt==0) break;
        ans=min(ans,pos-i);
        --vis[a[i]];
        if (vis[a[i]]==1) --cnt;
    }
    if (ans>n) printf("%d\n",-1); else printf("%d\n",ans);
}
int main()
{
    scanf("%d",&T);
    while (T--) solve();
    return 0;
}