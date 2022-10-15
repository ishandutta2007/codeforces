#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
using namespace __gnu_pbds;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) X.begin(), X.end()
#define read(x) for (int xx = 0; xx < sz(x); ++xx) cin >> x[xx];

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
using ll = long long;

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

// xz

int n, k, N;

const int mxn = 2e5, mxk = 10, mxN = mxk * mxk;

ll S[mxk][mxk];
ll val[mxn];
ll good;

int F[mxn][mxk];
int W[mxn][mxk];
int deg[mxn];

int id(int d, int i) { return d * k + i; }

int dfs(int i, ll sum)
{
    if (i == k) return sum == good;

    int ct = 0;
    for (auto z = 0; z <= i; ++z)
        ct += dfs(i + 1, sum + S[i][z]);

    return ct;
}

int main()
{ _
    int m; cin >> n >> m >> k; N = k * k;

    memset(S, 0, sizeof(S));

    memset(F, -1, sizeof(F));
    memset(W, 0, sizeof(W));
    memset(deg, 0, sizeof(deg));

    for (int j = 0; j < m; ++j)
    {
        int u, v, w; cin >> u >> v >> w; --u, --v;
        F[u][deg[u]] = v;
        W[u][deg[u]] = w;
        ++deg[u];
    }

    uniform_int_distribution<ll> unif(1e8, 1e9);
    for (int u = 0; u < n; ++u) val[u] = unif(rng);
    good = accumulate(val, val + n, 0LL);

    int temp[mxn] = { 0 };
    for (int u = 0; u < n; ++u)
    {
        for (int i = 0; i < deg[u]; ++i)
            temp[F[u][i]] = W[u][i];
        sort(F[u], F[u] + deg[u], [&](int x, int y) { return temp[x] < temp[y]; });
        for (int i = 0; i < deg[u];++i)
            S[deg[u] - 1][i] += val[F[u][i]];
    }

    int ans = dfs(0, 0LL);

    cout << ans << endl;

    exit(0);
}