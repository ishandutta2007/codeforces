#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    scanf("%lld",&n);
    long long f = n;
    for (int i = 2; i * 1ll * i <= n; i++)
    {
        if (n % i == 0) { f = gcd(f, i);
            f = gcd(f, n / i);
        }
    }

    printf("%lld\n", f);
}