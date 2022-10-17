#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//#define int ll

struct DSU {
    vector<int> p, sz;
    DSU(int n) {
        p.resize(n + 1);
        iota(p.begin(), p.end(), 0);
        sz.resize(n + 1, 1);
    }
    int find(int v) {
        return p[v] == v ? v : p[v] = find(p[v]);
    }
    bool merge(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) {
            return false;
        }
        if (sz[a] < sz[b]) {
            swap(a, b);
        }
        p[b] = a;
        sz[a] += sz[b];
        return true;
    }
};

const int N = 2e5 + 10;
int t[4 * N];

void build(int v, int l, int r, vector<int> &val) {
    if (l == r) {
        t[v] = val[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * v, l, mid, val);
    build(2 * v + 1, mid + 1, r, val);
    t[v] = max(t[2 * v], t[2 * v + 1]);
}

int get_max(int v, int l, int r, int a, int b) {
    if (l > b || r < a) {
        return 0;
    }
    if (l >= a && r<= b) {
        return t[v];
    }
    int mid = (l + r) / 2;
    return max(get_max(2 * v, l, mid, a, b), get_max(2 * v + 1, mid + 1, r, a, b));
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef PC
    freopen("input.txt", "r", stdin);
#endif
    int T;
    cin >> T;
    while (T--) {
        int n, m, q;
        cin >> n >> m >> q;
        vector<pair<int, int>> edges(m);
        for (auto &it : edges) {
            cin >> it.first >> it.second;
        }
        vector<int> L(n, 0), R(n, m);
        for (int iter = 0; iter < 20; iter++) {
            vector<vector<int>> check(m + 1);
            for (int i = 1; i < n; i++) {
                check[(L[i] + R[i]) / 2].push_back(i);
            }
            DSU kek(n);
            for (int j = 1; j <= m; j++) {
                kek.merge(edges[j - 1].first, edges[j - 1].second);
                for (auto i : check[j]) {
                    if (kek.find(i) == kek.find(i + 1)) {
                        R[i] = j;
                    } else {
                        L[i] = j;
                    }
                }
            }
        }
        build(1, 1, n - 1, R);
        for (int i = 0; i < q; i++) {
            int l, r;
            cin >> l >> r;
            cout << get_max(1, 1, n - 1, l, r - 1) << '\n';
        }
        cout << '\n';
    }
    return 0;
}