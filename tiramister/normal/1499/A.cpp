#include <iostream>

using namespace std;

void solve() {
    int n;
    cin >> n;

    int w = 0;
    for (int q = 0; q < 2; ++q) {
        int k;
        cin >> k;
        w += k;
    }
    int b = n * 2 - w;

    int x, y;
    cin >> x >> y;
    cout << (x <= w / 2 && y <= b / 2 ? "YES" : "NO") << "\n";
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int q;
    cin >> q;
    while (q--) solve();

    return 0;
}