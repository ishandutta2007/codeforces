#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n, x; cin >> n >> x;

        map<int, multiset<int>> coeffs;
        for (int i = 0; i < n; ++i) {
            int a; cin >> a;

            int exponent = 0;
            while (a % x == 0) {
                ++exponent;
                a /= x;
            }

            coeffs[a].insert(exponent);
        }

        int ans = 0;
        for (auto &[a, exponents] : coeffs) {
            while (!exponents.empty()) {
                int x = *exponents.begin();
                exponents.erase(exponents.begin());
                if (exponents.contains(x + 1)) {
                    exponents.erase(exponents.find(x + 1));
                } else ++ans;
            }
        }

        cout << ans << "\n";
    }
}