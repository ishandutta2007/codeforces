#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <numeric>
int n, nn, a[100001], t[100002];
long long k, sum[100001], b[100001], c[100001];
void Add(int x, int v = 1)
{
    x++;
    while (x <= nn + 1)
    {
        t[x] += v;
        x += x & -x;
    }
}
int Query(int x)
{
    x++;
    int s = 0;
    while (x)
    {
        s += t[x];
        x -= x & -x;
    }
    return s;
}
bool Check(long long x)
{
    std::memset(t, 0, sizeof(t));
    Add(c[0]);
    long long cnt = 0LL;
    for (int i = 1; i <= n; i++)
    {
        int p = std::upper_bound(b, b + nn, sum[i] - x) - b - 1;
        cnt += Query(p);
        Add(c[i]);
    }
    return cnt >= k;
}
int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    std::memcpy(b + 1, sum + 1, 8 * n);
    std::sort(b, b + n + 1);
    nn = std::unique(b, b + n + 1) - b;
    for (int i = 0; i <= n; i++)
    {
        c[i] = std::lower_bound(b, b + nn, sum[i]) - b;
    }
    long long l = -100000000000000LL, r = 100000000000000LL, best;
    while (l <= r)
    {
        long long mid = (l + r) >> 1;
        if (Check(mid))
        {
            best = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    std::cout << best;
    return 0;
}