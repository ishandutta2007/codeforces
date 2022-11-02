#include <iostream>

using namespace std;
using ll = long long;

const ll MOD = 1000000007;

int main() {
    int N;
    ll l, r;
    cin >> N >> l >> r;

    ll mod[3];
    for (int i = 0; i < 3; ++i) {
        mod[i] = (r - i + 3) / 3 - (l - i + 2) / 3;
    }

    ll dp[N + 1][3];
    fill(dp[0], dp[N + 1], 0);
    dp[0][0] = 1;
    for (int i = 1; i <= N; ++i) {
        for (int k = 0; k < 3; ++k) {
            for (int l = 0; l < 3; ++l) {
                dp[i][(k + l) % 3] += dp[i - 1][k] * mod[l] % MOD;
            }
        }

        for (int k = 0; k < 3; ++k) {
            dp[i][k] %= MOD;
        }
    }

    cout << dp[N][0] << endl;
    return 0;
}