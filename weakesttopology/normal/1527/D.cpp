#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(x) begin(x), end(x)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> E(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        E[u].push_back(v), E[v].push_back(u);
    }

    vector<int> L(n), R(n), sz(n), color(n, -1);
    int timer = 0;
    auto dfs = [&](auto&& self, int u, int p) -> void {
        L[u] = timer;
        for (auto v : E[u]) if (v != p) {
            color[v] = (u == 0 ? v : color[u]);
            self(self, v, u);
        }
        R[u] = timer++;
        sz[u] = R[u] - L[u] + 1;
    };
    dfs(dfs, 0, -1);

    auto is_ancestor = [&](int u, int v) { return L[u] <= L[v] && R[v] <= R[u]; };

    vector<ll> ans(n + 1, 0);
    ll sum = 1;
    for (auto v : E[0]) {
        ans[0] += 1LL * sz[v] * (sz[v] - 1) / 2;
        int rem = color[1] == v ? sz[1] : 0;
        ans[1] += sum * (sz[v] - rem);
        sum += sz[v] - rem;
    }

    int deep = 1, nxt = 2;
    while (nxt < n) {
        if (is_ancestor(deep, nxt)) {
            ans[nxt] = 1LL * (n - sz[color[deep]]) * (sz[deep] - sz[nxt]);
            deep = nxt;
            ++nxt;
        }
        else if (color[nxt] == color[deep]) {
            if (not is_ancestor(nxt, deep)) {
                ans[nxt] = 1LL * (n - sz[color[deep]]) * sz[deep];
                break;
            }
            else ++nxt;
        }
        else {
            ans[nxt] = 1LL * (n - sz[color[deep]] - sz[nxt]) * sz[deep];
            break;
        }
    }

    if (nxt == n || color[nxt] != color[deep]) {
        int d[2] = { deep, nxt };
        for (int u = nxt + 1; u < n; ++u) {
            bool good = false;
            for (auto t : {0, 1}) {
                bool up = is_ancestor(u, d[t]);
                bool down = is_ancestor(d[t], u);
                if (up || down) {
                    good = true;
                    if (down) {
                        ans[u] = 1LL * (sz[d[t]] - sz[u]) * sz[d[t ^ 1]];
                        d[t] = u;
                    }
                    break;
                }
            }
            if (not good) {
                ans[u] = 1LL * sz[d[0]] * sz[d[1]];
                break;
            }
        }

        int cnt = 0;
        for (int u = 0; u < n; ++u) {
            cnt += size(E[u]) == 1;
        }
        if (cnt == 2) ans[n] = 1;
    }

    for (int x = 0; x <= n; ++x) {
        cout << ans[x] << "\n "[x < n];
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