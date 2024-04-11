#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define pii pair <int, int>
#define xx first
#define yy second
using namespace std;

const int N = 100010;

char s[3][N];
int dp[3][N];

int jug (char s) {
    if (s == 0 || s == '.') return 1;
    return 0;
}

int main () {
//    freopen ("in.txt", "r", stdin);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        memset (s, 0, sizeof s);
        memset (dp, 0, sizeof dp);
        for (int i = 0; i < 3; i++) scanf ("%s", s[i]);
        for (int i = 0; i < 3; i++) if (s[i][0] == 's') dp[i][0] = 1;
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < 3; j++) if (dp[j][i]) {
                if (jug (s[j][3 * i + 1])) {
                    if (jug (s[j][3 * i + 2]) && jug (s[j][3 * i + 3])) dp[j][i + 1] = 1;
                    if (j > 0 && jug (s[j - 1][3 * i + 1]) && jug (s[j - 1][3 * i + 2]) && jug (s[j - 1][3 * i + 3])) dp[j - 1][i + 1] = 1;
                    if (j < 2 && jug (s[j + 1][3 * i + 1]) && jug (s[j + 1][3 * i + 2]) && jug (s[j + 1][3 * i + 3])) dp[j + 1][i + 1] = 1;
                }
            }
        }
        int res = 0;
        for (int i = 0; i < 3; i++) if (dp[i][n - 1]) res = 1;
        if (res) cout << "YES\n";
        else cout << "NO\n";
    }
}