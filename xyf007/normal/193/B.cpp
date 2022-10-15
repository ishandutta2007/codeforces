#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <numeric>
int n, m, r;
long long a[31], b[31], k[31], p[31], ans = -1e18;
void checkmax(long long &x, long long y)
{
    if (x < y)
    {
        x = y;
    }
}
void Dfs(int d, int op)
{
    if (d > m)
    {
        return;
    }
    if (d % 2 == m % 2)
    {
        checkmax(ans, std::inner_product(a + 1, a + n + 1, k + 1, 0LL));
    }
    long long tmp[31];
    std::memcpy(tmp + 1, a + 1, 8 * n);
    if (op == 2)
    {
        std::transform(a + 1, a + n + 1, b + 1, a + 1, [](const long long &x, const long long &y) -> long long { return x ^ y; });
        Dfs(d + 1, 1);
        std::memcpy(a + 1, tmp + 1, 8 * n);
    }
    for (int i = 1; i <= n; i++)
    {
        a[i] = tmp[p[i]] + r;
    }
    Dfs(d + 1, 2);
    std::memcpy(a + 1, tmp + 1, 8 * n);
}
int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> n >> m >> r;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        std::cin >> b[i];
    }
    for (int i = 1; i <= n; i++)
    {
        std::cin >> k[i];
    }
    for (int i = 1; i <= n; i++)
    {
        std::cin >> p[i];
    }
    Dfs(0, 2);
    std::cout << ans;
    return 0;
}