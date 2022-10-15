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

int n, l, timer;
vvi E;
vi tin, tout;
vvi up;
vi sz, depth;

int dfs(int v, int p)
{
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    sz[v] = 1;

    for (int u : E[v])
        if (u != p)
        {
            depth[u] = depth[v] + 1;
            sz[v] += dfs(u, v);
        }

    tout[v] = ++timer;
    return sz[v];
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int LCA(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i)
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    return up[u][0];
}

void preprocess(int root)
{
    sz.assign(n, 0);
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<int>(l + 1));
    dfs(root, root);
}

int dist(int u, int v)
{
    int p = LCA(u, v);
    return depth[u] + depth[v] - 2 * depth[p];
}

ii find_middle(int u, int v)
{
    int d = dist(u, v) / 2;

    int p = LCA(u, v), mid;

    if (dist(u, p) >= dist(v, p))
    {
        for (int i = l; i >= 0; --i)
            if (!is_ancestor(up[u][i], v) && dist(v, up[u][i]) > d)
                u = up[u][i];
        mid = up[u][0];
    }
    else
    {
        swap(u, v);
        for (int i = l; i >= 0; --i)
            if (!is_ancestor(up[u][i], v) && dist(v, up[u][i]) > d)
                u = up[u][i];
        mid = up[u][0];
        u = up[u][1];
    }

    return mp(mid, u);
}

int main()
{ _
    cin >> n; E.assign(n, vi());
    for (int i = 0; i < n - 1; ++i)
    {
        int a, b; cin >> a >> b; --a, --b;
        E[a].pb(b), E[b].pb(a);
    }

    depth.assign(n, 0); sz.assign(n, 0);
    preprocess(0);

    int m; cin >> m;
    for (int j = 0; j < m; ++j)
    {
        int x, y; cin >> x >> y; --x, --y;

        if (x == y)
        {
            cout << n << endl;
            continue;
        }

        if (dist(x, y) % 2)
        {
            cout << 0 << endl;
            continue;
        }

        auto [mid, mx] = find_middle(x, y);
        auto [mid_, my] = find_middle(y, x);
        assert(mid == mid_);

        int ans, p = LCA(x, y);

        if (x == p || y == p)
        {
            if (y == p)
            {
                swap(x, y);
                swap(mx, my);
            }
            ans = sz[mid] - sz[my];
        }
        else if (mid == p)
            ans = n - sz[mx] - sz[my];
        else
        {
            if (is_ancestor(mid, x))
            {
                swap(x, y);
                swap(mx, my);
            }
            ans = sz[mid] - sz[my];
        }
        cout << ans << endl;
    }

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