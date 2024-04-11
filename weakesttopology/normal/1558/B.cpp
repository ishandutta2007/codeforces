#include <bits/stdc++.h>
using namespace std;
long long add(long long x, long long y, long long mod) {
    long long res = x + y;
    if (res >= mod) res -= mod;
    return res;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    long long mod;
    cin >> N >> mod;
    vector<long long> dp(N + 2);
    dp[N] = 1;
    auto query = [&](int l, int r) {
        return add(dp[l], mod - dp[r + 1], mod);
    };
    for (int x = N - 1; x >= 1; --x) {
        dp[x] = dp[x + 1];
        for (int d = 2; d * x <= N; ++d) {
            dp[x] = add(dp[x], query(d * x, min(d * x + d - 1, N)), mod);
        }
        dp[x] = add(dp[x], dp[x + 1], mod);
    }
    cout << query(1, 1) << '\n';
    exit(0);
}