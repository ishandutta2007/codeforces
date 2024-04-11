#include <iostream>
#include <string>

using namespace std;
using ll = long long;

const ll INF = 1LL << 60;
const string hard = "hard";

int main() {
    int N;
    string S;
    cin >> N >> S;

    ll a[N];
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    ll dp[5][N + 1];
    dp[0][0] = 0;
    for (int k = 1; k < 5; ++k) {
        dp[k][0] = INF;
    }

    for (int i = 0; i < N; ++i) {
        for (int k = 0; k < 5; ++k) {
            dp[k][i + 1] = dp[k][i];
        }

        for (int k = 0; k < 4; ++k) {
            if (S[i] == hard[k]) {
                dp[k + 1][i + 1] = min(dp[k][i], dp[k + 1][i]);
                dp[k][i + 1] = dp[k][i] + a[i];
            }
        }
    }

    ll ans = INF;
    for (int k = 0; k < 4; ++k) {
        ans = min(ans, dp[k][N]);
    }

    cout << ans << endl;
    return 0;
}