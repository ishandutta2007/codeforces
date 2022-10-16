#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int& x : a) cin >> x;
    reverse(a.begin(), a.end());

    int last = 2e9+1;
    int ans = 0;

    for (int x : a) {
        while (x != 0 && x >= last) x /= 2, ++ans;

        if (x >= last) {
            cout << -1 << '\n';
            return;
        }

        last = x;
    }

    cout << ans << '\n';
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}