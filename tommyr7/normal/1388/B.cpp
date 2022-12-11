#include <bits/stdc++.h>
using namespace std;
int T,n;
void solve()
{
    scanf("%d",&n);
    int t=(n+3)/4;
    for (int i=1;i<=n-t;i++)
        printf("%d",9);
    for (int i=1;i<=t;i++)
        printf("%d",8);
    printf("\n");
}
int main()
{
    scanf("%d",&T);
    while (T--) solve();
    return 0;
}