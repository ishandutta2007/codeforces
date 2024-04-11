#include <bits/stdc++.h>
#define int long long 

using namespace std;

const int N = 2e5 + 7;
vector <int> g[N], gp[N];
int color[N];
char res[N];
bool vis[N], visp[N];

void dfs0(int v) {
    color[v] = 1;
    for (int u : g[v]) {
        if (color[u] == 1) {
            cout << -1 << endl;
            exit(0);
        }
        if (color[u] == 0) dfs0(u);
    }    
    color[v] = 2;
}

void dfs1(int v) {
    vis[v] = 1;
    for (int u : g[v]) {
        if (!vis[u]) dfs1(u); 
    }
}

void dfs2(int v) {
    visp[v] = 1;
    for (int u : gp[v]) {
        if (!visp[u]) dfs2(u);
    }
}

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    memset(vis, 0, sizeof(vis));
    memset(visp, 0, sizeof(visp));
    memset(color, 0, sizeof(color));
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        gp[y].push_back(x);
    }
    for (int i = 1; i <= n; i++) {
        if (color[i] == 0) dfs0(i);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i] && !visp[i]) {
            res[i] = 'A';
            ans++;
        } else {
            res[i] = 'E';
        }
        if (!vis[i]) dfs1(i);
        if (!visp[i]) dfs2(i);
    }
    cout << ans << endl;
    for (int i = 1; i <= n; i++) cout << res[i];
    cout << endl;

    return 0; 
}