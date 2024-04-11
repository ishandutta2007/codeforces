#include <bits/stdc++.h>
using namespace std;

using matrix = array<array<int, 100>, 100>;
long long a[105];
constexpr int MOD = 1000000007;

matrix now;

matrix matmul(const matrix &m1, const matrix &m2)
{
    matrix ret{};
    for (int k = 0; k < 100; k++)
    {
        for (int i = 0; i < 100; i++)
        {
            for (int j = 0; j < 100; j++)
            {
                ret[i][j] = (ret[i][j] + m1[i][k] * 1ll * m2[k][j]) % MOD;
            }
        }
    }
    return ret;
}

int main()
{
    int n; long long k;
    scanf("%d%lld",&n,&k);
    for (int i = 0; i < n; i++) scanf("%lld",&a[i]);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (__builtin_popcountll(a[i] ^ a[j]) % 3 == 0) now[i][j] = 1;
        }
    }
    --k;

    matrix z{};
    for (int i = 0; i < n; i++) z[i][i] = 1;

    for (long long flag = 1; flag <= k; flag <<= 1)
    {
        if (k & flag) z = matmul(z, now);
        now = matmul(now, now);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) ans = (ans + z[i][j]) % MOD;
    printf("%d\n", ans);
}