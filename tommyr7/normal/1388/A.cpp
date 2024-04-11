#include <bits/stdc++.h>
using namespace std;
int T,n;
void solve()
{
    scanf("%d",&n);
    if (n<31) printf("NO\n");
    else
    {
        printf("YES\n");
        int x=n-6-10-14;
        if (x!=6&&x!=10&&x!=14) printf("%d %d %d %d\n",6,10,14,x); else printf("%d %d %d %d\n",6,10,15,x-1);
    }
}
int main()
{
    scanf("%d",&T);
    while (T--) solve();
    return 0;
}