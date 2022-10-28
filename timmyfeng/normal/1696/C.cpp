#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n, m; cin >> n >> m;

        vector<int> a(n);
        for (auto &i : a) cin >> i;

        vector<pair<int, long long>> reduced;
        for (auto i : a) {
            int count = 1;
            while (i % m == 0) i /= m, count *= m;
            if (reduced.empty() || reduced.back().first != i) {
                reduced.push_back({i, count});
            } else {
                reduced.back().second += count;
            }
        }

        int k; cin >> k;

        vector<int> b(k);
        for (auto &i : b) cin >> i;

        reverse(b.begin(), b.end());

        bool possible = true;
        for (auto i : b) {
            int count = 1;
            while (i % m == 0) i /= m, count *= m;
            if (reduced.empty() || reduced.back().first != i || reduced.back().second < count) {
                possible = false;
                break;
            }
            reduced.back().second -= count;
            if (reduced.back().second == 0) reduced.pop_back();
        }

        possible &= reduced.empty();

        cout << (possible ? "Yes" : "No") << "\n";
    }
}