#include <bits/stdc++.h>
#define LL long long
#define pii pair <int, int>
#define xx first
#define yy second
using namespace std;

const int N = 5010, mod = 1e9 + 7;

int dp[N][N], sum[N][N], len[N][N];
char s[N];
int n;

inline void add (int &a, int b) {
    a += b;
    if (a >= mod) a -= mod;
//    return a;
}

int getlen (int x, int y) {
    if (len[x][y] != -1) return len[x][y];
    if (x > n || y > n || s[x] != s[y]) return len[x][y] = 0;
    return len[x][y] = getlen (x + 1, y + 1) + 1;
}

int main () {
//    freopen ("in.txt", "r", stdin);
//    cout << sizeof (dp) / 1024 * 3 / 1024;
    memset (len, -1, sizeof len);
//    int n;
    cin >> n;
    scanf ("%s", s + 1);
//    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) if (s[i - j + 1] != '0') {
            if (i == j) {
                dp[i][j] = 1;
//                continue;
            } else {
                dp[i][j] = sum [i - j][j - 1];
//                if(i == 6 && j == 4) cout << dp[i - j][]
                int x = i - 2 * j + 1;
                int y = i - j + 1;
                if (x > 0 && s[x] != '0') {
                    int l = getlen (x, y);
                    if (l < j && s[x + l] < s[y + l]) {
                        add (dp[i][j], dp[i - j][j]);
//                        cout << i <<' ' << j << ' ' << dp[i - j][j] << endl;
                    }
//                    cout << i << ' ' << j << ' ' << dp[i][j] << ' ' << x << ' ' << y << ' ' << getlen (x, y) << ' ' << (int)s[x + l] << ' ' << (int)s[y + l] << endl;
                }
            }
//            if (s[i + 1] != '0') add (sum[i][j], dp[i][j]);
        }
        for (int j = 1; j <= n; j++) {
//            if (s[i + 1] != '0')
            sum[i][j] = sum[i][j - 1] + dp[i][j];
            sum[i][j] %= mod;
//            else sum[i][j] = sum[i][j - 1];
        }
    }
//    cout << getlen (1, 2) << endl;
//    cout <<dp[2][1] << ' ' << sum[2][3] << endl;
    int res = 0;
    for (int i = 1; i <= n; i++) {
//        cout << dp[n][i] << endl;
        add (res, dp[n][i]);
    }
    cout << res << endl;
}