#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <numeric>
constexpr int kMod = 1e9 + 7;
int t, fac[2601], inv[2601];
char s[101];
int Ksm(int a, int b)
{
    int s = 1;
    while (b)
    {
        if (b & 1)
        {
            s = s * static_cast<long long>(a) % kMod;
        }
        a = a * static_cast<long long>(a) % kMod;
        b >>= 1;
    }
    return s;
}
long long C(int x, int y)
{
    if (x < y || y < 0)
    {
        return 0LL;
    }
    return static_cast<long long>(fac[x]) * inv[x - y] % kMod * inv[y] % kMod;
}
int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    fac[0] = 1;
    for (int i = 1; i <= 2600; i++)
    {
        fac[i] = fac[i - 1] * static_cast<long long>(i) % kMod;
    }
    inv[2600] = Ksm(fac[2600], kMod - 2);
    for (int i = 2599; i >= 0; i--)
    {
        inv[i] = inv[i + 1] * static_cast<long long>(i + 1) % kMod;
    }
    std::cin >> t;
    while (t--)
    {
        std::cin >> (s + 1);
        std::size_t n = std::strlen(s + 1);
        int tot = 0, ans = 0, f = -1;
        for (size_t i = 1; i <= n; i++)
        {
            tot += s[i] - 'a' + 1;
        }
        for (size_t i = 0; i <= n; i++)
        {
            f *= -1;
            ans = (ans + f * C(n, i) * C(tot - 26 * i - 1, n - 1) % kMod + kMod) % kMod;
        }
        std::cout << (ans - 1 + kMod) % kMod << '\n';
    }
    return 0;
}