#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(x) begin(x), end(x)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> a(m), b(m);
    for (int j = 0; j < m; ++j) cin >> a[j] >> b[j];

    vector<int> I(m);
    iota(all(I), 0);
    sort(all(I), [&](int i, int j){ return pair(a[i], b[j]) < pair(a[j], b[i]); });

    vector<int> p(n);
    iota(all(p), 0);

    int rt = 0, ptr = 1, remaining = m - (n - 1);
    vector<pair<int, int>> spare_edges, ans(m);

    vector<set<int>> vset(n);
    for (int u = 0; u < n; ++u) vset[u].insert(u);

    bool good = true;

    for (auto j : I) {
        if (b[j]) {
            if (ptr >= n) {
                good = false;
                break;
            }
            int u = rt, v = ptr++;
            for (auto x : vset[u]) {
                if (remaining == 0) break;
                for (auto y : vset[v]) {
                    if (remaining == 0) break;
                    if (x == u && y == v) continue;
                    spare_edges.emplace_back(x, y);
                    --remaining;
                }
            }
            vset[u].merge(vset[v]);
            ans[j] = { u, v };
        }
        else {
            if (empty(spare_edges)) {
                good = false;
                break;
            }
            ans[j] = spare_edges.back();
            spare_edges.pop_back();
        }
    }

    if (not good) cout << -1 << endl;
    else {
        for (auto [u, v] : ans) {
            cout << u + 1 << " " << v + 1 << endl;
        }
    }

    exit(0);
}