#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int tt;
    cin >> tt;

    while (tt--) {
        int a, b, c;
        cin >> a >> b >> c;

        int n = abs(a - b) * 2;

        if (c > n || a > n || b > n) {
            cout << -1 << '\n';
            continue;
        }

        c--;
        int res = (c - n / 2 + n) % n;
        cout << res + 1 << '\n';
    }
}