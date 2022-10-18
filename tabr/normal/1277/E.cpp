#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)

vector<vector<int>> g;
vector<bool> ga, gb;
int a, b;

void dfsa(int v, int p = -1) {
    ga[v] = true;
    if (v == b)
        return;
    for (auto u : g[v])
        if (u != p && ga[u] == false) {
            dfsa(u, v);
        }
}
void dfsb(int v, int p = -1) {
    gb[v] = true;
    if (v == a)
        return;
    for (auto u : g[v])
        if (u != p && gb[u] == false) {
            dfsb(u, v);
        }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m >> a >> b;
        g.clear();
        ga.clear();
        gb.clear();
        g.resize(n + 1);
        ga.resize(n + 1, false);
        gb.resize(n + 1, false);
        rep(i, 0, m) {
            int x, y;
            cin >> x >> y;
            g[x].emplace_back(y);
            g[y].emplace_back(x);
        }
        dfsa(a, -1);
        dfsb(b, -1);
        ll aa = 0, bb = 0;
        rep(i, 1, n + 1) {
            if (ga[i] == true && gb[i] == false)
                aa++;
            if (gb[i] == true && ga[i] == false)
                bb++;
        }
        cout << aa * bb << endl;
    }
    return 0;
}