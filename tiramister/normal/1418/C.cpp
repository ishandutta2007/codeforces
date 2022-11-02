#line 1 "main.cpp"
#include <iostream>
#include <vector>

using namespace std;

constexpr int INF = 1 << 30;

void solve() {
    int n;
    cin >> n;
    vector<int> xs(n);
    for (auto& x : xs) cin >> x;

    auto dp = vector(2, vector(n + 1, INF));
    dp[1][0] = 0;

    for (int i = 0; i < n; ++i) {
        for (int b = 0; b < 2; ++b) {
            int sum = 0;
            for (int j = i; j < i + 2 && j < n; ++j) {
                sum += xs[j] * b;
                dp[1 - b][j + 1] = min(dp[1 - b][j + 1], dp[b][i] + sum);
            }
        }
    }

    cout << min(dp[0][n], dp[1][n]) << "\n";
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int q;
    cin >> q;
    while (q--) solve();

    return 0;
}