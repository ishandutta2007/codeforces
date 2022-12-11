#include <bits/stdc++.h>

using namespace std;

int n, m;
int d[505][505];
vector <int> candidates;

int cal(int u) {
    int ret = 0;
    for (auto v: candidates) ret += d[u][v];
    return ret;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) d[i][j] = 10000 * (i != j);
    for (int i = 1; i <= m; ++i) {
        int sz, x, y; cin >> sz >> x;
        for (int j = 1; j < sz; ++j) {
            cin >> y;
            d[x][y] = d[y][x] = 1;
            x = y;
        }
    }
    for (int k = 1; k <= n; ++k) for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j)
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    for (int itest = 0; itest < n; ++itest) {
        candidates.clear();
        for (int i = 1; i <= n; ++i) candidates.push_back(i);
        while (1) {
            int id = 1, mn = cal(1);
            for (int i = 2; i <= n; ++i) {
                int op = cal(i);
                if (op < mn) mn = op, id = i;
            }
            cout << id << endl;
            string res; cin >> res;
            if (res == "FOUND") break;
            int u; cin >> u;
            vector <int> nxt_candidates;
            for (auto v: candidates) if (d[u][v] < d[id][v]) nxt_candidates.push_back(v);
            candidates.swap(nxt_candidates);
        }
    }
    return 0;
}