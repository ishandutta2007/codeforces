#include <bits/stdc++.h>
using namespace std;
#define ll long long
int T;
ll a, b, c, d;
int main()
{
    scanf("%d", &T);
    for ( int i=1 ; i<=T ; i++)
    {
        scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
        ll tmp = ((a - 1ll) / b) / d + 1;
        if (a > b * c)
        {
            printf("-1\n");
            continue;
        }
        ll sum = tmp * a ;
        ll minuses = ((tmp - 1ll) * tmp / 2ll) * b * d ;
        printf("%lld\n", sum - minuses );
    }
    return 0;
}