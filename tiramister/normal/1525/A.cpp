#include <iostream>
#include <numeric>

using namespace std;

void solve() {
    int k;
    cin >> k;
    cout << 100 / gcd(100, k) << "\n";
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int q;
    cin >> q;
    while (q--) solve();

    return 0;
}