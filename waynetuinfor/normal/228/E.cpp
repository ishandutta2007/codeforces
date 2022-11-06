#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 10;
vector<int> ss;

class TwoSat {
    private:
        vector<int> G[maxn << 1];
        bool v[maxn << 1];
        int s[maxn << 1], c;
        bool dfs(int now, int p) {
            if (v[now ^ 1]) return false;
            if (v[now]) return true;
            v[now] = true;
            s[c++] = now;
            for (int u : G[now]) if (u != p && !dfs(u, now)) return false;
            return true;
        }
    public:
        TwoSat() {
            memset(v, false, sizeof(v));
            memset(s, 0, sizeof(s));
            c = 0;
        }
        void add_edge(int a, int b) {
            G[a].push_back(b);
        }
        bool solve() {
            for (int i = 0; i < maxn << 1; i += 2) {
                if (G[i].size()) {
                    c = 0;
                    // cout << "try dfs(" << i << ")" << endl;
                    // memset(v, false, sizeof(v));
                    if (!dfs(i, -1)) {
                        while (c) v[s[--c]] = false;
                        // memset(v, false, sizeof(v));
                        // cout << "try dfs(" << i + 1 << ")" << endl;
                        if (!dfs(i + 1, -1)) return false;
                        else ss.push_back(i + 1);
                    } else ss.push_back(i);
                }
            }
            return true;
        }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    TwoSat t;
    while (m--) {
        int a, b, c; cin >> a >> b >> c;
        if (c == 1) {
            t.add_edge(a << 1, b << 1); t.add_edge(b << 1, a << 1);
            t.add_edge(a << 1 | 1, b << 1 | 1); t.add_edge(b << 1 | 1, a << 1 | 1);
        } else {
            t.add_edge(a << 1, b << 1 | 1); t.add_edge(b << 1 | 1, a << 1);
            t.add_edge(a << 1 | 1, b << 1); t.add_edge(b << 1, a << 1 | 1);
        }
    }
    bool ans = t.solve();
    if (!ans) return cout << "Impossible" << endl, 0;
    vector<int> vec;
    for (int i : ss) {
        if (i & 1) vec.push_back(i / 2);
    }
    cout << vec.size() << endl;
    for (int i : vec) cout << i << ' '; cout << endl;
    return 0;
}