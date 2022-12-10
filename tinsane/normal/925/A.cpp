#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define dbg(...) fprintf(stderr, __VA_ARGS__)
#define dbgv(x) cerr << #x << " = " << x << endl
#define dbga(arr, len) {cerr << #arr << " = "; for (int _ = 0; _ < len; _++)\
cerr << arr[_] << " "; cerr << endl;}
#define dbgi(it) {cerr << #it << " = "; for (const auto& _ : it)\
cerr << _ << " "; cerr << endl;}
#else
#define dbg(...) (void)0
#define dbgv(x) (void)0
#define dbga(arr, len) (void)0
#define dbgi(it) (void)0
#endif

using ll = long long;
using dbl = long double;
using pii = pair<int, int>;

const int N = 100500;
const ll LINF = (ll)1e18;

ll n, m, vel;
int lads, elevs;
ll lad[N], elev[N];

ll query(ll x1, ll y1, ll x2, ll y2)
{
    if (x1 == x2)
        return abs(y1 - y2);

    ll best = LINF;

    int idx0 = lower_bound(lad, lad + lads, y1) - lad;
    for (int idx : {idx0, idx0 - 1})
    {
        if (!(0 <= idx && idx < lads))
            continue;
        best = min(best, abs(y1 - lad[idx]) + abs(x1 - x2) + abs(lad[idx] - y2));
    }

    idx0 = lower_bound(elev, elev + elevs, y1) - elev;
    for (int idx : {idx0, idx0 - 1})
    {
        if (!(0 <= idx && idx < elevs))
            continue;
        best = min(best, abs(y1 - elev[idx]) + (abs(x1 - x2) + vel - 1) / vel + abs(elev[idx] - y2));
    }

    return best;
}

void solve()
{
    scanf("%lld%lld%d%d%lld", &n, &m, &lads, &elevs, &vel);
    for (int i = 0; i < lads; i++)
        scanf("%lld", &lad[i]);
    for (int i = 0; i < elevs; i++)
        scanf("%lld", &elev[i]);

    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        ll x1, y1, x2, y2;
        scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);
        printf("%lld\n", query(x1, y1, x2, y2));
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    solve();

    dbg("\n\ntime = %.3lf\n", (double)clock() / CLOCKS_PER_SEC);
}