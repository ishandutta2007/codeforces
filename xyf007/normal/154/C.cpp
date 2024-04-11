#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <numeric>
constexpr int kBase = 41;
constexpr long long kMod = 100000000000031LL;
int n, m;
long long f[1000001], a[1000001];
std::pair<int, int> e[1000001];
int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> n >> m;
    f[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        f[i] = f[i - 1] * kBase % kMod;
    }
    for (int i = 1; i <= m; i++)
    {
        std::cin >> e[i].first >> e[i].second;
        a[e[i].first] = (a[e[i].first] + f[e[i].second]) % kMod;
        a[e[i].second] = (a[e[i].second] + f[e[i].first]) % kMod;
    }
    long long ans = 0;
    for (int i = 1; i <= m; i++)
    {
        ans += (a[e[i].first] + f[e[i].first]) % kMod == (a[e[i].second] + f[e[i].second]) % kMod;
    }
    std::sort(a + 1, a + n + 1);
    int cnt = 1;
    for (int i = 2; i <= n; i++)
    {
        if (a[i] == a[i - 1])
        {
            cnt++;
        }
        else
        {
            ans += cnt * static_cast<long long>(cnt - 1) / 2;
            cnt = 1;
        }
    }
    std::cout << ans + cnt * static_cast<long long>(cnt - 1) / 2;
    return 0;
}