#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<pair<int, int>> preferences(n);
        for (auto &[a, b] : preferences) {
            cin >> a >> b;
        }

        int low = 0, high = n;
        while (low < high) {
            int mid = (low + high + 1) / 2;

            int party_size = 0;
            for (auto [a, b] : preferences) {
                if (b >= party_size && a >= mid - 1 - party_size) {
                    ++party_size;
                }
            }

            if (party_size >= mid) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }

        cout << high << "\n";
    }
}