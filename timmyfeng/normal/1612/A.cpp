#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int x, y;
        cin >> x >> y;

        if ((x + y) % 2 == 1) {
            cout << -1 << " " << -1 << "\n";
        } else {
            cout << min(x, (x + y) / 2) << " " << max(0, (x + y) / 2 - x) << "\n";
        }
    }
}