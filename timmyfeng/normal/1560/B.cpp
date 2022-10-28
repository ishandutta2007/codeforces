#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;

        int n = abs(a - b) * 2;

        if (max({a, b, c}) > n) {
            cout << -1 << "\n";
        } else if (c <= n / 2) {
            cout << c + n / 2 << "\n";
        } else {
            cout << c - n / 2 << "\n";
        }
    }
}