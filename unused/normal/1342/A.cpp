#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int x, y, a, b;
        scanf("%d%d%d%d",&x,&y,&a,&b);
        printf("%lld\n", min(abs(x-y)*1ll*a + min(abs(x),abs(y))*1ll*b,
            (abs(x)+abs(y))*1ll*a));
    }
}