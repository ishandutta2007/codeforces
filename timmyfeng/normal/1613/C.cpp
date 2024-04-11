#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long h;
        int n;

        cin >> n >> h;

        vector<long long> a(n);
        for (auto &i : a) {
            cin >> i;
        }

        long long low = 1, high = h;
        while (low < high) {
            long long mid = (low + high) / 2;

            long long damage = mid;
            for (int i = 0; i < n - 1; ++i) {
                damage += min(a[i + 1] - a[i], mid);
            }

            if (damage >= h) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        cout << low << "\n";
    }
}