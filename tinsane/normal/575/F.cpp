#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <cassert>
using namespace std;

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 0
#endif

typedef long long ll;

const ll LINF = 1.5e18;
const int N = 5e3 + 10;
int n;
int x;
int l[N], r[N];
int list[2 * N];
int sz;
ll dp[2 * N], dp_new[2 * N];

void solve()
{
    scanf("%d%d", &n, &x);
    list[sz++] = x;
    for(int i = 0; i < n; ++i)
    {
        scanf("%d%d", &l[i], &r[i]);
        list[sz++] = l[i];
        list[sz++] = r[i];
    }
    sort(list, list + sz);
    sz = unique(list, list + sz) - list;
    fill(dp, dp + sz, LINF);
    dp[lower_bound(list, list + sz, x) - list] = 0;
    for(int i = 0; i < n; ++i)
    {
        fill(dp_new, dp_new + sz, LINF);
        ll cur_min = LINF;
        for(int j = sz - 1; j >= 0; --j)
        {
            if (j + 1 < sz)
                cur_min += list[j + 1] - list[j];
            cur_min = min(cur_min, dp[j]);
            dp_new[j] = min(dp_new[j], cur_min);
        }
        cur_min = LINF;
        for(int j = 0; j < sz; ++j)
        {
            if (j > 0)
                cur_min += list[j] - list[j - 1];
            cur_min = min(cur_min, dp[j]);
            dp_new[j] = min(dp_new[j], cur_min);
        }
        for(int j = 0; j < sz; ++j)
            if (l[i] > list[j] || r[i] < list[j])
                dp_new[j] += min(abs(l[i] - list[j]), abs(r[i] - list[j]));
        copy(dp_new, dp_new + sz, dp);
    }
    printf("%lld", *min_element(dp, dp + sz));
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    solve();

    eprintf("time = %.3lf\n", (double)clock() / CLOCKS_PER_SEC);

    return 0;
}