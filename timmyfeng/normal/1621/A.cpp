#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        if (k > (n + 1) / 2) {
            cout << -1 << "\n";
            continue;
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j && i % 2 == 0 && i / 2 < k) {
                    cout << 'R';
                } else {
                    cout << '.';
                }
            }
            cout << "\n";
        }
    }
}