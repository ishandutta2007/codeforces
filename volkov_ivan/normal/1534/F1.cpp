#include <bits/stdc++.h>
//#define int long long

using namespace std;

const int N = 4e5 + 7;
vector <int> g[N];
vector <int> gprime[N];
bool vis[N];
int color[N];
vector <int> sorted;

void dfs0(int v) {
    vis[v] = 1;
    for (int u : g[v]) {
        if (!vis[u])
            dfs0(u);
    }
    sorted.push_back(v);
}

void dfs(int v, int c) {
    color[v] = c; 
    for (int u : gprime[v]) {
        if (color[u] == -1) {
            dfs(u, c);
        }
    }
}

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector <vector <char>> v(n, vector <char>(m));
    vector <vector <int>> num(n, vector<int>(m, -1));
    int cur = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
            if (v[i][j] == '#')
                num[i][j] = cur++;
        }
    }
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] != '#')
                continue;
            int a = num[i][j];
            if (i != 0 && v[i - 1][j] == '#')
                g[a].push_back(num[i - 1][j]); 
            if (j != 0 && v[i][j - 1] == '#')
                g[a].push_back(num[i][j - 1]);
            if (j != m - 1 && v[i][j + 1] == '#')
                g[a].push_back(num[i][j + 1]);
            for (int k = i + 1; k < n; k++) {
                if (v[k][j] == '#') {
                    g[a].push_back(num[k][j]);
                    break;
                }
                if (j != 0 && v[k][j - 1] == '#')
                    g[a].push_back(num[k][j - 1]);
                if (j != m - 1 && v[k][j + 1] == '#')
                    g[a].push_back(num[k][j + 1]);
            }
        }
    }
    //cout << g[1].size() << endl;
    for (int i = 0; i < cur; i++) {
        for (int u : g[i]) {
            gprime[u].push_back(i);
        }
        color[i] = -1;
        vis[i] = 0;
    }
    for (int i = 0; i < cur; i++) {
        if (!vis[i])
            dfs0(i);
    }
    reverse(sorted.begin(), sorted.end());
    int cc = 0;
    for (int elem : sorted) {
        if (color[elem] == -1) {
            dfs(elem, cc++);
        }
    }
    vector <bool> used(cc, 0);
    for (int i = 0; i < cur; i++) {
        for (auto u : g[i]) {
            //cout << i << ' ' << u << ' ' << color[i] << ' ' << color[u] << endl;
            if (color[u] != color[i])
                used[color[u]] = 1;
        }
    }
    int ans = 0;
    for (int i = 0; i < cc; i++) {
        if (!used[i])
            ans++;
    }
    cout << ans << endl;
    return 0;
}