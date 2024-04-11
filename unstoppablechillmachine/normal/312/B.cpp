#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

const int sz = 300100;

void solve() {
    ld a, b, c, d;
    cin >> a >> b >> c >> d;
    ld ans = a / b, l = a / b, p = ((b - a) * (d - c)) / (b * d);
    for (int i = 0; i < 100000; ++i) {
        l *= p;
        ans += l;
    }
    cout << fixed << setprecision(8) << ans << '\n';
}
int main() {
    int t = 1;
    while (t--) {
        solve();
    }
}