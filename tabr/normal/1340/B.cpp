#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<string> s(n);
    vector<string> a = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
    vector<vector<int>> c(n, vector<int>(10));
    vector<vector<bool>> dp(n + 1, vector<bool>(k + 1));
    dp[n][0] = true;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        for (int j = 0; j < 10; j++) {
            for (int l = 0; l < 7; l++) {
                if (a[j][l] == '0' && s[i][l] == '1') {
                    c[i][j] = 10;
                    break;
                } else if (a[j][l] == '1' && s[i][l] == '0') {
                    c[i][j]++;
                }
            }
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < 10; j++) {
            if (c[i][j] == 10) continue;
            for (int l = 0; l <= k - c[i][j]; l++) {
                if (dp[i + 1][l]) {
                    dp[i][l + c[i][j]] = true;
                }
            }
        }
    }
    if (!dp[0][k]) {
        cout << -1 << '\n';
        return 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 9; j >= 0; j--) {
            if (c[i][j] == 10 || k - c[i][j] < 0) continue;
            if (dp[i + 1][k - c[i][j]]) {
                k -= c[i][j];
                cout << j;
                break;
            }
        }
    }
    cout << '\n';
    return 0;
}