#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, d, x, y; cin >> a >> b >> c >> d >> x >> y;
    if (abs(a - c) % x == 0 && abs(b - d) % y == 0) {
        int n = abs(a - c) / x, m = abs(b - d) / y;
        // if (min(n, m) == 0 || max(n, m) % min(n, m) == 0) cout << "YES\n";
        // else cout << "NO\n";
        if (n % 2 == m % 2) cout << "YES\n";
        else cout << "NO\n";
    }
    else cout << "NO\n";
    return 0;
}