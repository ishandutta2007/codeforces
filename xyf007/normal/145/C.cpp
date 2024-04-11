#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <numeric>
#include <unordered_map>
constexpr int kMod = 1e9 + 7;
int n, k, a[100001], fac[100001], inv[100001], dp[1024][1024], b[1024];
std::unordered_map<int, int> mp;
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
bool Check(int x)
{
    bool ok = true;
    while (x)
    {
        ok &= x % 10 == 4 || x % 10 == 7;
        x /= 10;
    }
    return ok;
}
int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> n >> k;
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        fac[i] = fac[i - 1] * static_cast<long long>(i) % kMod;
    }
    inv[n] = Ksm(fac[n], kMod - 2);
    for (int i = n - 1; i >= 0; i--)
    {
        inv[i] = inv[i + 1] * static_cast<long long>(i + 1) % kMod;
    }
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
        if (Check(a[i]))
        {
            mp[a[i]]++;
        }
    }
    int cnt = 0, tot = 0;
    for (auto &&i : mp)
    {
        b[++cnt] = i.second;
        tot += i.second;
    }
    dp[0][0] = 1;
    for (int i = 1; i <= cnt; i++)
    {
        dp[i][0] = 1;
        for (int j = 1; j <= i; j++)
        {
            dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1] * static_cast<long long>(b[i]) % kMod) % kMod;
        }
    }
    int ans = 0;
    for (int i = 0; i <= k && i <= cnt; i++)
    {
        ans = (ans + dp[cnt][i] * C(n - tot, k - i) % kMod) % kMod;
    }
    std::cout << ans;
    return 0;
}