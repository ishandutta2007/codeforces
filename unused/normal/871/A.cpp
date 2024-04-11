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

int a[1000005];

int main()
{
    cin.sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];

        if (a[i] == 1 || a[i] == 2 || a[i] == 3 || a[i] == 5 || a[i] == 7 || a[i] == 11)
        {
            cout << -1 << '\n';
            continue;
        }

        int ans1 = a[i] / 4;
        int rem = a[i] - ans1 * 4;
        if (rem == 2) cout << ans1 << '\n';
        else if (rem == 1) cout << ans1 - 1 << '\n';
        else if (rem == 3) cout << ans1 - 1 << '\n';
        else cout << ans1 << '\n';
    }
}