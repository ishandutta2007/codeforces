#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) begin(X), end(X)
#define size(X) (int)std::size(X)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

int solve()
{
    string s; cin >> s;

    int n = size(s);

    constexpr int K = 26;

    vector<array<array<int, K>, K>> dp(2);

    for (int i = 0; i < 2; ++i)
        for (int x = 0; x < K; ++x)
            for (int y = 0; y < K; ++y)
                dp[i][x][y] = INF;

    // dp[i][x][y] = minimum cost of s[0, ..., i] with s[i - 1] = x and s[i] = y;

    for (int x = 0; x < K; ++x)
        for (int y = 0; y < K; ++y) if (y != x)
            dp[0][x][y] = ('a' + y != s[0]);

    array<int, K> prefix, suffix;

    int b = 0;

    for (int i = 1; i < n; ++i, b ^= 1)
    {
        for (int x = 0; x < K; ++x)
        {
            fill(all(prefix), INF), fill(all(suffix), INF);

            for (int z = 1; z < K; ++z)
                prefix[z] = min(dp[b][z - 1][x], prefix[z - 1]);
            for (int z = K - 2; z >= 0; --z)
                suffix[z] = min(dp[b][z + 1][x], suffix[z + 1]);

            for (int y = 0; y < K; ++y) if (y != x)
                dp[b ^ 1][x][y] = ('a' + y != s[i]) + min(prefix[y], suffix[y]);
        }

        for (int x = 0; x < K; ++x)
            for (int y = 0; y < K; ++y)
                dp[b][x][y] = INF;
    }

    int ans = INF;

    for (int x = 0; x < K; ++x)
        for (int y = 0; y < K; ++y)
            ans = min(ans, dp[b][x][y]);

    return ans;
}

int main()
{ _
    int t; cin >> t;
    while (t--) cout << solve() << endl;
    exit(0);
}