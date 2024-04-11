#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
using namespace __gnu_pbds;

#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) X.begin(), X.end()
#define sz(X) (int)X.size()

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
using ll = long long;

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

// xz

int main()
{
    int n; cin >> n;

    vector dp(n + 1, vector(n + 1, 0LL));

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            dp[i][j] = (i % 2 ? 1 : -1) * (2LL << (i + j));

    ll M = abs(dp[n][n]);

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
            cout << dp[i][j] + M << " ";
        cout << endl;
    }

    auto sgn = [](ll z) { return z > 0; };

    int q; cin >> q;

    while (q--)
    {
        vector<int> X, Y;
        int x = n, y = n;
        cout << flush;
        ll k; cin >> k;
        k -= (2 * n - 1) * M;
        while (x && y)
        {
            X.push_back(x), Y.push_back(y);

            k -= dp[x][y];
            if (y >= 2 && sgn(dp[x][y - 1]) == sgn(k)) y -= 1;
            else x -= 1;
        }
        reverse(all(X)), reverse(all(Y));
        for (int i = 0; i < sz(X); ++i)
            cout << X[i] << " " << Y[i] << endl;
        cout << endl;
    }

    exit(0);
}