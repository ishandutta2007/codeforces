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
using vvi = vector<vi>;
using vll = vector<ll>;

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

// xz

int main()
{ _
    int n, m; cin >> n >> m;
    vvi a(n, vi(m));
    for (int i = 0; i < n; ++i)
    {
        string s; cin >> s;
        for (int j = 0; j < m; ++j)
            a[i][j] = s[j] - '0';
    }

    if (n >= 4 && m >= 4)
    {
        cout << -1 << endl;
        exit(0);
    }
    if (n == 1 || m == 1)
    {
        cout << 0 << endl;
        exit(0);
    }

    auto cost = [](int mask1, int mask2)
    {
        return __builtin_popcount(mask1 ^ mask2);
    };

    auto friendly = [&n](int mask1, int mask2)
    {
        for (int z = 0; z < n - 1; ++z)
        {
            int x = __builtin_popcount(mask1 & (1 << z | 1 << (z + 1)));
            int y = __builtin_popcount(mask2 & (1 << z | 1 << (z + 1)));
            if ((x + y) % 2 == 0)
                return false;
        }
        return true;
    };

    int N = 1 << n;

    vi x(m, 0);
    for (int j = 0; j < m; ++j)
        for (int i = 0; i < n; ++i)
            x[j] += a[i][j] << i;

    vvi dp(m, vi(N, INF));
    for (int mask = 0; mask < N; ++mask)
        dp[0][mask] = cost(x[0], mask);

    for (int j = 1; j < m; ++j)
        for (int cur = 0; cur < N; ++cur)
            for (int pre = 0; pre < N; ++pre)
                if (friendly(pre, cur))
                dp[j][cur] = min(dp[j][cur], dp[j - 1][pre] + cost(x[j], cur));

    int ans = *min_element(all(dp[m - 1]));

    cout << ans << endl;

    exit(0);
}