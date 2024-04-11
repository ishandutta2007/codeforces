#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int a[2], b[2], c[2];
    cin >> a[0] >> a[1] >> b[0] >> b[1] >> c[0] >> c[1];

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                if (b[j] + c[k] <= a[i] && max(b[1 - j], c[1 - k]) <= a[1 - i]) {
                    cout << "YES\n";
                    exit(0);
                }
            }
        }
    }

    cout << "NO\n";
}