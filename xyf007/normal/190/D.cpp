#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
int n, k, a[400001], b[400001], cnt[400001];
int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }
    std::memcpy(b + 1, a + 1, 4 * n);
    std::sort(b + 1, b + n + 1);
    int nn = std::unique(b + 1, b + n + 1) - b - 1;
    for (int i = 1; i <= n; i++)
    {
        a[i] = std::lower_bound(b + 1, b + nn + 1, a[i]) - b;
    }
    int l = 1, r = 0, maxp = -1, maxv = 0;
    long long ans = 0LL;
    while (r < n)
    {
        while (r < n && maxv < k)
        {
            if (++cnt[a[++r]] > maxv)
            {
                maxv = cnt[a[r]];
                maxp = a[r];
            }
        }
        if (maxv < k)
        {
            break;
        }
        while (l <= r && maxv >= k)
        {
            ans += n - r + 1;
            cnt[a[l]]--;
            if (a[l++] == maxp)
            {
                maxv--;
            }
        }
    }
    std::cout << ans;
    return 0;
}