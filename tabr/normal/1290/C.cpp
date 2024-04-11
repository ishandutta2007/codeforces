#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

struct unionfind {
    vector<int> p;
    vector<int> sz;
    vector<int> col;
    vector<vector<int>> val;
    int n, ans = 0;
    unionfind(int _n)
        : n(_n) {
        p.resize(n);
        iota(p.begin(), p.end(), 0);
        sz.assign(n, 1);
        col.assign(n, -1);
        val.resize(2);
        val[0].resize(n);
        val[1].resize(n);
    }

    inline int get(int x) {
        if (p[x] == x) {
            return x;
        } else {
            return p[x] = get(p[x]);
        }
    }
    int eval(int x) {
        x = get(x);
        if (x == get(n - 1)) {
            return val[1][x];
        } else {
            return min(val[0][x], val[1][x]);
        }
    }
    inline bool unite(int x, int y) {
        x = get(x);
        y = get(y);
        if (x == y) {
            return false;
        }
        ans -= eval(x) + eval(y);
        p[x] = y;
        sz[y] += sz[x];
        for (int i = 0; i < 2; i++) {
            val[i][y] += val[i][x];
        }
        ans += eval(y);
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    string ss;
    cin >> ss;
    vector<int> s(n);
    for (int i = 0; i < n; i++) {
        s[i] = ss[i] - '0';
    }
    vector<vector<int>> x(n);
    vector<vector<pair<int, int>>> e(k + 1);
    for (int i = 0; i < k; i++) {
        int c;
        cin >> c;
        for (int j = 0; j < c; j++) {
            int t;
            cin >> t;
            t--;
            x[t].emplace_back(i);
        }
    }
    unionfind d(k + 1);
    for (int i = 0; i < n; i++) {
        if (x[i].empty()) continue;
        if (x[i].size() == 1) {
            x[i].emplace_back(k);
        }
        int a = x[i][0], b = x[i][1], c = 1 ^ s[i];
        e[a].emplace_back(b, c);
        e[b].emplace_back(a, c);
    }
    function<void(int)> dfs = [&](int v) {
        for (auto to : e[v]) {
            if (d.col[to.first] != -1) continue;
            d.col[to.first] = d.col[v] ^ to.second;
            dfs(to.first);
        }
    };
    for (int i = k; i >= 0; i--) {
        if (d.col[i] == -1) {
            d.col[i] = 0;
            dfs(i);
        }
        d.val[d.col[i]][i]++;
    }
    for (int i = 0; i < n; i++) {
        if (x[i].size()) {
            d.unite(x[i][0], x[i][1]);
        }
        cout << d.ans << endl;
    }
    return 0;
}