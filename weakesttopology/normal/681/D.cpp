#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define debug(x) cerr << #x << " == " << (x) << '\n'
#define mp(x, y) make_pair(x, y)
#define ALL(X) X.begin(), X.end()
#define READ(X) for (int i_ = 0; i_ < (int)X.size(); ++i_) cin >> X[i_]
#define SZ(X) (int)X.size()

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int N = 2 * 1e5;
int n;
int st[2 * N];

vi pr;

const int default_value = 0;
int op(int l, int r)
{
    return max(l, r);
}

void build()
{
    for (int i = n - 1; i > 0; --i)
        st[i] = op(st[i << 1], st[i << 1 | 1]);
}

void modify(int p, int value)
{
    for (st[p += n] = value; p > 1; p >>= 1)
        st[p >> 1] = op(st[p], st[p ^ 1]);
}

// inclusive
int query(int l, int r)
{
    int res = default_value;
    for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1)
    {
        if (l & 1)
            res = op(st[l++], res);
        if (r & 1)
            res = op(res, st[--r]);
    }
    return res;
}

vi a, h;

void dfs(const vvi& E, int u, int par)
{
    int p = query(0, h[u]) + 1;
    if (a[u] == u)
    {
        modify(h[u], p);
        pr[u] = p;
    }

    for (auto v : E[u])
    {
        h[v] = h[u] + 1;
        dfs(E, v, u);
    }

    modify(h[u], 0);
}

bool dfs_check(const vvi& E, int u)
{
    modify(h[u], pr[u]);

    bool r = true;
    for (auto v : E[u])
        r = r && dfs_check(E, v);

    r = r && query(0, h[u]) == pr[a[u]];

    modify(h[u], 0);

    return r;
}

int main()
{ _
    int m; cin >> n >> m;
    vvi E(n);
    vi d(n, 0);
    for (int j = 0; j < m; ++j)
    {
        int p, q; cin >> p >> q; --p, --q;
        E[p].pb(q);
        d[q]++;
    }

    a.assign(n, 0);
    h.assign(n, 0);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i]; --a[i];
        st[n + i] = 0;
    }
    build();

    pr.assign(n, 0);
    for (int u = 0; u < n; ++u)
        if (not d[u])
            dfs(E, u, 0);

    bool r = true;
    for (int u = 0; u < n; ++u)
        if (not d[u])
            r = r && dfs_check(E, u);

    if (not r)
    {
        cout << -1 << endl;
        exit(0);
    }

    vi ans(n);
    for (int i = 0; i < n; ++i)
        ans[i] = i;
    vi _pr = pr;
    sort(ALL(ans), [&_pr](int i, int j){ return _pr[i] > _pr[j]; });

    cout << n << endl;
    for (auto x : ans)
        cout << x + 1 << " ";
    cout << endl;

    exit(0);
}

/*
 * INT_MAX      ~  2 * 1e9  ~ 2^31 - 1
 * LLONG_MAX    ~  9 * 1e18 ~ 2^63 - 1
 * ULLONG_MAX   ~ 18 * 1e18 ~ 2^64 - 1
 *
 * INF  ~ 1.0 * 1e9
 * LINF ~ 4.5 * 1e18
 *
 * CHECK:
 *      OVERFLOW
 *      IF/LOOP CONDITIONS
 *      CREATION OF STL CONTAINERS
*/