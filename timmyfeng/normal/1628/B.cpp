#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;

    vector<string> arr(n);
    for (auto &i : arr) cin >> i;

    unordered_set<string> prefix;
    for (auto s : arr) {
        if (s.front() == s.back()) {
            cout << "YES\n";
            return;
        } else if (ssize(s) == 2) {
            bool exists = prefix.contains(string() + s[1] + s[0]);
            for (char c = 'a'; c <= 'z'; ++c) {
                exists |= prefix.contains(string() + s[1] + s[0] + c);
            }

            if (exists) {
                cout << "YES\n";
                return;
            }
        } else {
            if (prefix.contains(string() + s[2] + s[1] + s[0]) || prefix.contains(string() + s[2] + s[1])) {
                cout << "YES\n";
                return;
            }
        }
        prefix.insert(s);
    }

    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        solve();
    }
}