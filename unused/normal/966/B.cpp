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

pair<int, int> c[300005];

int main()
{
    int n, x1, x2;
    cin.sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n >> x1 >> x2;

    for (int i = 0; i < n; i++) cin >> c[i].first;
    for (int i = 0; i < n; i++) c[i].second = i;
    sort(c, c + n);

    for (int i = 0; i < n; i++)
    {
        int need = (x1 + c[i].first - 1) / c[i].first;
        
        if (i + need >= n) continue;

        int need2 = (x2 + c[i + need].first - 1) / c[i + need].first;

        if (i + need + need2 <= n)
        {
            vector<int> ans1, ans2;
            for (int j = 0; j < need; j++) ans1.push_back(c[i + j].second + 1);
            for (int j = 0; j < need2; j++) ans2.push_back(c[i + need + j].second + 1);
            sort(ans1.begin(), ans1.end());
            sort(ans2.begin(), ans2.end());

            printf("Yes\n%d %d\n", need, need2);
            for (int t : ans1) printf("%d ", t);
            printf("\n");
            for (int t : ans2) printf("%d ", t);
            printf("\n");
            return 0;
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        int need = (x2 + c[i].first - 1) / c[i].first;
        
        if (i + need >= n) continue;

        int need2 = (x1 + c[i + need].first - 1) / c[i + need].first;

        if (i + need + need2 <= n)
        {
            vector<int> ans1, ans2;
            for (int j = 0; j < need; j++) ans2.push_back(c[i + j].second + 1);
            for (int j = 0; j < need2; j++) ans1.push_back(c[i + need + j].second + 1);
            sort(ans1.begin(), ans1.end());
            sort(ans2.begin(), ans2.end());

            printf("Yes\n%d %d\n", need2, need);
            for (int t : ans1) printf("%d ", t);
            printf("\n");
            for (int t : ans2) printf("%d ", t);
            printf("\n");
            return 0;
        }
    }

    puts("No");
}