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

int main()
{ _
    string s, t; cin >> s >> t;
    const int n = sz(s), m = sz(t), N = 250;

    vector dp(n + 1, vector(m + 1, vector(N + 1, INF)));
    vector p(n + 1, vector(m + 1, vector(N + 1, array<int, 3>())));

    for (int bal = 0; bal <= N; ++bal)
        dp[0][0][bal] = bal, p[0][0][bal] = { 0, 0, bal - 1 };

    auto chmin = [](int& x, int y) { return y < x ? x = y, 1 : 0; };

    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= m; ++j)
        {
            for (int bal = N - 1; bal >= 0; --bal)
            {
                int c = dp[i][j][bal] + 1;
                array<int, 3> par = { i, j, bal };

                if (i < n && s[i] == '(' && chmin(dp[i + 1][j][bal + 1], c)) p[i + 1][j][bal + 1] = par;
                if (j < m && t[j] == '(' && chmin(dp[i][j + 1][bal + 1], c)) p[i][j + 1][bal + 1] = par;
                if (i < n && j < m && s[i] == '(' && t[j] == '(' && chmin(dp[i + 1][j + 1][bal + 1], c)) p[i + 1][j + 1][bal + 1] = par;

                if (bal)
                {
                    if (i < n && s[i] == ')' && chmin(dp[i + 1][j][bal - 1], c)) p[i + 1][j][bal - 1] = par;
                    if (j < m && t[j] == ')' && chmin(dp[i][j + 1][bal - 1], c)) p[i][j + 1][bal - 1] = par;
                    if (i < n && j < m && s[i] == ')' && t[j] == ')' && chmin(dp[i + 1][j + 1][bal - 1], c)) p[i + 1][j + 1][bal - 1] = par;

                    if(chmin(dp[i][j][bal - 1], c)) p[i][j][bal - 1] = par;
                }

            }
        }

    int i = n, j = m, bal = 0;

    string ans;
    while (i != 0 || j != 0 || bal != 0)
    {
        auto par = p[i][j][bal];
        ans += par[2] > bal ? ")" : "(";
        i = par[0], j = par[1], bal = par[2];
    }
    reverse(all(ans));

    cout << ans << endl;

    exit(0);
}