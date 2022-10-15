#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) (X).begin(), (X).end()
#define sz(X) (int)X.size()

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

void chmax(auto& x, auto y) { x = max(x, y); }

int main()
{ _
    int n, p, k; cin >> n >> p >> k;

    vector a(n, 0);
    for (auto& x : a) cin >> x;

    vector s(n, vector(p, 0));
    for (auto& v : s) for (auto& x : v) cin >> x;

    vector I(n, 0); iota(all(I), 0);
    sort(all(I), [&a](int i, int j){ return a[i] > a[j]; });

    auto c = [&](int i, int mask) { return i - __builtin_popcount(mask); };

    const int N = 1 << p;
    vector vis(2, vector(N, 0)); vis[0][0] = 1;
    vector dp(2, vector(N, 0LL));
    int b = 0;

    for (int i = 0; i < n; ++i, b ^= 1)
    {
        int v = I[i];
        for (int mask = 0; mask < N; ++mask)
        {
            if (not vis[b][mask]) continue;

            vis[b ^ 1][mask] = 1;
            if (c(i, mask) < k)
                chmax(dp[b ^ 1][mask], dp[b][mask] + a[v]);
            else
                chmax(dp[b ^ 1][mask], dp[b][mask]);

            for (int j = 0; j < p; ++j) if (not (mask >> j & 1))
            {
                chmax(dp[b ^ 1][mask + (1 << j)], dp[b][mask] + s[v][j]);
                vis[b ^ 1][mask + (1 << j)] = 1;
            }
        }
        fill(all(dp[b]), 0), fill(all(vis[b]), 0);
    }

    ll ans = dp[b][N - 1];

    cout << ans << endl;

    exit(0);
}