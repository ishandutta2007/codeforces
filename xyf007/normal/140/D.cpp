#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <numeric>
int n, a[101];
int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }
    std::sort(a + 1, a + n + 1);
    int ans = 0, sum = 10, tot = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += a[i];
        if (sum > 720)
        {
            break;
        }
        ans++;
        tot += std::max(sum - 360, 0);
    }
    std::cout << ans << ' ' << tot;
    return 0;
}