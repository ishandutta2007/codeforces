#include <bits/stdc++.h>
using namespace std;

const int maxn = 500 + 10, inf = 1e9 + 1;

struct query {
    int x, y, t;
};

int n, m, k;

bool check(int t, const vector<query>& qry) {
    vector<vector<int>> s(n + 1);
    for (int i = 0; i <= n; ++i) s[i].resize(m + 1);
    for (int i = 0; i < qry.size(); ++i) if (qry[i].t <= t) {
        ++s[qry[i].x][qry[i].y];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
        }
    }
    for (int i = k; i <= n; ++i) {
        for (int j = k; j <= m; ++j) {
            int cnt = s[i][j] - s[i][j - k] - s[i - k][j] + s[i - k][j - k];
            if (cnt == k * k) return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int q; cin >> n >> m >> k >> q;
    vector<query> qry(q);
    for (int i = 0; i < q; ++i) cin >> qry[i].x >> qry[i].y >> qry[i].t;
    int d = 1, ans = inf; while (d < inf) d <<= 1;
    while (d >>= 1) if (ans - d >= 0) if (check(ans - d, qry)) ans -= d;
    if (ans == inf) ans = -1;
    cout << ans << endl;
    return 0;
}