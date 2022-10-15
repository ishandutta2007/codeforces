#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(x) begin(x), end(x)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> b(n);
    vector<pair<int, int>> p;
    for (int i = 0; i < n; ++i) {
        b[i].resize(m);
        for (int j = 0; j < m; ++j) {
            cin >> b[i][j];
            p.emplace_back(i, j);
        }
    }
    sort(all(p), [&](auto x, auto y){ return b[x.first][x.second] < b[y.first][y.second]; });

    vector<vector<int>> res(m, vector<int>(n, -1));
    for (int j = 0; j < m; ++j) {
        auto [x, y] = p[j];
        res[j][x] = b[x][y];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (res[j][i] != -1) {
                b[i].erase(find(all(b[i]), res[j][i]));
            }
        }
        for (int j = 0; j < m; ++j) {
            if (res[j][i] == -1) {
                res[j][i] = b[i].back();
                b[i].pop_back();
            }
            cout << res[j][i] << "\n "[j + 1 < m];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();

    exit(0);
}