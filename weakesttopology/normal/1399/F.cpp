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

int main()
{ _
    int t; cin >> t;

    const int N = 1 << 20;

    while (t--)
    {
        int n; cin >> n;
        vi l(n + 1), r(n + 1);
        for (int i = 0; i < n; ++i)
            cin >> l[i] >> r[i];
        l[n] = 1, r[n] = N;
        ++n;

        vi J(n, 0); iota(all(J), 0);
        sort(all(J), [&](int i, int j){ return pair(r[i], r[i] - l[i]) < pair(r[j], r[j] - l[j]); });

        vi weight(n, 0), b, dp;
;
        for (auto i : J)
        {
            dp = b = { 0 };
            for (auto j : J)
            {
                if (j == i || l[j] < l[i] || r[i] < r[j])
                    continue;
                int p = (int)distance(b.begin(), upper_bound(all(b), l[j] - 1));
                int cur = dp[p - 1] + weight[j];
                if (b.back() < r[j])
                    dp.push_back(dp.back()), b.push_back(r[j]);
                dp.back() = max(dp.back(), cur);
            }
            weight[i] = dp.back() + 1;
        }
        int ans = weight[n - 1] - 1;
        cout << ans << endl;
    }
    exit(0);
}