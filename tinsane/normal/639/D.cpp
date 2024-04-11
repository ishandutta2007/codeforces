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
const int N = 200500;
const ll INF = (ll)1e18;

int n, k;
ll b, c;
ll t[N];
vector<ll> by_mod[5];
int suf[5];
ll cur_ans;

int math_mod(ll x, int y)
{
    return (x % y + y) % y;
}

ll fix(ll x, int w)
{
    while (math_mod(x, 5) != w)
        x++;
    return x;
}

ll eval(ll x, ll y)
{
    ll cost = (y - x) / 5 * b;
    ll mx = math_mod(x, 5);
    ll my = math_mod(y, 5);
    if (mx <= my)
        cost += (my - mx) * c;
    else
        cost += (5 - mx + my) * c;
    return cost;
}

void take(ll num)
{
    ll best = INF;
    int best_who = -1;
    for (int i = 0; i < 5; i++)
    {
        if ((int)by_mod[i].size() == suf[i])
            continue;
        ll x = by_mod[i][(int)by_mod[i].size() - 1 - suf[i]];
        ll cost = eval(x, num);
        if (cost < best)
        {
            best = cost;
            best_who = i;
        }
    }
    assert(best_who != -1);
    cur_ans += best;
    suf[best_who]++;
}

ll solve(int w)
{
    for (int i = 0; i < 5; i++)
        by_mod[i].clear();
    fill(suf, suf + 5, 0);
    cur_ans = 0;

    for (int i = 0; i < n - 1; i++)
        by_mod[math_mod(t[i], 5)].push_back(t[i]);

    ll e = fix(t[n - 1], w);
    for (int i = 0; i < k - 1; i++)
        take(e);
    ll ans = cur_ans + (e - t[n - 1]) * c;
    ll prev_e = e;

    for (int i = n - 2; i >= k - 1; i--)
    {
        e = fix(t[i], w);
        cur_ans -= (prev_e - e) / 5 * b * (k - 1);

        int my_mod = math_mod(t[i], 5);
        if (suf[my_mod] > 0)
        {
            suf[my_mod]--;
            by_mod[my_mod].pop_back();
            take(e);
            cur_ans -= (e - t[i]) * c;
        }
        else
            by_mod[my_mod].pop_back();

        ans = min(ans, cur_ans + (e - t[i]) * c);
        prev_e = e;
    }

    return ans;
}

void solve()
{
    scanf("%d%d%lld%lld", &n, &k, &b, &c);
    b = min(b, 5 * c);
    for (int i = 0; i < n; i++)
        scanf("%lld", &t[i]);
    sort(t, t + n);

    ll res = INF;
    for (int w = 0; w < 5; w++)
        res = min(res, solve(w));

    printf("%lld\n", res);
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