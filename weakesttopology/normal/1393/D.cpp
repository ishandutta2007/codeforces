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
using vii = vector<pair<int, int>>;
using vll = vector<ll>;

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

// xz

int main()
{ _
    int n, m; cin >> n >> m;

    if (n < 3 || m < 3)
    {
        cout << n * m << endl;
        exit(0);
    }

    vector<string> S(n);
    for (int i = 0; i < n; ++i)
        cin >> S[i];

    vector<vll> dp(n, vll(m, 0));

    for (int i = 0; i < n; ++i)
        dp[i][0] = dp[i][1] = 1;

    for (int j = 0; j < m; ++j)
        dp[0][j] = dp[n - 1][j] = 1;

    auto check = [&S](int i, int j)
    {
        return
            S[i][j] == S[i - 1][j - 1] &&
            S[i][j] == S[i][j - 2] &&
            S[i][j] == S[i + 1][j - 1] &&
            S[i][j] == S[i][j - 1];
    };

    int ans = 2 * n + 2 * m - 4;

    for (int j = 2; j < m; ++j)
        for (int i = 1; i < n - 1; ++i)
        {
            if (check(i, j))
                dp[i][j] = 1 + min({ dp[i - 1][j - 1], dp[i][j - 2], dp[i + 1][j - 1] });
            else dp[i][j] = 1;

            ans += dp[i][j];
        }

    cout << ans << endl;

    exit(0);
}