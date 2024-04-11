#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        vector<int> occ(30);
        for (int i = 0; i < n; ++i) {
            int a; cin >> a;
            for (int j = 0; j < 30; ++j) {
                if (a & (1 << j)) {
                    ++occ[j];
                }
            }
        }

        int gcd_bits = 0;
        for (auto i : occ)
            gcd_bits = gcd(gcd_bits, i);
        
        for (int i = 1; i <= n; ++i) {
            if (gcd_bits % i == 0) {
                cout << i << " ";
            }
        }
        cout << "\n";
    }
}