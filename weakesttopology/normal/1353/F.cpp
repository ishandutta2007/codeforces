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

using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

// xz

ll solve()
{
    int n, m; cin >> n >> m;

    vvll a(n, vll(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> a[i][j];

    vvll dp = a;
    auto cost = [&](ll x)
    {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                dp[i][j] = LINF;

        dp[0][0] = a[0][0] - x;
        if (dp[0][0] < 0) return LINF;

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
            {
                if (i == 0 && j == 0) continue;
                ll diff = a[i][j] - (x + i + j);
                if (diff < 0) continue;
                if (i - 1 >= 0) dp[i][j] = min(dp[i][j], dp[i - 1][j]);
                if (j - 1 >= 0) dp[i][j] = min(dp[i][j], dp[i][j - 1]);
                dp[i][j] += diff;
            }
        return dp[n - 1][m - 1];
    };

    ll ans = LINF;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            ans = min(ans, cost(a[i][j] - (i + j)));
    return ans;
}

int main()
{ _
    int t; cin >> t;
    while (t--) cout << solve() << endl;
    exit(0);
}