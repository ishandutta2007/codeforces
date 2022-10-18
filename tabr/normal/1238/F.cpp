#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)

vector<vector<int>> g;
int ans = 0;
vector<int> sub;

void dfs(int v, int p) {
    sub[v] = 1;
    int a = 0, b = 0;
    for (auto u : g[v])
        if (u != p) {
            dfs(u, v);
            sub[v] = max(sub[v], sub[u] + (int)g[v].size() - 1 + (p == -1));
            if (sub[u] > a) {
                b = a;
                a = sub[u];
            } else if (sub[u] > b) {
                b = sub[u];
            }
        }
    ans = max(ans, a + b + (int)g[v].size() - 1);
    ans = max(ans, sub[v]);
}

int main() {
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        ans = 0;
        sub.clear();
        sub.resize(n, 1);
        g.clear();
        g.resize(n);
        rep(i, 1, n) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            g[x].emplace_back(y);
            g[y].emplace_back(x);
        }

        dfs(0, -1);
        cout << ans << endl;
    }
}