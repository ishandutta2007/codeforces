#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <numeric>
int n, a[100001][2], b[200001], cnt[200001];
void checkmin(int &x, int y)
{
    if (x > y)
    {
        x = y;
    }
}
int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i][0] >> a[i][1];
        b[2 * i - 1] = a[i][0];
        b[2 * i] = a[i][1];
    }
    std::sort(b + 1, b + 2 * n + 1);
    int nn = std::unique(b + 1, b + 2 * n + 1) - b - 1;
    for (int i = 1; i <= n; i++)
    {
        cnt[a[i][0] = std::lower_bound(b + 1, b + nn + 1, a[i][0]) - b]++;
        cnt[a[i][1] = std::lower_bound(b + 1, b + nn + 1, a[i][1]) - b]++;
        if (a[i][0] == a[i][1])
        {
            cnt[a[i][0]]--;
        }
    }
    int max = *std::max_element(cnt + 1, cnt + nn + 1), ans = 0x7fffffff;
    if (max < (n + 1) / 2)
    {
        std::cout << -1;
        return 0;
    }
    for (int i = 1; i <= nn; i++)
    {
        if (cnt[i] < (n + 1) / 2)
        {
            continue;
        }
        int tmp = 0;
        for (int j = 1; j <= n; j++)
        {
            tmp += a[j][0] == i;
        }
        checkmin(ans, std::max(0, (n + 1) / 2 - tmp));
    }
    std::cout << ans;
    return 0;
}