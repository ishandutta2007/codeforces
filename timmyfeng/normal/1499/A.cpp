#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, k1, k2, w, b;
        cin >> n >> k1 >> k2 >> w >> b;

        if (k2 < k1) {
            swap(k2, k1);
        }
        int k3 = n - k2, k4 = n - k1;

        cout << (k1 + (k2 - k1) / 2 >= w && k3 + (k4 - k3) / 2 >= b ? "YES" : "NO") << "\n";
    }
}