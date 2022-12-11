#include <bits/stdc++.h>
using namespace std;
int T;
long long a,b;
int main()
{
    scanf("%d",&T);
    while (T--)
    {
        scanf("%lld%lld",&a,&b);
        if (a-b==1LL) printf("NO\n"); else printf("YES\n");
    }
    return 0;
}