#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

#define _ inline
#define f first
#define sec second
#define pb push_back
#define ins insert
#define ers erase
#define mk make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rsz resize
//#define int ll
#define forn(i, n) for (register int i(1); i <= n; i++)
#define fore(i, n) for (register int i(0); i < n; i++)

#define right rightt
#define left leftt
#define prev prevv
#define next nextt

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const int P = 239017;
const long long BINF = 1e18 + 10;

const int N = 1010;
const int MX = (1 << 12) + 10;

vector<vector<vector<int> > > v;
int calc[5][5], dp[N][MX], arr[N][5], c[5], f[N][5], k1 = 15, k2 = 255, k3 = 4095;
_ void upd(int a, int b, int val) {
    dp[a][b] = min(dp[a][b], val);
}

_ void go(int mask, int val, int ind) {
    int k = ind + 3;
    if ((mask & k3) == k3) {
        upd(ind + 3, f[k][3], val);
    }
    if ((mask & k2) == k2) {
        upd(ind + 2, (mask >> 8) | (f[k][2] * 16), val);
    }
    if ((mask & k1) == k1) {
        upd(ind + 1, (mask >> 4) | (f[k][1] * 256), val);
    }
    upd(ind, mask, val);
}

_ void source() {
    int n;
    cin >> n;
    for (int i = 1; i <= 4; i++) {
        cin >> c[i];
    }
    for (int j = 1; j <= 4; j++) {
        for (int i = 1; i <= n; i++) {
            char ch;
            cin >> ch;
            arr[i][j] = (ch == '.' ? 1 : 0);
            if (arr[i][j]) {
                f[i - 1][1] |= 1 << (j - 1);
            }
        }
    }
    for (int i = 2; i < 4; i++) {
        for (int j = 0; j < n; j++) {
            f[j][i] = f[j][i - 1] + f[j + i - 1][1] * (1 << (4 * (i - 1)));
        }
    }
    v.rsz(5);
    for (int i = 1; i <= 4; i++) {
        v[i].rsz(5);
    }
    for (int i = 1; i <= 4; i++) {
        calc[i][1] = 1 << (i - 1);
    }
    v[1][2] = {0, 1, 4, 5};
    v[1][3] = {0, 1, 2, 4, 5, 6, 8, 9, 10};
    for (auto &it : v[1][2]) {
        calc[1][2] |= (1 << it);
    }
    for (auto &it : v[1][3]) {
        calc[1][3] |= (1 << it);
    }
    calc[2][2] = calc[1][2] * 2;
    calc[3][2] = calc[2][2] * 2;
    calc[2][3] = calc[1][3] * 2;
    int lim = 1 << 12;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < lim; j++) {
            dp[i][j] = INF;
        }
    }
    dp[0][f[0][3]] = 0;
    for (int i = 0; i < n; i++) {
        int k = i + 3;
        for (int mask = 0; mask < lim; mask++) {
            go(mask, dp[i][mask], i);
            if (i + 4 <= n) {
                dp[i + 4][f[i + 4][3]] = min(dp[i + 4][f[i + 4][3]], dp[i][mask] + c[4]);
                dp[i + 3][f[i + 3][3]] = min(dp[i + 3][f[i + 3][3]], dp[i][mask] + c[4]);
                upd(i + 2, (mask >> 8) | (f[k][2] * 16), dp[i][mask] + c[4]);
                upd(i + 1, (mask >> 4) | (f[k][1] * 256), dp[i][mask] + c[4]);
            }
            for (int j = 1; j < 3; j++) {
                go(mask | calc[j][3], dp[i][mask] + c[3], i);
            }
            for (int j = 1; j < 4; j++) {
                go(mask | calc[j][2], dp[i][mask] + c[2], i);
            }
            for (int j = 1; j < 5; j++) {
                go(mask | calc[j][1], dp[i][mask] + c[1], i);
            }
        }
    }
    cout << dp[n][0];
}

signed main() {
#ifdef EXTRATERRESTRIAL_
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
    //freopen(TASK".in", "r", stdin);
    //freopen(TASK".out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    source();
    return 0;
}