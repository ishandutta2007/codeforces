#include <bits/stdc++.h>
#define int long long 

using namespace std;

const int N = 1007;
char f[N][N];
bool vis[N][N];
int n, m;

bool ok(int x, int y) {
    return (x >= 0 && y >= 0 && x < n && y < m && !vis[x][y] && f[x][y] == '#');
}

void dfs(int x, int y) {
    if (!ok(x, y)) return;
    vis[x][y] = 1;
    dfs(x - 1, y);
    dfs(x + 1, y);
    dfs(x, y - 1);
    dfs(x, y + 1);
}

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> f[i][j];
        }
    }
    bool empt_gor = 0, empt_vert = 0;
    for (int i = 0; i < n; i++) {
        int state = 0;
        int cnt = 0;
        for (int j = 0; j < m; j++) {
            if (f[i][j] == '#') cnt++;
            if (state == 2 && f[i][j] == '#') state = 3;
            if (state == 1 && f[i][j] == '.') state = 2;
            if (state == 0 && f[i][j] == '#') state = 1;
        }
        if (cnt == 0) empt_gor = 1;
        if (state == 3) {
            cout << -1 << endl;
            return 0;
        }
    }
    for (int j = 0; j < m; j++) {
        int state = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (f[i][j] == '#') cnt++;
            if (state == 2 && f[i][j] == '#') state = 3;
            if (state == 1 && f[i][j] == '.') state = 2;
            if (state == 0 && f[i][j] == '#') state = 1;
        }
        if (cnt == 0) empt_vert = 1;
        if (state == 3) {
            cout << -1 << endl;
            return 0;
        }
    }
    if (empt_gor && !empt_vert) {
        cout << -1 << endl;
        return 0;
    }
    if (!empt_gor && empt_vert) {
        cout << -1 << endl;
        return 0;
    }
    int res = 0;
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (f[i][j] == '#' && !vis[i][j]) {
                res++;
                dfs(i, j);
            }
        }
    }
    cout << res << endl;
    return 0; 
}