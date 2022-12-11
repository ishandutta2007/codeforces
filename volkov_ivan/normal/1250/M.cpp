#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 5e5 + 7;
vector <int> g[N];
pair <int, int> p[N];
int c[N];
bool used[N];
bool vis[N];

signed main() {
    memset(vis, 0, sizeof(vis));
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("Desktop/input.txt", "r", stdin);
    int n, m; 
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 0; i < n; i++) {
        cin >> p[i].first;
        p[i].second = i + 1;
        c[i + 1] = p[i].first;
    }
    sort(p, p + n);
    for (int i = 0; i < n; i++) {
        int cc = p[i].first, v = p[i].second;
        //cout << i << ' ' << v << ' ' << cc << endl;
        for (int j = 1; j < cc; j++) used[j] = 0;
        for (int u : g[v]) {
            if (vis[u]) {
                if (c[u] == cc) {
                    cout << -1 << endl;
                    return 0;
                }
                if (c[u] < cc) {
                    used[c[u]] = 1;
                }
            }
        }
        for (int j = 1; j < cc; j++) {
            if (!used[j]) {
                cout << -1 << endl;
                return 0;
            }
        }
        vis[v] = 1;
    }
    for (int i = 0; i < n; i++) cout << p[i].second << ' ';
    cout << endl;
    return 0;
}