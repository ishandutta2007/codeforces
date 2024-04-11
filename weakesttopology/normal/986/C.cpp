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

    int fullmask = (1 << n) - 1;

    vector<int> a(m);
    vector<bool> vis(1 << n, false), special(1 << n, false);

    for (auto& x : a) {
        cin >> x;
        special[x] = true;
    }

    auto dfs = [&](auto&& self, int mask) -> void {
        vis[mask] = true;
        for (int i = 0; i < n; ++i) {
            int newmask = mask ^ (1 << i);
            if ((mask >> i & 1) && not vis[newmask]) self(self, newmask);
        }
        if (int newmask = mask ^ fullmask; special[mask] && not vis[newmask]) self(self, newmask);
    };

    int ans = 0;
    for (auto x : a) {
        if (not vis[x]) {
            ans += 1;
            dfs(dfs, x);
        }
    }
    cout << ans << endl;

    exit(0);
}