#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;

    vector<int> par(n);
    for (int i = 1; i < n; ++i) cin >> par[i], --par[i];

    vector<pair<int, int>> range(n);
    for (auto &[l, r] : range) cin >> l >> r;

    int answer = 0;
    vector<long long> sum(n);
    for (int i = n - 1; i >= 0; --i) {
        auto [l, r] = range[i];
        if (l > sum[i]) {
            sum[par[i]] += r;
            ++answer;
        } else {
            sum[par[i]] += min(1LL * r, sum[i]);
        }
    }

    cout << answer << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
}