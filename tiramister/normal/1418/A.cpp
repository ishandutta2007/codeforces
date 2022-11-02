#line 1 "main.cpp"
#include <iostream>

using namespace std;

using lint = long long;

void solve() {
    lint x, y, k;
    cin >> x >> y >> k;

    auto a = k * (y + 1) - 1,
         b = x - 1;
    cout << (a + b - 1) / b + k << "\n";
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int q;
    cin >> q;
    while (q--) solve();

    return 0;
}