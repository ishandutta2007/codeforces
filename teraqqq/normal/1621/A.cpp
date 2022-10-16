#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k; cin >> n >> k;

    if (2 * (k - 1) >= n)  {
        cout << -1 << '\n';
        return;
    }

    vector a(n, string(n, '.'));

    for (int i = 0; i < k; ++i) {
        a[2*i][2*i] = 'R';
    }

    for (auto& s : a) {
        cout << s << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}