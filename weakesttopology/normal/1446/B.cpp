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

bool chmax(auto& x, auto y) { return x < y ? x = y, true : false; }

int main()
{ _
    int n, m; cin >> n >> m;

    string A, B; cin >> A >> B;

    A.insert(begin(A), '*');
    B.insert(begin(B), '*');

    vector dp(n + 1, vector(m + 1, -INF));

    dp[0][0] = 0;

    int ans = 0;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            if (A[i] == B[j])
            {
                if (chmax(dp[i][j], dp[i - 1][j - 1] + 4))
                    ans = max(ans, dp[i][j] - (i + j + 2));

                if (chmax(dp[i][j], 4 + i + j))
                    ans = max(ans, dp[i][j] - (i + j + 2));
            }

            chmax(dp[i][j], max(dp[i - 1][j], dp[i][j - 1]));
        }

    cout << ans << endl;

    exit(0);
}