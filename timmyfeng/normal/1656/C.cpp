#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (auto &i : a) cin >> i;

        if (!count(a.begin(), a.end(), 1)) {
            cout << "YES\n";
            continue;
        }

        sort(a.begin(), a.end());

        bool answer = true;
        for (int i = 1; i < n; ++i) {
            answer &= (a[i] == a[i - 1] || a[i] - a[i - 1] >= 2);
        }

        cout << (answer ? "YES" : "NO") << "\n";
    }
}