#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s; cin >> s;
    const int n = s.size();

    int l = 0, r = n - 1;

    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') l = i;
    }
    for (int i = n; i--; ) {
        if (s[i] == '0') r = i;
    }

    cout << max(0, r - l + 1) << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}