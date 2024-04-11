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

        while (k > 3) {
            cout << 1 << " ";
            --k, --n;
        }

        if (n % 2 == 1) {
            cout << 1 << " " << (n - 1) / 2 << " " << (n - 1) / 2 << "\n";
        } else if (n % 4 == 0) {
            cout << n / 4 << " " << n / 4 << " " << n / 2 << "\n";
        } else {
            cout << 2 << " " << n / 2 - 1 << " " << n / 2 - 1 << "\n";
        }
    }
}