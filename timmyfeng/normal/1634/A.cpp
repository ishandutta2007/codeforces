#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n, k; cin >> n >> k;
        string s; cin >> s;

        string rev_s = s;
        ranges::reverse(rev_s);

        if (k == 0) {
            cout << 1 << "\n";
        } else if (rev_s == s) {
            cout << 1 << "\n";
        } else {
            cout << 2 << "\n";
        }
    }
}