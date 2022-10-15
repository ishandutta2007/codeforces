#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
int t, n, m, a[100001];
std::pair<int, double> b[100005];
int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> t;
    while (t--)
    {
        std::cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            std::cin >> a[i];
        }
        for (int i = 1; i <= m; i++)
        {
            std::cin >> b[i].first >> b[i].second;
        }
        b[++m] = {0, 0.0};
        std::sort(b + 1, b + m + 1);
        int now = n;
        double ans = 0.0, nowp = 1.0;
        bool f = true;
        for (int i = m; i >= 1; i--)
        {
            while (now > b[i].first)
            {
                if (a[now] != now)
                {
                    f = false;
                    break;
                }
                now--;
            }
            if (!f)
            {
                break;
            }
            ans += nowp * b[i].second;
            nowp *= (1 - b[i].second);
        }
        if (f)
        {
            ans += nowp;
        }
        std::cout << std::setprecision(8) << std::fixed << ans << '\n';
    }
    return 0;
}