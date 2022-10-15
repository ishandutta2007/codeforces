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

class UFDS
{
private:
    vector<int> p, rk, sz;
    int num_disjoint_sets;
public:
    UFDS(int n)
    {
        rk.assign(n, 0);
        p.assign(n, 0);
        for (int i = 0; i < n; ++i)
            p[i] = i;
        num_disjoint_sets = n;
        sz.assign(n, 1);
    }
    int find_set(int i)
    {
        return (p[i] == i) ? i : (p[i] = find_set(p[i]));
    }
    bool is_same_set(int i, int j)
    {
        return find_set(i) == find_set(j);
    }
    void union_set(int i, int j)
    {
        int x = find_set(i), y = find_set(j);
        if (x != y)
        {
            --num_disjoint_sets;
            if (rk[x] >= rk[y])
            {
                p[y] = x;
                rk[x] += (rk[x] == rk[y]);
                sz[x] += sz[y];
            }
            else
            {
                p[x] = y;
                sz[y] += sz[x];
            }
        }
    }
    int set_size(int i)
    {
        return sz[find_set(i)];
    }
    int num_sets()
    {
        return num_disjoint_sets;
    }
};

ii bfs(const vvi& E, vi& d, int r)
{
    queue<int> q; q.push(r); d[r] = 0;
    while (not q.empty())
    {
        int u = q.front(); q.pop();
        for (auto v : E[u])
            if (d[v] == -1)
            {
                d[v] = d[u] + 1;
                q.push(v);
                if (d[v] > d[r])
                    r = v;
            }
    }
    return mp(r, d[r]);
}

int main()
{ _
    int n, m, q; cin >> n >> m >> q;

    vvi E(n); UFDS S(n);
    for (int j = 0; j < m; ++j)
    {
        int a, b; cin >> a >> b; --a, --b;
        E[a].pb(b);
        E[b].pb(a);
        S.union_set(a, b);
    }

    vi diam(n, -1);
    vvi d(2, vi(n, -1));
    for (int u = 0; u < n; ++u)
    {
        int v = S.find_set(u);
        if (diam[v] == -1)
        {
            tie(v, diam[u]) = bfs(E, d[0], v);
            tie(v, diam[u]) = bfs(E, d[1], v);
            diam[S.find_set(u)] = diam[u];
        }
    }

    for (int z = 0; z < q; ++z)
    {
        int t; cin >> t;
        if (t == 1)
        {
            int x; cin >> x; --x;
            x = S.find_set(x);
            cout << diam[x] << endl;
        }
        else
        {
            int x, y; cin >> x >> y; --x, --y;
            x = S.find_set(x), y = S.find_set(y);

            if (x != y)
            {
                S.union_set(x, y);
                int p = S.find_set(x);
                diam[p] = max(max(diam[x], diam[y]), 1 + (diam[x] + 1) / 2 + (diam[y] + 1) / 2);
            }
        }
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