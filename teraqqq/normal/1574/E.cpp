#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;
using ll = long long;

const int N = 1e6;
const int MOD = 998244353;

int n, m, k;
int col[2][N], row[2][N], chess[2];
int bcol, brow, bchs, cnt_col = 1, cnt_row = 1;
map<pi, int> val;

void div2(int& x) {
    if (x & 1) x += MOD;
    x >>= 1;
}

void mul2(int& x) {
    x += x;
    if (x >= MOD) x -= MOD;
}

void upd(int x, int y, int k, int dx) {
    if (row[0][x] && row[1][x]) brow += dx;
    if (col[0][y] && col[1][y]) bcol += dx;

    if (dx == +1) {
        if (row[0][x] || row[1][x]) div2(cnt_row);
        if (col[0][y] || col[1][y]) div2(cnt_col);
    } else {
        if (row[0][x] || row[1][x]) mul2(cnt_row);
        if (col[0][y] || col[1][y]) mul2(cnt_col);
    }
}

void clr(int x, int y) {
    if (val.count({x, y})) {
        const int k = val[{x, y}];
        const int a = (y + k) % 2, b = (x + k) % 2, c = (x + y + k) % 2;

        upd(x, y, k, -1);
        row[a][x]--;
        col[b][y]--;
        chess[c]--;
        upd(x, y, k, +1);
        val.erase({x, y});
    }
}

void change(int x, int y, int k) {
    clr(x, y);

    val[{x, y}] = k;
    const int a = (y + k) % 2, b = (x + k) % 2, c = (x + y + k) % 2;

    upd(x, y, k, -1);
    row[a][x]++;
    col[b][y]++;
    chess[c]++;
    upd(x, y, k, +1);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> k;

    for (int i = 0; i < n; ++i) mul2(cnt_row);
    for (int i = 0; i < m; ++i) mul2(cnt_col);

    map<pi, int> val;
    for (int i = 0; i < k; ++i) {
        int x, y, t; cin >> x >> y >> t; --x, --y;

        clr(x, y);
        if (t >= 0) change(x, y, t);

        ll ans = (chess[0]?1:0) + (chess[1]?1:0) - 2;
        if (bcol == 0) ans += cnt_col;
        if (brow == 0) ans += cnt_row;

        ans %= MOD;
        if (ans < 0) ans += MOD;
        cout << ans << '\n';
    }
}