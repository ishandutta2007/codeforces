#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using lint = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> us(n);
    for (auto& u : us) {
        cin >> u;
        --u;
    }

    vector<vector<lint>> xss(n);
    for (auto u : us) {
        lint x;
        cin >> x;
        xss[u].push_back(x);
    }

    vector<lint> ans(n + 1, 0);
    for (auto& xs : xss) {
        int m = xs.size();

        sort(xs.rbegin(), xs.rend());
        xs.insert(xs.begin(), 0);
        for (int i = 1; i <= m; ++i) xs[i] += xs[i - 1];

        for (int k = 1; k <= m; ++k) {
            ans[k] += xs[m / k * k];
        }
    }

    for (int k = 1; k <= n; ++k) cout << ans[k] << " ";
    cout << "\n";
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int q;
    cin >> q;
    while (q--) solve();

    return 0;
}