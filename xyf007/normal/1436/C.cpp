#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
constexpr int MOD = 1e9 + 7;
int n, x, pos;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> x >> pos;
    int l = 0, r = n, ans = 1, cnt0 = 0, cnt1 = 0;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (pos >= mid)
        {
            if (mid != pos)
            {
                ans = ans * static_cast<long long>(x - 1 - cnt0) % MOD;
            }
            l = mid + 1;
            if (mid != pos)
            {
                cnt0++;
            }
        }
        else
        {
            ans = ans * static_cast<long long>(n - x - cnt1) % MOD;
            r = mid;
            cnt1++;
        }
    }
    for (int i = 1; i <= n - cnt0 - cnt1 - 1; i++)
    {
        ans = ans * static_cast<long long>(i) % MOD;
    }
    cout << ans;
    return 0;
}