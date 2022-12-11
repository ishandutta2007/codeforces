#include <bits/stdc++.h>

using namespace std;

int main() {
    int test;
    cin >> test;
    while (test--) {
        int n, k1, k2, x1 = 0, x2 = 0;
        cin >> n >> k1 >> k2;
        while (k1--) {
            int x; cin >> x;
            x1 = max(x1, x);
        }
        while (k2--) {
            int x; cin >> x;
            x2 = max(x2, x);
        }
        cout << ((x1 > x2) ? "YES" : "NO") << '\n';
    }
}