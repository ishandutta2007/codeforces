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

    vector<vector<int>> F(n);
    for (int u = 1; u < n; ++u) {
        int p;
        cin >> p;
        --p;
        F[p].push_back(u);
    }

    vector<vector<int>> E(n);
    for (int u = 1; u < n; ++u) {
        int p;
        cin >> p;
        --p;
        E[p].push_back(u);
    }

    vector<int> L(n), R(n);
    int timer = 0;
    auto dfs = [&](auto& self, int u) -> void {
        L[u] = timer;
        for (auto v : E[u]) self(self, v);
        R[u] = timer++;
    };
    dfs(dfs, 0);

    set<pair<int, int>> S;
    auto insert = [&](int u) {
        auto iter = S.upper_bound(pair(R[u], u));
        if (iter != begin(S) && prev(iter)->first >= L[u]) return pair(false, -1);
        int removed = -1;
        if (iter != end(S) && L[iter->second] <= L[u]) {
            removed = iter->second;
            S.erase(iter);
        }
        S.emplace(R[u], u);
        return pair(true, removed);
    };

    int ans = 1;

    auto solve = [&](auto& self, int u) -> void {
        auto [inserted, removed] = insert(u);
        ans = max(ans, (int)size(S));
        for (auto v : F[u]) self(self, v);
        if (inserted) S.erase(pair(R[u], u));
        if (removed != -1) S.emplace(R[removed], removed);
    };
    solve(solve, 0);

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();

    exit(0);
}