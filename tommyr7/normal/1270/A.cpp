#include <bits/stdc++.h>
#define Maxn 107
using namespace std;
int T,n,n1,n2;
int a[Maxn],b[Maxn];
void solve()
{
    scanf("%d%d%d",&n,&n1,&n2);
    bool flag=true;
    for (int i=1;i<=n1;i++)
        scanf("%d",&a[i]);
    for (int i=1;i<=n2;i++)
        scanf("%d",&b[i]);
    for (int i=1;i<=n2;i++)
        if (b[i]==n) flag=false;
    if (flag) printf("YES\n"); else printf("NO\n");
}
int main()
{
    scanf("%d",&T);
    while (T--) solve();
    return 0;
}