#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b; cin >> a >> b;
    int tlim = a / b - 1;
    bool ans = false;
    double x = 1e18;
    if (tlim & 1) --tlim;
    if (tlim > 0) ans = true, x = min(x, 1.0 * (a - b) / tlim);
    tlim = a / b;
    if (tlim % 2 == 0) --tlim;
    if (tlim > 0) ans = true, x = min(x, 1.0 * (a + b) / (tlim + 1));
    if (!ans) cout << "-1" << endl;
    else cout << fixed << setprecision(20) << x << endl;
}