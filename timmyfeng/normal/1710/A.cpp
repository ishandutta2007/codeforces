#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n, m, k; cin >> n >> m >> k;

        vector<int> a(k);
        for (auto &i : a) cin >> i;

        long long vertical = 0, horizontal = 0;
        bool vpar = false, hpar = false;
        for (auto i : a) {
            if (i >= 2 * n) {
                vertical += i / n;
                vpar |= (i / n != 2);
            }
            if (i >= 2 * m) {
                horizontal += i / m;
                hpar |= (i / m != 2);
            }
        }

        if (vertical >= m && !(!vpar && m % 2 == 1)) {
            cout << "Yes\n";
        } else if (horizontal >= n && !(!hpar && n % 2 == 1)) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}