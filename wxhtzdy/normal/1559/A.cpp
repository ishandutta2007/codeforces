#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &i : a) cin >> i;

        int res = (1 << 31) - 1;
        for (int i = 0; i < n; i++) {
            res &= a[i];
        }
        cout << res << '\n';
    }
}