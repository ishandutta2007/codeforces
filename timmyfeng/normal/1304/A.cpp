#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        if ((y - x) % (a + b)) {
            cout << -1 << '\n';
        } else {
            cout << (y - x) / (a + b) << '\n';
        }
    }
}