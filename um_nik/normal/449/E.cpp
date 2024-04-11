#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

const ll MOD = (ll)(1e9 + 7);
ll a[1000100];
ll phi[1000100];
ll gcd_sum[1000100];
int p[1000100];
ll sum1[1000100], sum2[1000100];
ll ans;
int t;
ll sum3[1000100], sum4[1000100];

int main()
{
    for (int i = 1; i < 1000100; i++)
        p[i] = -1;
    for (int i = 2; i < 1000100; i++)
    {
        if (p[i] != -1)
            continue;
        for (int j = 2 * i; j < 1000100; j += i)
        {
            if (p[j] == -1)
                p[j] = i;
        }
    }
    for (int x = 2; x < 1000100; x++)
    {
        if (p[x] == -1)
        {
            phi[x] = x - 1;
            continue;
        }
        phi[x] = x;
        int y = x;
        while (p[y] != -1)
        {
            int d = p[y];
            phi[x] = phi[x] / d * (d - 1);
            while (y % d == 0)
                y /= d;
        }
        if (y != 1)
            phi[x] = phi[x] / y * (y - 1);
    }
    for (int x = 2; x < 1000100; x++)
    {
        gcd_sum[x] = phi[x];
        for (int i = 2; i <= (int)(sqrt(x + .5)); i++)
            if (x % i == 0)
                gcd_sum[x] = (gcd_sum[x] + (ll)i * phi[x / i] + (ll)(x / i) * phi[i]) % MOD;
        int y = (int)sqrt(x + .5);
        if (y * y == x)
            gcd_sum[x] = (gcd_sum[x] - (ll)y * phi[y] + MOD) % MOD;
    }
    for (ll x = 1; x < 1000100; x++)
    {
        a[x] = x * x * x;
        a[x] -= 2LL * ( x * (x - 1) + ((x - 1) * x * (x + 1)) / 6LL - gcd_sum[x] );
        a[x] %= MOD;
    }
    for (int i = 1; i < 1000100; i++)
    {
        sum1[i] = (sum1[i - 1] + a[i]) % MOD;
        sum2[i] = (sum2[i - 1] + sum1[i]) % MOD;
    }
    for (int i = 1; i < 1000100; i++)
        sum4[i] = (sum4[i - 1] + sum1[i - 1] + sum1[i]) % MOD;
    for (int i = 1; i < 1000100; i++)
        sum3[i] = (sum3[i - 1] + sum4[i]) % MOD;
    scanf("%d", &t);
    while (t--)
    {
        int m, n;
        scanf("%d%d", &m, &n);
        if (m > n)
            swap(m, n);
        printf("%I64d\n", ( sum3[m] + sum2[m] * (ll)(n - m) ) % MOD);
    }

    return 0;
}