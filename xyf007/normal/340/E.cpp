#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
constexpr int kMod = 1e9 + 7;
int n, a[2001], fac[2001], inv[2001];
bool vis[2001];
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
    if (y < 0 || x < y)
    {
        return 0;
    }
    return static_cast<long long>(fac[x]) * inv[x - y] % kMod * inv[y] % kMod;
}
int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
        if (a[i] == i)
        {
            std::cout << 0;
            return 0;
        }
        if (a[i] != -1)
        {
            vis[a[i]] = true;
        }
    }
    int tot = std::count(a + 1, a + n + 1, -1), cnt = 0, ans = 1, f = 1;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i] && a[i] == -1)
        {
            cnt++;
        }
    }
    fac[0] = 1;
    for (int i = 1; i <= tot; i++)
    {
        ans = ans * static_cast<long long>(i) % kMod;
        fac[i] = ans;
    }
    inv[tot] = Ksm(fac[tot], kMod - 2);
    for (int i = tot - 1; i >= 0; i--)
    {
        inv[i] = inv[i + 1] * static_cast<long long>(i + 1) % kMod;
    }
    for (int i = 1; i <= cnt; i++)
    {
        f *= -1;
        ans = (ans + f * C(cnt, i) * fac[tot - i] % kMod + kMod) % kMod;
    }
    std::cout << ans;
    return 0;
}