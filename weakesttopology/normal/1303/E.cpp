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

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
using ll = long long;

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

// xz

string solve()
{
    string s, t; cin >> s >> t;

    int n = sz(s), m = sz(t);

    int l = 0;
    for (int i = 0; i < n && l < m; ++i)
        if (s[i] == t[l]) ++l;

    if (l == m) return "YES";

    vector pos(26, vector(0, 0));
    for (int i = 0; i < n; ++i)
        pos[s[i] - 'a'].push_back(i);

    vector dp(n + 1, vector(n + 1, 0));

    auto chmin = [](int& x, int y) { x = min(x, y); };

    for (int k = 1; k < m; ++k)
    {
        string a = t.substr(0, k), b = t.substr(k, m);

        dp.assign(n + 1, vector(n + 1, INF)); dp[0][0] = -1;

        for (int i = 0; i < k; ++i)
            for (int j = 0; j < m - k; ++j)
            {
                int x = a[i] - 'a', y = b[j] - 'a';

                auto aiter = upper_bound(all(pos[x]), dp[i][j]);
                if (aiter != pos[x].end()) chmin(dp[i + 1][j], *aiter);

                auto biter = upper_bound(all(pos[y]), dp[i][j]);
                if (biter != pos[y].end()) chmin(dp[i][j + 1], *biter);
            }

        for (int i = 0; i < k; ++i)
        {
            int x = a[i] - 'a';
            auto aiter = upper_bound(all(pos[x]), dp[i][m - k]);
            if (aiter != pos[x].end()) chmin(dp[i + 1][m - k], *aiter);
        }

        for (int j = 0; j < m - k; ++j)
        {
            int y = b[j] - 'a';
            auto biter = upper_bound(all(pos[y]), dp[k][j]);
            if (biter != pos[y].end()) chmin(dp[k][j + 1], *biter);
        }

        if (dp[k][m - k] < INF) return "YES";
    }
    return "NO";
}

int main()
{ _
    int t; cin >> t;
    while (t--) cout << solve() << endl;
    exit(0);
}