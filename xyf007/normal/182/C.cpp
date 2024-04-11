#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <numeric>
#include <set>
int n, len, k, a[100001];
long long sum[100001];
void checkmax(long long &x, long long y)
{
    if (x < y)
    {
        x = y;
    }
}
int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    clock_t st = clock();
    std::cin >> n >> len;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    std::cin >> k;
    long long ans = 0LL, tot = 0LL;
    if (!k)
    {
        for (int i = len; i <= n; i++)
        {
            checkmax(ans, std::abs(sum[i] - sum[i - len]));
        }
        std::cout << ans;
        return 0;
    }
    std::multiset<int> s, s2;
    for (int i = 1; i <= len; i++)
    {
        if (a[i] < 0)
        {
            if ((int)s.size() < k)
            {
                s.emplace(a[i]);
                tot += a[i];
            }
            else if (a[i] < *s.rbegin())
            {
                tot += a[i] - *s.rbegin();
                s2.emplace(*s.rbegin());
                s.erase(--s.end());
                s.emplace(a[i]);
            }
            else
            {
                s2.emplace(a[i]);
            }
        }
    }
    for (int i = len; i <= n; i++)
    {
        checkmax(ans, std::abs(sum[i] - sum[i - len] - 2 * tot));
        if (auto it = s.find(a[i - len + 1]); it != s.end())
        {
            tot -= a[i - len + 1];
            s.erase(it);
            if (!s2.empty())
            {
                tot += *s2.begin();
                s.emplace(*s2.begin());
                s2.erase(s2.begin());
            }
        }
        else if (auto it = s2.find(a[i - len + 1]); it != s2.end())
        {
            s2.erase(it);
        }
        if (i < n && a[i + 1] < 0)
        {
            if ((int)s.size() < k)
            {
                s.emplace(a[i + 1]);
                tot += a[i + 1];
            }
            else if (a[i + 1] < *s.rbegin())
            {
                tot += a[i + 1] - *s.rbegin();
                s2.emplace(*s.rbegin());
                s.erase(--s.end());
                s.emplace(a[i + 1]);
            }
            else
            {
                s2.emplace(a[i + 1]);
            }
        }
    }
    s.clear();
    s2.clear();
    tot = 0LL;
    for (int i = 1; i <= len; i++)
    {
        if (a[i] > 0)
        {
            if ((int)s.size() < k)
            {
                s.emplace(a[i]);
                tot += a[i];
            }
            else if (a[i] > *s.begin())
            {
                tot += a[i] - *s.begin();
                s2.emplace(*s.begin());
                s.erase(s.begin());
                s.emplace(a[i]);
            }
            else
            {
                s2.emplace(a[i]);
            }
        }
    }
    for (int i = len; i <= n; i++)
    {
        checkmax(ans, std::abs(sum[i] - sum[i - len] - 2 * tot));
        if (auto it = s.find(a[i - len + 1]); it != s.end())
        {
            tot -= a[i - len + 1];
            s.erase(it);
            if (!s2.empty())
            {
                tot += *s2.rbegin();
                s.emplace(*s2.rbegin());
                s2.erase(--s2.end());
            }
        }
        else if (auto it = s2.find(a[i - len + 1]); it != s2.end())
        {
            s2.erase(it);
        }
        if (i < n && a[i + 1] > 0)
        {
            if ((int)s.size() < k)
            {
                s.emplace(a[i + 1]);
                tot += a[i + 1];
            }
            else if (a[i + 1] > *s.begin())
            {
                tot += a[i + 1] - *s.begin();
                s2.emplace(*s.begin());
                s.erase(s.begin());
                s.emplace(a[i + 1]);
            }
            else
            {
                s2.emplace(a[i + 1]);
            }
        }
    }
    std::cout << ans;
    return 0;
}