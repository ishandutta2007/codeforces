#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        vector<int> k(n), h(n);
        for (auto &i : k) cin >> i;
        for (auto &i : h) cin >> i;

        vector<pair<int, int>> casts;
        for (int i = 0; i < n; ++i) {
            casts.push_back({k[i] - h[i], 1});
            casts.push_back({k[i], -1});
        }
        ranges::sort(casts);

        long long ans = 0;
        int total = 0, prv = 0;
        for (auto [time, delta] : casts) {
            if (total == 0) prv = time;
            total += delta;
            if (total == 0) ans += (long long) (time - prv) * (time - prv + 1) / 2;
        }

        cout << ans << "\n";
    }
}