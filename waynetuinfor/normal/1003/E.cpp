#include <bits/stdc++.h>
using namespace std;

const int maxn = 4e5 + 5;
int deg[maxn], p[20][maxn], dep[maxn];

int lca(int a, int b) {
    if (dep[a] > dep[b]) swap(a, b);
    for (int i = 0; i < 20; ++i) if ((dep[b] - dep[a]) >> i & 1) b = p[i][b];
    if (a == b) return a;
    for (int i = 19; i >= 0; --i) {
        if (p[i][a] != p[i][b]) a = p[i][a], b = p[i][b];
        if (a == b) return a;
    }
    return p[0][a];
}

int main() {
    int n, d, k; cin >> n >> d >> k;
    if (d + 1 > n) {
        cout << "NO" << endl;
        return 0;
    }
    if (k == 1) {
        if (n == 2 && d == 1) cout << "YES\n1 2\n";
        else cout << "NO" << endl;
        return 0;
    }
    vector<pair<int, int>> ed;
    for (int i = 1; i <= d; ++i) ed.emplace_back(i, i + 1), ++deg[i], ++deg[i + 1];
    int a = 1, b = d + 1;
    set<pair<int, int>> s;
    for (int i = 2; i <= d + 1; ++i) p[0][i] = i - 1, dep[i] = i - 1;
    for (int j = 1; j < 20; ++j) {
        for (int i = 2; i <= d + 1; ++i) {
            if ((1 << j) > dep[i]) continue;
            p[j][i] = p[j - 1][p[j - 1][i]];
        }
    }
    for (int i = 2; i <= d; ++i) s.insert(make_pair(deg[i], i));
    for (int i = d + 2; i <= n; ++i) {
        if (s.size() == 0) {
            cout << "NO" << endl;
            return 0;
        }
        int dg, x; tie(dg, x) = *s.begin();
        if (dg + 1 > k) {
            cout << "NO" << endl;
            return 0;
        }
        s.erase(make_pair(dg, x));
        ++deg[x], ++deg[i];
        ed.emplace_back(x, i);
        p[0][i] = x; 
        dep[i] = dep[x] + 1;
        for (int j = 1; j < 20; ++j) {
            if ((1 << j) > dep[i]) continue;
            p[j][i] = p[j - 1][p[j - 1][i]];
        }
        int da = dep[a] + dep[i] - 2 * dep[lca(a, i)];
        int db = dep[b] + dep[i] - 2 * dep[lca(b, i)];
        if (da > d) {
            cout << "NO" << endl;
            return 0;
        }
        if (db > d) {
            cout << "NO" << endl;
            return 0;
        }
        if (deg[x] < k) s.insert(make_pair(deg[x], x));
        if (da < d && db < d) if (deg[i] < k) s.insert(make_pair(deg[i], i));
    }
    cout << "YES" << endl;
    for (int i = 0; i < ed.size(); ++i) cout << ed[i].first << ' ' << ed[i].second << endl;
}