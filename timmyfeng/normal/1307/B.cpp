#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int mx = 0;
        int match = false;
        while (n--) {
            int a;
            cin >> a;
            mx = max(mx, a);
            if (a == x) {
                match = true;
            }
        }
        if (match) {
            cout << 1 << '\n';
        } else if (mx > x) {
            cout << 2 << '\n';
        } else {
            cout << x / mx + (x % mx != 0) << '\n';
        }
    }
}