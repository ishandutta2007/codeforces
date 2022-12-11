#include <bits/stdc++.h>
using namespace std;
int n,m,a,b,t;
void solve()
{
    scanf("%d%d%d%d",&n,&m,&a,&b);
    int ans=abs(a-b);
    ans=min(ans+m,n-1);
    printf("%d\n",ans);
}
int main()
{
    scanf("%d",&t);
    while (t--) solve();
    return 0;
}