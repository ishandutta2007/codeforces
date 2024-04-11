#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n, k; cin >> n >> k;

        if (n == 4 && k == 3) {
            cout << -1 << "\n";
            continue;
        }

        vector<int> mate(n);
        for (int i = 0; i < n; ++i) {
            mate[i] = (n - 1) ^ i;
        }

        for (int bit = n / 2; bit > 0; bit /= 2) {
            if (k >= bit) {
                swap(mate[bit], mate[0]);
                swap(mate[mate[bit]], mate[mate[0]]);
                k -= bit;
            }
        }

        for (int i = 0; i < n; ++i) if (i < mate[i]) cout << i << " " << mate[i] << "\n";
    }
}