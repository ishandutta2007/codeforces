#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <numeric>
using namespace std;
constexpr int MOD = 998244353;
int n, a[300001];
long long ksm(long long a, int b)
{
    long long s = 1;
    while (b)
    {
        if (b & 1)
        {
            s = s * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return s;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= 2 * n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + 2 * n + 1);
    long long sum = (accumulate(a + n + 1, a + 2 * n + 1, 0LL) - accumulate(a + 1, a + n + 1, 0LL)) % MOD, ss = 1, inv = 1;
    for (int i = 1; i <= 2 * n; i++)
    {
        ss = ss * i % MOD;
    }
    for (int i = 1; i <= n; i++)
    {
        inv = inv * i % MOD;
    }
    inv = ksm(inv, MOD - 2);
    cout << sum * ss % MOD * inv % MOD * inv % MOD;
    return 0;
}