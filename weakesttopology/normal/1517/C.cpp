#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(x) begin(x), end(x)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

const int D = 2;
const int dx[2] = { +0, +1 };
const int dy[2] = { -1, -0 };

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> p(n);
    for (auto& x : p) cin >> x;

    constexpr int nmax = 500;
    int g[nmax][nmax]{}, qt[nmax + 1];
    iota(all(qt), 0);

    auto dfs = [&](auto& self, int x, int y, int c) -> void {
        g[x][y] = c, qt[c] -= 1;
        for (int t = 0; t < D && qt[c] > 0; ++t) {
            int nx = x + dx[t], ny = y + dy[t];
            if (nx < n && ny >= 0 && g[nx][ny] == 0) self(self, nx, ny, c);
        }
    };

    for (int x = 0; x < n; ++x) {
        dfs(dfs, x, x, p[x]);
    }

    for (int x = 0; x < n; ++x) {
        for (int y = 0; y <= x; ++y) {
            cout << g[x][y] << "\n "[y < x];
        }
    }

    exit(0);
}