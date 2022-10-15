#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <numeric>
#include <unordered_map>
int k, b, n, a[100001];
std::unordered_map<int, int> mp;
int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> k >> b >> n;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }
    int cnt = 0;
    long long ans0 = 0LL, ans = 0LL, sum = 0LL;
    mp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        if (a[i])
        {
            cnt = 0;
        }
        else
        {
            cnt++;
        }
        ans0 += cnt;
        sum += a[i];
        ans += mp[(sum - b + k - 1) % (k - 1)];
        mp[sum % (k - 1)]++;
    }
    if (!b)
    {
        std::cout << ans0;
    }
    else if (b == k - 1)
    {
        std::cout << ans - ans0;
    }
    else
    {
        std::cout << ans;
    }
    return 0;
}