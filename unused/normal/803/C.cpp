#include <bits/stdc++.h>
using namespace std;

long long n, k;

bool check(long long g)
{
    if (n * 2 / k / (k + 1) < g) return false;

    for (int i = 1; i < k; i++)
    {
        printf("%lld ", g * i);
        n -= g * i;
    }
    printf("%lld\n", n);
    return true;
}

int main()
{
    cin >> n >> k;

    for (int i = 1; i * 1ll * i <= n; i++)
    {
        if (n % i) continue;
        if (check(n / i)) return 0;
    }

    for (int i = sqrt(n) + 1; i >= 1; i--)
    {
        if (n % i) continue;
        if (check(i)) return 0;
    }

    printf("-1\n");
}