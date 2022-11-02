#include <bits/stdc++.h>
#define LL long long
#define pii pair <LL, LL>
#define xx first
#define yy second
#define ULL unsigned long long
using namespace std;

const int N = 4010, mod = 1e9 + 7;

int dp[N][N];
char s[100100];

inline void add (int &a, int b) {
    a += b;
    if (a >= mod) a -= mod;
}

int getdp (int i, int j) {
    if (j < 0 || i - j < 0) return 0;
    return dp[i - j][j];
}

int main () {
//    freopen ("in.txt", "r", stdin);
    dp[0][0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) if (i || j) {
            if (i == j) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % mod;
        }
    }
//    cout << dp[3][1] << endl;
    int n, m, flag = 0, c = 0, mn = 0;
    cin >> n >> m;
    if (n & 1) {
        cout << 0 << endl;
        return 0;
    }
    scanf ("%s", s);
    for (int i = 0; i < m; i++) {
        if (s[i] == '(') c++;
        else {
//            if (c == 0) flag = 1;
            c--;
        }
        mn = min (mn, c);
    }
//    if (flag) cout << 0 << endl;
    int r = 0;
    int lim = n - m;
    for (int i = 0; i <= lim; i++) {
        for (int j = 0; j <= i; j++) if (j >= i - j && 2 * j - i >= -mn) {
            int k = lim - i, l = 2 * j - i + c;
            l += (k - l) / 2;
//            cout << i << ' ' <<j << ' ' << k << ' ' << l << endl;
//            cout << getdp (i, j) << ' ' << getdp (k, l) << endl;
            add (r, 1LL * getdp (i, j) * getdp (k, l) % mod);
        }
    }
    cout << r << endl;
}