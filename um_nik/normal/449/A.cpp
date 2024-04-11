#include <iostream>
using namespace std;

typedef long long ll;

ll n, m, k;
ll ans = 1LL;

int main()
{
    scanf("%I64d%I64d%I64d", &n, &m, &k);
    if (k > n + m - 2)
    {
        printf("-1\n");
        return 0;
    }

    if (k < (ll)(3e6))
    {
        for (ll i = 0; i <= k; i++)
            ans = max(ans, (n / (i + 1LL)) * (m / (k - i + 1LL)));
        printf("%I64d\n", ans);
        return 0;
    }

    for (ll i = 1; i <= 1000LL; i++)
    {
        if (i > n)
            break;
        ll p = n / i - 1LL;
        ans = max(ans, i * (m / max(1LL, (k - p + 1LL) ) ));
    }
    for (ll i = 1; i <= 1000LL; i++)
    {
        if (i > m)
            break;
        ll p = m / i - 1LL;
        ans = max(ans, i * (n / max(1LL, (k - p + 1LL) ) ));
    }
    printf("%I64d\n", ans);
    return 0;
}