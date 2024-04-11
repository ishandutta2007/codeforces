#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (int)1e9
#define mod 998244353
#define maxn 4010
#define maxc 26

struct fenwick {
    vector<int> fn;

    fenwick(): fn({}) {
        int i;
        fn.resize(maxn);
        for (i = 0; i < maxn; i++) fn[i] = INF;
    }

    void upd(int p, int x) {
        while (p < maxn) {
            fn[p] = min(fn[p], x); p += (p & (-p));
        }
    }

    int pm(int p) {
        int r = INF;
        while (p > 0) {
            r = min(r, fn[p]); p -= (p & (-p));
        }
        return r;
    }
};

int i, i1, j, k, k1, tc, n, m, res, flag[10], a, b;
int ti, td, tr, ts, dp[maxn][maxn];
fenwick sp[maxc][maxc];
string s, t;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> ti >> td >> tr >> ts >> s >> t;
    n = s.size(); m = t.size(); s = '#' + s; t = '#' + t;

    for (i = 0; i <= n; i++) {
        for (j = 0; j <= m; j++) {
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;

    for (i = 0; i <= n; i++) {
        for (j = 0; j <= m; j++) {
            if (abs(i * m - j * n) >= 800000) continue;

            // cout << "i, j =" _ i _ j << nf;
            if (i >= 1 && j >= 1) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + tr * (s[i] != t[j]));
            }
            if (i >= 1) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + td);
            }
            if (j >= 1) {
                dp[i][j] = min(dp[i][j], dp[i][j - 1] + ti);
            }
            if (i >= 2 && j >= 2) {
                a = (int)s[i] - 'a'; b = (int)t[j] - 'a';
                // cout << "a, b, sp" _ a _ b _ sp[b][a] << nl;
                dp[i][j] = min(dp[i][j], sp[b][a].pm(j - 1) + (i - 1) * td + (j - 1) * ti + ts);
            }
        }

        if (i == 0) continue;
        for (j = 1; j <= m; j++) {
            a = (int)s[i] - 'a'; b = (int)t[j] - 'a';
            sp[a][b].upd(j, dp[i - 1][j - 1] - i * td - j * ti);
        }
    }

    /* for (i = 0; i <= n; i++) {
        for (j = 0; j <= m; j++) {
            cout << dp[i][j] << ' ';
        }
        cout << nl;
    } */

    cout << dp[n][m] << nl;

    return 0;
}