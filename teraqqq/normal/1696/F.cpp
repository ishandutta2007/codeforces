#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;
using vi = vector<int>;

void no() {
    cout << "No" << endl;
}

void dfs(int v, int h, int p, const vector<vi>& go, vector<vi>& buckets) {
    buckets[h].push_back(v);
    for (int to : go[v]) {
        if (to == p) continue;
        dfs(to, h+1, v, go, buckets);
    }
}

void solve() {
    int n; cin >> n;
    vector mid(n, vector(n, vector<int>(n)));

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            string s; cin >> s;
            for (int u = 0; u < n; ++u) {
                if (s[u] == '1') mid[i][j][u] = mid[j][i][u] = true;
            }
        }
    }

    vector<int> used(n);
    vector dom(n, vector<int>(n));

    for (int a = 0; a < n; ++a)
    for (int b = 0; b < n; ++b) {
        if (a == b) continue;

        for (int i = 0; i < n; ++i)
        for (int j = 0; j < i; ++j) {
            if (mid[i][j][a] && !mid[i][j][b]) ++dom[a][b];
        }
    }

    vector<int> ord;
    for (int iter = 0; iter < n - 1; ++iter) {
        int v = -1;
        for (int i = 0; i < n; ++i) {
            if (used[i]) continue;
            for (int j = 0; j < n; ++j) {
                if (!used[j] && i != j && dom[i][j] == 0) v = i;
            }
        }

        if (v == -1) return no();

        used[v] = true;
        ord.push_back(v);

        for (int u = 0; u < n; ++u) {
            if (used[u]) continue;
            
            for (int a = 0; a < n; ++a)
            for (int b = 0; b < n; ++b) {
                if (a == b) continue;
                if (mid[u][v][a] && !mid[u][v][b]) --dom[a][b];
            }
        }
    }

    vector<int> deg(n), neighbour(n, -1);
    int sz = 1;

    vector<pi> ans;
    reverse(ord.begin(), ord.end());

    auto add_edge = [&](int a, int b) {
        ans.emplace_back(a, b);
        deg[a]++;
        deg[b]++;
        neighbour[a] = b;
        neighbour[b] = a;
    };

    for (int v : ord) {
        if (sz == 1) {
            for (int i = 0; i < n; ++i) if (used[i] == 0) add_edge(i, v);
        } else {
            for (int i = 0; i < n; ++i) {
                if (used[i]) continue;
                if (mid[neighbour[i]][v][i]) add_edge(i, v);
            }
        }

        used[v] = 0;
        if (ans.size() != sz) return no();
        ++sz;
    }

    vector chk(n, vector(n, vector<int>(n)));

    vector<vi> go(n);
    for (auto [a, b] : ans) go[a].push_back(b), go[b].push_back(a);

    for (int v = 0; v < n; ++v) {
        vector<vi> buckets(n);
        dfs(v, 0, -1, go, buckets);

        for (auto w : buckets) {
            for (int i : w)
            for (int j : w) {
                if (i != j) chk[i][j][v] = true;
            }
        }
    }

    if (chk != mid) return no();

    cout << "Yes" << endl;
    for (auto [a, b] : ans) cout << a+1 << ' ' << b+1 << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}