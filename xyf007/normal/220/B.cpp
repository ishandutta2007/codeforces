#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <numeric>
#include <vector>
int n, m, a[100001], cnt[100001], id[100001], tot, sum[100001][501];
std::vector<int> v;
bool vis[100001];
int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
        if (a[i] <= n)
        {
            cnt[a[i]]++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (cnt[i] >= i)
        {
            v.emplace_back(i);
            vis[i] = true;
            id[i] = ++tot;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        std::memcpy(sum[i], sum[i - 1], sizeof(sum[i]));
        if (a[i] <= n && vis[a[i]])
        {
            sum[i][id[a[i]]]++;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        int l, r, ans = 0;
        std::cin >> l >> r;
        for (auto &&j : v)
        {
            ans += sum[r][id[j]] - sum[l - 1][id[j]] == j;
        }
        std::cout << ans << '\n';
    }
    return 0;
}