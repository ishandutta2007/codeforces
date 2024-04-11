#include <algorithm>
#include <iostream>

using namespace std;
using ll = long long;

const ll INF = 1LL << 50;

int main() {
    int N, K, X;
    cin >> N >> K >> X;

    ll a[N + 1];
    for (int i = 1; i <= N; ++i) {
        cin >> a[i];
    }

    ll dp[N + 1][X + 1];
    // dp[i][j] = iji
    fill(dp[0], dp[N + 1], -INF);
    dp[0][0] = 0;

    for (int x = 1; x <= X; ++x) {
        for (int i = 1; i <= N; ++i) {
            for (int k = max(0, i - K); k < i; ++k) {
                dp[i][x] = max(dp[i][x], dp[k][x - 1] + a[i]);
            }
        }
    }

    ll ans = -1;
    for (int i = max(0, N - K + 1); i <= N; ++i) {
        ans = max(ans, dp[i][X]);
    }
    cout << (ans < 0 ? -1 : ans) << endl;
    return 0;
}