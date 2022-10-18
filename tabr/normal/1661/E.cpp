#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

struct dsu {
    vector<int> p;
    vector<int> sz;
    int n;

    dsu(int _n) : n(_n) {
        p = vector<int>(n);
        iota(p.begin(), p.end(), 0);
        sz = vector<int>(n, 1);
    }

    inline int get(int x) {
        if (p[x] == x) {
            return x;
        } else {
            return p[x] = get(p[x]);
        }
    }

    inline bool unite(int x, int y) {
        x = get(x);
        y = get(y);
        if (x == y) {
            return false;
        }
        p[x] = y;
        sz[y] += sz[x];
        return true;
    }

    inline bool same(int x, int y) {
        return (get(x) == get(y));
    }

    inline int size(int x) {
        return sz[get(x)];
    }

    inline bool root(int x) {
        return (x == get(x));
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<string> s(3);
    for (int i = 0; i < 3; i++) {
        cin >> s[i];
    }
    vector<int> w(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            w[i] += (s[j][i] - '0') << j;
        }
    }
    dsu uf(3 * n);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            if (s[i][j] == '1' && s[i + 1][j] == '1') {
                uf.unite(i * n + j, i * n + j + n);
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (s[i][j] == '1' && s[i][j + 1] == '1') {
                uf.unite(i * n + j, i * n + j + 1);
            }
        }
    }
    vector<pair<int, int>> b;
    for (int i = 0, j = 0; i < n; i = j) {
        if (s[0][i] != '1' || s[1][i] != '0' || s[2][i] != '1') {
            j = i + 1;
            continue;
        }
        while (j < n && s[0][i] == s[0][j] && s[1][i] == s[1][j] && s[2][i] == s[2][j]) {
            j++;
        }
        if (uf.same(i, i + n * 2)) {
            b.emplace_back(i, j - 1);
        }
    }
    vector<pair<int, int>> a;
    vector<vector<int>> t(3 * n);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            if (s[i][j] == '1') {
                t[uf.get(i * n + j)].emplace_back(j);
            }
        }
    }
    for (int i = 0; i < 3 * n; i++) {
        if (t[i].empty()) {
            continue;
        }
        sort(t[i].begin(), t[i].end());
        a.emplace_back(t[i][0], t[i].back());
    }
    vector<int> pref(n + 1);
    for (auto p : a) {
        pref[p.second + 1]++;
    }
    for (int i = 0; i < n; i++) {
        pref[i + 1] += pref[i];
    }
    vector<int> suf(n + 1);
    for (auto p : a) {
        suf[p.first]++;
    }
    for (int i = n - 1; i >= 0; i--) {
        suf[i] += suf[i + 1];
    }
    vector<int> nxt(n);
    for (int i = n - 2; i >= 0; i--) {
        if (w[i] == w[i + 1]) {
            nxt[i] = nxt[i + 1];
        } else {
            nxt[i] = w[i + 1];
        }
    }
    vector<int> pre(n);
    for (int i = 1; i < n; i++) {
        if (w[i] == w[i - 1]) {
            pre[i] = pre[i - 1];
        } else {
            pre[i] = w[i - 1];
        }
    }
    sort(b.begin(), b.end());
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        int ans = (int) a.size() - (pref[l] + suf[r + 1]);
        auto iter = upper_bound(b.begin(), b.end(), make_pair(l + 1, -1));
        if (iter != b.begin()) {
            iter--;
            if (iter->first <= l && l <= iter->second && nxt[l] != 7) {
                ans++;
            }
            if (iter->first <= l && r <= iter->second) {
                cout << 2 << '\n';
                continue;
            }
        }
        iter = upper_bound(b.begin(), b.end(), make_pair(r + 1, -1));
        if (iter != b.begin()) {
            iter--;
            if (iter->first <= r && r <= iter->second && pre[r] != 7) {
                ans++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}