#include<bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
#define LL long long
#define pii pair <int, int>
#define xx first
#define yy second
using namespace std;

const int N = 66666, M = 300, INF = 0x3f3f3f3f;

int dp[N][M], s[20][5], a[20], b[20];

inline void up (int &a, int b) {
    a = max (a, b);
}

int main () {
//    freopen ("in.txt", "r", stdin);
    int n, sa = 0, sb = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf ("%s%d%d", &s[i], &a[i], &b[i]);
        sa += a[i];
        sb += b[i];
    }
    memset (dp, -1, sizeof dp);
    dp[0][0] = 0;
    for (int i = 0; i < (1 << n); i++) {
        int ca = 0, cb = 0, ta = 0, tb = 0;
        for (int k = 0; k < n; k++) if (i & (1 << k)) {
            if (s[k][0] == 'R') ca++; else cb++;
            ta += a[k];
            tb += b[k];
        }
        for (int j = 0; j < M; j++) if (dp[i][j] != -1) {
//            cout << i << ' ' << j << ' ' << dp[i][j] << endl;
//            int nn = max (max (ta - j, tb - dp[i][j]), 0);
            for (int k = 0; k < n; k++) if ((i & (1 << k)) == 0) {
//                cout << i << ' ' << j << ' ' << k << ' ' << j + a[k] - max (a[k] - ca, 0) << ' ' << b[k] << ' ' << ca << ' ' << cb << endl;
                up (dp[i | (1 << k)][j + a[k] - max (a[k] - ca, 0)], dp[i][j] + b[k] - max (b[k] - cb, 0));
            }
        }
    }
    int r = INF;
    for (int i = 0; i < M; i++) if (dp[(1 << n) - 1][i] != -1) {
//        cout << i << ' ' << dp[(1 << n) - 1][i] << endl;
        r = min (r, max (sa - i, sb - dp[(1 << n) - 1][i]) + n);
    }
    cout << r << endl;
}