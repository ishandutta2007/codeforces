#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstring>
#include <numeric>
constexpr int kMod = 1e9 + 7;
int n, k, a[2001], inv[2001], c[2001], ans[2001];
int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> n >> k;
    inv[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        inv[i] = static_cast<long long>(kMod - kMod / i) * inv[kMod % i] % kMod;
    }
    c[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        c[i] = c[i - 1] * static_cast<long long>(k - 1 + i) % kMod * inv[i] % kMod;
    }
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            ans[j] = (ans[j] + static_cast<long long>(c[j - i]) * a[i]) % kMod;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        std::cout << ans[i] << ' ';
    }
    return 0;
}