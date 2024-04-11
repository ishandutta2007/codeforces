#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    int fx = 0, fy = 0;
    for (int i = 0; i < n; ++i) {
        char c; int x, y; cin >> c >> x >> y;
        if (c == '+') {
            if (x > y) swap(x, y);
            fx = max(fx, x);
            fy = max(fy, y);
        } else {
            if (x > y) swap(x, y);
            if (fx <= x && fy <= y) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}