#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
int t, n, q, a[100001];
long long sum[100001];
std::set<long long> s;
void Solve(int l, int r)
{
    if (l > r)
    {
        return;
    }
    if (a[l] == a[r])
    {
        s.emplace(a[l] * static_cast<long long>(r - l + 1));
        return;
    }
    int mid = (a[l] + a[r]) >> 1, pos = std::upper_bound(a + l, a + r + 1, mid) - a - 1;
    s.emplace(sum[pos] - sum[l - 1]);
    s.emplace(sum[r] - sum[pos]);
    Solve(l, pos);
    Solve(pos + 1, r);
}
int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> t;
    while (t--)
    {
        std::cin >> n >> q;
        for (int i = 1; i <= n; i++)
        {
            std::cin >> a[i];
        }
        std::sort(a + 1, a + n + 1);
        for (int i = 1; i <= n; i++)
        {
            sum[i] = sum[i - 1] + a[i];
        }
        s.clear();
        s.emplace(sum[n]);
        Solve(1, n);
        while (q--)
        {
            int x;
            std::cin >> x;
            if (s.count(x))
            {
                std::cout << "Yes\n";
            }
            else
            {
                std::cout << "No\n";
            }
        }
    }
    return 0;
}