#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 10;
int a[maxn][maxn], n, m;

struct solver {
    vector<vector<int>> v, s;
    int n, m;
    void init(int _n, int _m) {
        n = _n; m = _m;
        v = vector<vector<int>>(n + 1, vector<int>(m + 1));
        s = vector<vector<int>>(n + 1, vector<int>(m + 1));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) v[i][j] = a[i][j];
        }
        for (int j = 1; j <= m; ++j) {
            for (int i = 1; i <= n; ++i) {
                if (v[i][j] == 1) s[i][j] = s[i - 1][j] + 1;
                else s[i][j] = 0;
            }
        }
    }
    void modify(int x, int y) {
        v[x][y] = 1 - v[x][y];
        for (int i = 1; i <= n; ++i) {
            if (v[i][y] == 1) s[i][y] = s[i - 1][y] + 1;
            else s[i][y] = 0;
        }
    }
    int query(int x, int y) {
        int ret = 0;
        int lptr = y, rptr = y;
        for (int h = n; h >= 0; --h) {
            while (lptr >= 1 && s[x][lptr] >= h) --lptr;
            while (rptr <= m && s[x][rptr] >= h) ++rptr;
            ret = max(ret, h * (rptr - lptr - 1));
        }
        return ret;
    }
} solve[4];

void rotate(int n, int m) {
    vector<vector<int>> na(maxn, vector<int>(maxn));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            na[i][j] = a[j][m - i + 1];
        }
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) a[i][j] = na[i][j];
    }
}

pair<int, int> get(int i, int x, int y) {
    if (i == 0) return make_pair(x, y);
    if (i == 1) return make_pair(m - y + 1, x);
    if (i == 2) return make_pair(n - x + 1, m - y + 1);
    if (i == 3) return make_pair(y, n - x + 1);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int q; cin >> n >> m >> q;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) cin >> a[i][j];
    }
    for (int i = 0; i < 4; ++i) {
        if (i & 1) solve[i].init(m, n), rotate(m, n);
        else solve[i].init(n, m), rotate(n, m);
    } 
    while (q--) {
        int t, x, y; cin >> t >> x >> y;
        int ans = 0;
        for (int i = 0; i < 4; ++i) {
            int tx, ty;
            tie(tx, ty) = get(i, x, y);
            if (t == 1) solve[i].modify(tx, ty);
            else ans = max(ans, solve[i].query(tx, ty));
        }
        if (t == 2) cout << ans << endl;
    }
    return 0;
}