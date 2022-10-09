#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

long long i, i1, j, k, k1, n, m, res, check1, a, b, dp[3010][3010], mod;
string s, t, o;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    mod = 998244353;

    cin >> s >> o;
    n = s.size(); m = o.size();
    t = s;
    for (i = 0; i < m; i++) {
        t[i] = o[i];
    }
    for (i = m; i < n; i++) {
        t[i] = '#';
    }

    // cout << s << ' ' << t << endl;

    for (j = 0; j <= n; j++) {
        dp[0][j] = 1;
    }

    for (i = 1; i <= n; i++) {
        for (j = 0; j < n - i + 1; j++) {
            dp[i][j] = 0;
        }
    }

    for (i = 1; i <= n; i++) {
        for (j = 0; j < n - i + 1; j++) {
            if (t[i + j - 1] == '#' || t[i + j - 1] == s[i - 1]) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
            }
            if (t[j] == '#' || t[j] == s[i - 1]) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % mod;
            }
        }
    }

    res = 0;
    for (i = m; i <= n; i++) {
        res = (res + dp[i][0]) % mod;
    }

    /* for (i = 0; i <= n; i++) {
        for (j = 0; j < n - i + 1; j++) {
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    } */

    cout << res;

    return 0;
}