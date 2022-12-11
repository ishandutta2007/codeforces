#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 57;
char f[N][N];
bool vis[N][N];
int n, m;
bool bad = 0;

bool ok(int x, int y) {
    return (x >= 0 && y >= 0 && x < n && y < m && !vis[x][y] && f[x][y] != '#');
}

int dfs(int x, int y) {
    if (!ok(x, y)) return 0;
    int res = 0;
    vis[x][y] = 1;
    if (f[x][y] == 'G') res = 1;
    if (f[x][y] == 'B') bad = 1;
    res += dfs(x - 1, y);
    res += dfs(x + 1, y);
    res += dfs(x, y - 1);
    res += dfs(x, y + 1);
    return res;
}

void solve() {
    bad = 0;
    cin >> n >> m;
    memset(vis, 0, sizeof(vis));
    int need = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> f[i][j];
            if (f[i][j] == 'G') need++;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (f[i][j] == 'B') {
                if (ok(i - 1, j) && f[i - 1][j] == '.') f[i - 1][j] = '#';
                if (ok(i + 1, j) && f[i + 1][j] == '.') f[i + 1][j] = '#';
                if (ok(i, j - 1) && f[i][j - 1] == '.') f[i][j - 1] = '#';
                if (ok(i, j + 1) && f[i][j + 1] == '.') f[i][j + 1] = '#';
            }
        }
    }
    int have = dfs(n - 1, m - 1);
    if (have == need && !bad) cout << "Yes" << endl;
    else cout << "No" << endl;
}

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; 
    cin >> t;
    for (int i = 0; i < t; i++) solve();
}