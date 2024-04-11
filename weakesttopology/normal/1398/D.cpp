#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
using namespace __gnu_pbds;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) X.begin(), X.end()
#define rall(X) X.rbegin(), X.rend()
#define sz(X) (int)X.size()
#define read(x) for (int xx = 0; xx < sz(x); ++xx) cin >> x[xx];

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
using ll = long long;

using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vvi = vector<vi>;
using vll = vector<ll>;

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

// xz

int main()
{ _
    int R, G, B; cin >> R >> G >> B;

    vi r(R); read(r); sort(all(r));
    vi g(G); read(g); sort(all(g));
    vi b(B); read(b); sort(all(b));

    r.insert(r.begin(), 0);
    g.insert(g.begin(), 0);
    b.insert(b.begin(), 0);

    vector dp(R + 1, vector(G + 1, vll(B + 1, 0)));

    ll ans = 0;
    for (int i = 0; i <= R; ++i)
        for (int j = 0; j <= G; ++j)
            for (int k = 0; k <= B; ++k)
            {
                ll x = r[i] * g[j];
                if (i && j) x += dp[i - 1][j - 1][k];

                ll y = r[i] * b[k];
                if (i && k) y += dp[i - 1][j][k - 1];

                ll z = g[j] * b[k];
                if (j && k) z += dp[i][j - 1][k - 1];

                dp[i][j][k] = max({x, y, z});
                ans = max(ans, dp[i][j][k]);
            }

    cout << ans << endl;

    exit(0);
}