#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10, inf = 1e9 + 1;
vector<int> a[maxn], st[20][maxn];

void build(int);
vector<int> query(int, int);
pair<bool, vector<int>> check(int, int, int, int);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, k; cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        int x;
        for (int j = 0; j < m; ++j) cin >> x, a[i].push_back(x);
    }
    build(n);
    int d = 1, ans = 0; while (d < inf) d <<= 1;
    vector<int> fin(5, inf);
    while (d >>= 1) if (ans + d < inf) {
        pair<bool, vector<int>> ret = check(ans + d, n, m, k);
        if (ret.first) ans += d, fin = ret.second;
    }
    if (fin[0] == inf) {
        for (int i = 0; i < m; ++i) cout << 0 << ' '; cout << endl;
        return 0;
    }
    for (int i = 0; i < m; ++i) cout << fin[i] << ' '; cout << endl;
    return 0;
}

void build(int n) {
    for (int i = 0; i < 20; ++i) for (int j = 0; j < maxn; ++j) st[i][j] = vector<int>(5, 0);
    for (int i = 1; i <= n; ++i) st[0][i] = a[i];
    for (int i = 1; (1 << i) <= n + 1; ++i) {
        for (int j = 1; j + (1 << i) <= n + 1; ++j) {
            for (int k = 0; k < 5; ++k) st[i][j][k] = max(st[i - 1][j][k], st[i - 1][j + (1 << (i - 1))][k]);
        }
    }
}

vector<int> query(int l, int r) {
    int p = 31 - __builtin_clz(r - l + 1);
    vector<int> ret(5, 0);
    for (int i = 0; i < 5; ++i) ret[i] = max(st[p][l][i], st[p][r - (1 << p) + 1][i]);
    return ret;
}

pair<bool, vector<int>> check(int len, int n, int m, int k) {
    int shot = inf;
    vector<int> ret;
    for (int i = len; i <= n; ++i) {
        int req = 0;
        vector<int> qry = query(i - len + 1, i);
        for (int j = 0; j < m; ++j) req += qry[j];
        if (req < shot) shot = req, ret = qry;
    }
    bool ok = shot <= k;
    return make_pair(ok, ret);
}