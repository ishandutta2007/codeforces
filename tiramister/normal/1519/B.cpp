#include <iostream>

using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    cout << (n * m - 1 == k ? "YES" : "NO") << "\n";
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int q;
    cin >> q;
    while (q--) solve();

    return 0;
}