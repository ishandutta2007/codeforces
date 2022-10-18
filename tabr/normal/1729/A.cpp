#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int a, b, c;
        cin >> a >> b >> c;
        int d = c + abs(c - b);
        if (a == d) {
            cout << 3 << "\n";
        } else if (a < d) {
            cout << 1 << "\n";
        } else {
            cout << 2 << "\n";
        }
    }
    return 0;
}