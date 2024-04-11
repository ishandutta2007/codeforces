#include <iostream>

using namespace std;

void solve() {
    int ans = 0;

    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        if (x != 2) ++ans;
    }

    cout << ans << "\n";
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int q;
    cin >> q;
    while (q--) solve();

    return 0;
}