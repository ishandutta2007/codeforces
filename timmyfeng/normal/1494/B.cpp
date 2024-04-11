#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        array<int, 2> x, y;
        cin >> n >> x[0] >> y[0] >> x[1] >> y[1];

        bool ok = false;
        for (int i = 0; i < (1 << 4) && !ok; ++i) {
            array<int, 2> u = x, v = y;
            for (int j = 0; j < 2; ++j) {
                for (int k = 0; k < 2; ++k) {
                    if ((i & (1 << (2 * j + k))) > 0) {
                        --u[j], --v[k];
                    }
                }
            }

            ok = true;
            for (auto j : {u[0], u[1], v[0], v[1]}) {
                ok &= 0 <= j && j <= n - 2;
            }
        }

        cout << (ok ? "YES" : "NO") << "\n";
    }
}