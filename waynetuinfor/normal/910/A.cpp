#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 10, inf = 1e9 + 1;
int dp[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, d; cin >> n >> d;
    string s; cin >> s;
    s = '.' + s;
    fill(dp, dp + maxn, inf);
    dp[1] = 0;
    for (int i = 2; i <= n; ++i) if (s[i] == '1') {
        for (int j = 1; j <= d; ++j) if (i - j >= 1) dp[i] = min(dp[i], dp[i - j] + 1);
    }
    cout << (dp[n] == inf ? -1 : dp[n]) << endl;
}