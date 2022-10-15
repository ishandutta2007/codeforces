#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
using namespace __gnu_pbds;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) X.begin(), X.end()
#define sz(X) (int)X.size()
#define read(x) for (int xx = 0; xx < sz(x); ++xx) cin >> x[xx];

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
using ll = long long;

using vi = vector<int>;
using vll = vector<ll>;

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

// xz

void dfs(const vector<vi>& E, int u, vi& depth)
{
    for (auto v : E[u])
    {
        depth[v] = depth[u] + 1;
        dfs(E, v, depth);
    }
}

int main()
{ _
    int n; cin >> n;
    vll a(n), b(n); read(a); read(b);

    vector<vi> E(n); vi d(n, 0);
    for (int i = 0; i < n; ++i)
    {
        if (b[i] != -1)
        {
            --b[i];
            E[b[i]].push_back(i);
            d[i] = 1;
        }
    }

    vi depth(n, 0);
    for (int u = 0; u < n; ++u)
        if (d[u] == 0) dfs(E, u, depth);

    vi I(n, 0); iota(all(I), 0);
    sort(all(I), [&depth](int u, int v){ return depth[u] > depth[v]; });

    ll ans = 0;
    vi op;
    for (auto u : I)
        if (a[u] >= 0)
        {
            if (b[u] != -1)
                a[b[u]] += a[u];
            ans += a[u];
            op.push_back(u);
        }
    reverse(all(I));
    for (auto u : I)
        if (a[u] < 0)
        {
            ans += a[u];
            op.push_back(u);
        }

    cout << ans << endl;
    for (auto u : op)
        cout << u + 1 << " ";
    cout << endl;

    exit(0);
}