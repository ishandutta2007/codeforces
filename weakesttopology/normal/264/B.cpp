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
    const int N = 1e5;
    int lp[N + 1] = { 0 };
    vi pr;
    for (int i = 2; i <= N; ++i)
    {
        if (lp[i] == 0) lp[i] = i, pr.push_back(i);

        for (auto p : pr)
        {
            if (p > lp[i] || i * p > N)
                break;
            lp[i * p] = p;
        }
    }

    int n; cin >> n;
    vi a(n); read(a);

    vi dp(N + 1, 0); dp[1] = 1;
    for (int i = (a[0] <= 1); i < n; ++i)
    {
        vi f;
        while (lp[a[i]])
            f.push_back(lp[a[i]]), a[i] /= lp[a[i]];
        sort(all(f));
        f.erase(unique(all(f)), f.end());

        int m = 1;
        for (auto p : f) m = max(m, dp[p] + 1);
        for (auto p : f) dp[p] = m;
    }

    int ans = *max_element(all(dp));
    cout << ans << endl;

    exit(0);
}