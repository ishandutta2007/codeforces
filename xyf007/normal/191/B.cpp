#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <numeric>
int n, k, a[100001], c[100001];
long long b;
int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> n >> k >> b;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }
    std::memcpy(c + 1, a + 1, 4 * n - 4);
    std::sort(c + 1, c + n, std::greater<int>());
    long long maxk = std::accumulate(c + 1, c + k, 0LL);
    for (int i = 1; i < n; i++)
    {
        int l = 1, r = n, best = -1;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (c[mid] >= a[i])
            {
                best = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        long long s = best < k ? maxk + c[k] - a[i] : maxk;
        if (s + a[i] > b)
        {
            std::cout << i;
            return 0;
        }
    }
    std::cout << n;
    return 0;
}