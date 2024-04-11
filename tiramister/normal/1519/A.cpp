#include <iostream>

using namespace std;
using lint = long long;

void solve() {
    lint r, b, d;
    cin >> r >> b >> d;
    if (r > b) swap(r, b);

    cout << (r * (d + 1) >= b ? "YES" : "NO") << "\n";
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int q;
    cin >> q;
    while (q--) solve();

    return 0;
}