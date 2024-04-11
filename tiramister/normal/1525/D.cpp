#include <iostream>
#include <vector>

using namespace std;
constexpr int INF = 1 << 30;

void solve() {
    vector<int> xs, ys;
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            int t;
            cin >> t;
            if (t == 1) {
                xs.push_back(i);
            } else {
                ys.push_back(i);
            }
        }
    }

    int n = xs.size(), m = ys.size();
    auto dp = vector(n + 1, vector(m + 1, INF));
    dp[0][0] = 0;

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < m; ++j) {
            // use j-th chair
            if (i + 1 <= n) {
                dp[i + 1][j + 1] = min(dp[i + 1][j + 1],
                                       dp[i][j] + abs(xs[i] - ys[j]));
            }

            // don't use j-th chair
            dp[i][j + 1] = min(dp[i][j + 1], dp[i][j]);
        }
    }

    cout << dp[n][m] << "\n";
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    solve();

    return 0;
}