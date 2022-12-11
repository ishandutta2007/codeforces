#pragma GCC target("popcnt")
#include <cctype>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <array>
#include <initializer_list>
#include <random>
#include <regex>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
using namespace std;

int a[100005];

deque<pair<int, int>> vt;

int main()
{
    int n, k, m;
    scanf("%d%d%d",&n,&k,&m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",&a[i]);
        if (vt.empty() || vt.back().first != a[i]) vt.emplace_back(a[i], 1);
        else
        {
            if (++vt.back().second == k) vt.pop_back();
        }
    }

    long long ans = 0;

    while (vt.size() >= 2 && vt[0].first == vt.back().first && vt[0].second + vt.back().second == k)
    {
        ans += k;
        vt.pop_front();
        vt.pop_back();
    }

    if (vt.empty()) ans = 0;
    else if (vt.size() == 1)
    {
        if (vt[0].second * 1ll * m % k == 0) ans = 0;
        else ans += vt[0].second * 1ll * m % k;
    }
    else if (vt.size() >= 2)
    {
        if (vt[0].first == vt.back().first)
        {
            ans += vt[0].second + vt.back().second + (vt[0].second + vt.back().second) % k * 1ll * (m - 1);
            vt.pop_front();
            vt.pop_back();
        }
        for (auto &e : vt) ans += e.second * 1ll * m;
    }

    printf("%lld\n", ans);
}