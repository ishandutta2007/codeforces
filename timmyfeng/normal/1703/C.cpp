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

        for (int i = 0; i < n; ++i) {
            int k; cin >> k;
            string s; cin >> s;
            for (auto c : s) {
                a[i] += (c == 'D') ? 1 : -1;
            }
            a[i] = (a[i] % 10 + 10) % 10;
            cout << a[i] << " ";
        }
        cout << "\n";
    }
}