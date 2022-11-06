#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
long long s[maxn], dp[4][maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        int a; cin >> a;
        s[i] = s[i - 1] + a;
    }
    if (s[n] % 3) return cout << "0" << endl, 0;
    map<int, long long> m;
    dp[0][0] = 1;
    int tar = s[n] / 3;
    for (int i = 1; i <= 3; ++i) {
        m.clear();
        for (int j = 0; j <= n; ++j) {
            dp[i][j] = m[s[j] - tar];
            m[s[j]] += dp[i - 1][j];
        }
    }
    cout << dp[3][n] << endl;
    return 0;
}