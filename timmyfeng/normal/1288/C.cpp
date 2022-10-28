#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<long long>> memo(m + 1, vector<long long>(n + 1));
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0) {
                memo[i][j] = 1;
            }
            else if (j == 0) {
                memo[i][j] = 0;
            }
            else {
                memo[i][j] = (memo[i-1][j] + memo[i][j-1]) % MOD;
            }
        }
    }

    int sol = 0;
    for (int i = 1; i <= n; i++) {
        sol = (sol + (memo[m-1][i] * memo[m][n-i+1]) % MOD) % MOD;
    }
    cout << sol;
}