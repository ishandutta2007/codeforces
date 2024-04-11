#include <iostream>
#include <string>

using namespace std;
using ll = long long;

const ll MOD = 1000000007;

int main() {
    string S;
    cin >> S;

    int N = S.size();
    S = "$" + S;
    ll dp[2][N + 1];
    dp[0][0] = 0;
    dp[1][0] = 1;

    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j < 2; ++j) {
            dp[j][i] = dp[j][i - 1];
        }

        if (S[i] == 'a') {
            dp[0][i] += dp[1][i - 1];
        } else if (S[i] == 'b') {
            dp[1][i] += dp[0][i - 1];
            dp[0][i] = 0;
        }

        for (int j = 0; j < 2; ++j) {
            dp[j][i] %= MOD;
        }
    }

    cout << (dp[0][N] + dp[1][N] - 1) % MOD << endl;
    return 0;
}