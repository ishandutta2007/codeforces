#include <iostream>
#include <numeric>
#include <vector>

using namespace std;
using ll = long long;

const ll MOD = 998244353;

template <class T>
vector<T> Vec(size_t l, T v) { return vector<T>(l, v); }

template <class T, class... Ts>
auto Vec(size_t l, Ts... ts) {
    return vector<decltype(Vec<T>(ts...))>(l, Vec<T>(ts...));
}

int main() {
    int N, K;
    cin >> N >> K;

    auto dp = Vec<ll>(N, N * 2 + 3, 4, 0LL);
    dp[0][1][0] = dp[0][2][1] = dp[0][2][2] = dp[0][1][3] = 1;

    for (int i = 0; i < N - 1; ++i) {
        for (int k = 0; k <= N * 2; ++k) {
            dp[i][k][0] %= MOD;
            dp[i + 1][k][0] += dp[i][k][0];
            dp[i + 1][k + 1][1] += dp[i][k][0];
            dp[i + 1][k + 1][2] += dp[i][k][0];
            dp[i + 1][k + 1][3] += dp[i][k][0];

            dp[i][k][1] %= MOD;
            dp[i + 1][k][0] += dp[i][k][1];
            dp[i + 1][k][1] += dp[i][k][1];
            dp[i + 1][k + 2][2] += dp[i][k][1];
            dp[i + 1][k][3] += dp[i][k][1];

            dp[i][k][2] %= MOD;
            dp[i + 1][k][0] += dp[i][k][2];
            dp[i + 1][k + 2][1] += dp[i][k][2];
            dp[i + 1][k][2] += dp[i][k][2];
            dp[i + 1][k][3] += dp[i][k][2];

            dp[i][k][3] %= MOD;
            dp[i + 1][k + 1][0] += dp[i][k][3];
            dp[i + 1][k + 1][1] += dp[i][k][3];
            dp[i + 1][k + 1][2] += dp[i][k][3];
            dp[i + 1][k][3] += dp[i][k][3];
        }
    }

    cout << accumulate(dp[N - 1][K].begin(), dp[N - 1][K].end(), 0LL) % MOD << endl;
    return 0;
}