#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        vector<int> a(n);
        set<int> odd;
        for (auto &i : a) {
            cin >> i;
            if (odd.contains(i)) odd.erase(i);
            else odd.insert(i);
        }

        if (!odd.empty()) {
            cout << -1 << "\n";
            continue;
        }

        vector<pair<int, int>> operations;
        vector<int> segments;
        int offset = 0;

        for (int i = n - 1; i > 0; i -= 2) {
            int j = (int) (ranges::find(a, a[i]) - begin(a));

            // flip a[0..j]
            for (int k = 0; k <= j; ++k) {
                operations.push_back({offset + j + k + 1, a[k]});
            }
            reverse(begin(a), begin(a) + j + 1);
            segments.push_back(2 * (j + 1));
            offset += 2 * (j + 1);

            // flip a[0..i-1]
            for (int k = 0; k < i; ++k) {
                operations.push_back({offset + i + k, a[k]});
            }
            reverse(begin(a), begin(a) + i);
            segments.push_back(2 * i);
            offset += 2 * i;
        }

        for (int i = 0; i < n / 2; ++i) segments.push_back(2);

        cout << operations.size() << "\n";
        for (auto [x, y] : operations) cout << x << " " << y << "\n";
        cout << segments.size() << "\n";
        for (auto i : segments) cout << i << "\n";
    }
}