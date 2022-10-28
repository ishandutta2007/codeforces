#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;

        if (a == n / 2 + 1 && b == n / 2) {
            for (int i = n; i >= 1; --i) {
                cout << i << " ";
            }
            cout << "\n";
        } else if (a > b || a > n / 2 || b <= n / 2) {
            cout << -1 << "\n";
        } else {
            for (int i = n; i > n / 2; --i) {
                if (i != b) {
                    cout << i << " ";
                }
            }
            cout << a << " " << b << " ";
            for (int i = n / 2; i >= 1; --i) {
                if (i != a) {
                    cout << i << " ";
                }
            }
            cout << "\n";
        }
    }
}