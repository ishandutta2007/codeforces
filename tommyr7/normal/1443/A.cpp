#include <bits/stdc++.h>
using namespace std;
#define Maxn 507
int T,n;
void solve()
{
    scanf("%d",&n);
    for (int i=2*n+2;i<=4*n;i+=2)
        printf("%d ",i);
    printf("\n");
}
int main()
{
    scanf("%d",&T);
    while (T--) solve();
    return 0;
}