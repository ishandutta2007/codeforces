#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <deque>
#include <numeric>
#define int long long
constexpr double kInf = 1e18;
int n, k;
long long a[200005], sum[200005];
double sumb[200005], sumc[200005], dp[200005][55];
auto f = [](const int &x, const int &y) -> double { return dp[x][y - 1] - sumc[x] + sum[x] * sumb[x]; };
auto slope = [](const int &x, const int &y, const int &j) -> double { return sum[x] == sum[y] ? f(x, j) > f(y, j) ? kInf : -kInf : (f(x, j) - f(y, j)) / static_cast<double>(sum[x] - sum[y]); };
signed main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }
    std::partial_sum(a + 1, a + n + 1, sum + 1);
    std::transform(a + 1, a + n + 1, sumb + 1, [](const int &x) -> double { return 1.0 / x; });
    std::partial_sum(sumb + 1, sumb + n + 1, sumb + 1);
    std::transform(sum + 1, sum + n + 1, a + 1, sumc + 1, [](const int &x, const int &y) -> double { return x / static_cast<double>(y); });
    std::partial_sum(sumc + 1, sumc + n + 1, sumc + 1);
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = kInf;
    }
    for (int i = 1; i <= k; i++)
    {
        std::deque<int> q;
        q.emplace_back(0);
        for (int j = 1; j <= n; j++)
        {
            while (q.size() > 1 && slope(q.at(1), q.front(), i) <= sumb[j])
            {
                q.pop_front();
            }
            dp[j][i] = dp[q.front()][i - 1] + sumc[j] - sumc[q.front()] - sum[q.front()] * (sumb[j] - sumb[q.front()]);
            while (q.size() > 1 && slope(j, q.at(q.size() - 2), i) <= slope(q.back(), q.at(q.size() - 2), i))
            {
                q.pop_back();
            }
            q.emplace_back(j);
        }
    }
    std::cout << std::setprecision(10) << std::fixed << dp[n][k];
    return 0;
}