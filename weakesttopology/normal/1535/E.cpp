#include "bits/stdc++.h"

using namespace std;

#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(x) begin(x), end(x)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin >> q;

    vector<ll> a(q + 1), c(q + 1);
    cin >> a[0] >> c[0];

    constexpr int K = 20;
    vector<array<int, K>> up(q + 1);

    for (int z = 1; z <= q; ++z) {
        int type;
        cin >> type;
        if (type == 1) {
            cin >> up[z][0] >> a[z] >> c[z];
            for (int x = 0; x + 1 < K; ++x) up[z][x + 1] = up[up[z][x]][x];
        }
        else {
            int u;
            ll w;
            cin >> u >> w;
            ll bought = 0, cost = 0;
            while (w > 0 && a[u] > 0) {
                int v = u;
                for (int x = K - 1; x >= 0; --x) {
                    if (a[up[v][x]] > 0) v = up[v][x];
                }
                ll take = min<ll>(a[v], w);
                a[v] -= take, w -= take;
                bought += take, cost += take * c[v];
            }
            cout << bought << " " << cost << endl;
        }
    }

    exit(0);
}