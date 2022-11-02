#include <bits/stdc++.h>
#define LL long long
#define pii pair <LL, LL>
#define xx first
#define yy second
#define ULL unsigned long long
using namespace std;

const int N = 2020, mod = 1e9 + 7;

int dp[N][N][2][2][2];
int m, d;
int a[N], an;
char s[N];

inline void add (int &a, int b) {
    a += b;
    if (a >= mod) a -= mod;
}

int dfs (int k, int now, int flag, int one, int eo) {
//    cout << k << ' ' << now << ' ' << flag <<' ' << one << ' ' << eo << endl;
    if (k == an) return now == 0;
    if (dp[k][now][flag][one][eo] != -1) return dp[k][now][flag][one][eo];
    int &res = dp[k][now][flag][one][eo];
    res = 0;
    int e = flag ? 9 : a[k];
//    cout << e << endl;
    for (int i = 0; i <= e; i++) {
        if ((one | (i > 0)) == 1 && eo == 1 && i != d) continue;
        if ((one | (i > 0)) == 1 && eo == 0 && i == d) continue;
        add (res, dfs (k + 1, (now * 10 + i) % m, flag | (i < a[k]), one | (i > 0), (one | (i > 0)) ? eo ^ 1 : 0));
    }
    return res;
}

int solve (int t) {
    scanf ("%s", s);
    an = strlen (s);
    for (int i = 0; i < an; i++) a[i] = s[i] - '0';
    if (t) {
        int n = an - 1;
        while (a[n] == 0) n--;
        a[n]--;
        for (int i = n + 1; i < an; i++) a[i] = 9;
//        if (a[n] == 0) an--;
    }
//    for (int i = 0; i < an; i++) cout << a[i]; cout << endl;
    memset (dp, -1, sizeof dp);
//    cout << dfs (0, 0, 0, 0, 0) << endl;
    return dfs (0, 0, 0, 0, 0);
}

int main () {
//    freopen ("in.txt", "r", stdin);
//    cout << sizeof (dp) / 1024 << endl;
    cin >> m >> d;
    int res = solve (1);
    res = mod - res;
    add (res, solve (0));
    cout << res << endl;
}