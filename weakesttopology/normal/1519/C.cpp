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

    vector<int> u(n), sz(n);
    for (auto& x : u) {
        cin >> x;
        --x;
        sz[x] += 1;
    }

    vector<vector<ll>> skill(n);
    ll tot = 0;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        skill[u[i]].push_back(x);
        tot += x;
    }

    map<int, vector<ll>> H;
    for (int i = 0; i < n; ++i) {
        if (sz[i] > 0) H[sz[i]].assign(sz[i], 0);
    }

    for (int i = 0; i < n; ++i) if (not empty(skill[i])) {
        sort(all(skill[i]));
        for (int j = 0; j < sz[i]; ++j) H[sz[i]][j] += skill[i][j];
    }

    for (auto& [l, v] : H) {
        for (int j = 1; j < l; ++j) {
            v[j] += v[j - 1];
        }
    }

    vector H1(all(H));
    for (int k = 1; k <= n; ++k) {
        ll ans = tot;
        for (auto& [l, v] : H1) {
            int r = l % k;
            if (r > 0) ans -= v[r - 1];
        }
        cout << ans << "\n "[k < n];
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