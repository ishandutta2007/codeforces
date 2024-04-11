#include <bits/stdc++.h>
using namespace std;

int MOD = 1e9 + 7;
long long dp[5001][5001];

long long power(long long b, int e) {
    long long r = 1;
    while (e) {
        if (e & 1) r = (r * b) % MOD;
        b = (b * b) % MOD;
        e >>= 1;
    }
    return r;
}

int main() {
    int n, k;
    cin >> n >> k;

    dp[0][0] = 1;
    for (int i = 1; i <= k; i++)
        for (int j = 1; j <= i; j++)
            dp[i][j] = (j * dp[i-1][j] + (n-j+1) * dp[i-1][j-1]) % MOD;

    long long r = 0;
    for (int i = 1; i <= min(k, n); i++)
        r += dp[k][i] * power(2, n-i) % MOD;
    cout << r % MOD << endl;
}