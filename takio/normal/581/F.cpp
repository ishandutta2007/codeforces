#include <bits/stdc++.h>
#define LL long long
#define pii pair <int, int>
#define xx first
#define yy second

using namespace std;

const int N = 5010;

vector <int> g[N];
int sz[N];
int dp[N][N][2], tmp[N][2];

void dfs (int u, int fa) {
//    cout << u << ' ' <<fa << endl;
    if (g[u].size() == 1) {
        dp[u][0][1] = 0;
        dp[u][1][0] = 0;
        sz[u] = 1;
        return;
    }
    dp[u][0][1] = 0;
    dp[u][0][0] = 0;
    for (int i = 0; i < (int) g[u].size(); i++) {
        int v = g[u][i];
        if (v == fa) continue;
        dfs (v, u);
        memcpy (tmp, dp[u], sizeof tmp);
        memset (dp[u], 0x3f, sizeof dp[u]);
        for (int j = 0; j <= sz[u]; j++) {
            for (int k = 0; k <= sz[v]; k++) {
//                if (u == 1 && j + k == 2) cout << j << ' ' << k << ' ' << tmp[j][0] << ' ' << tmp[j][1] << ' ' << dp[v][k][0] << ' ' << dp[v][k][1] << endl;
                dp[u][j + k][0] = min (dp[u][j + k][0], min (tmp[j][0] + dp[v][k][0], tmp[j][0] + dp[v][k][1] + 1));
                dp[u][j + k][1] = min (dp[u][j + k][1], min (tmp[j][1] + dp[v][k][0] + 1, tmp[j][1] + dp[v][k][1]));
//                if (u == 1 && v == 2 && j == 0 && k == 3) cout << dp[u][j + k][1] << ' ' << u << ' ' << j + k << ' ' << 1 << ' ' << tmp[j][1] << ' ' << dp[v][k][0] << "xxxxxxxxxxxxxxxxxxx" << endl;
//                dp[u][j + k][0] = min (dp[u][j + k][0]);
//                dp[u][j + k][1] = min (dp[u][j + k][1]);
            }
        }
//        cout << dp[u][3][1] << "xasdasdasdasf" << endl;
        sz[u] += sz[v];
//        for (int j = 0; j <= sz[u]; j++) {
//            cout << u << ' ' << j << ' ' << dp[u][j][0] << ' ' << dp[u][j][1] << endl;
//        } cout << endl;
    }
}

int main () {
//    cout << sizeof (dp) / 1024 << endl;
//    freopen ("in.txt", "r", stdin);
    int n;
    cin >> n;
    if (n == 2) { cout << 1; return 0; }
    for (int i = 1; i < n; i++) {
        int x, y;
        scanf ("%d%d", &x, &y);
        g[x].push_back (y);
        g[y].push_back (x);
    }
    memset (dp, 0x3f, sizeof dp);
    int rt;
    for (int i = 1; i <= n; i++) if (g[i].size() != 1) { rt = i; break; }
    dfs (rt, 0);
//    cout << rt << ' ' << sz[rt] << endl;
//    for (int i = 1; i <= n; i++) {
//        for (int j = 0; j <= sz[i]; j++) {
//            cout << i << ' ' << j << ' ' << dp[i][j][0] << ' ' << dp[i][j][1] << endl;
//        }
//    }
    cout << min (dp[rt][sz[rt] / 2][0], dp[rt][sz[rt] / 2][1]);
}