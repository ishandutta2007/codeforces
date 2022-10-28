#include <bits/stdc++.h>
using namespace std;

long long pow10(int p) {
    return (p == 0) ? 1 : 10 * pow10(p - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int x1, p1, x2, p2;
        cin >> x1 >> p1 >> x2 >> p2;

        int p = min(p1, p2);
        p1 -= p, p2 -= p;

        if (p1 > 6) {
            cout << ">\n";
        } else if (p2 > 6) {
            cout << "<\n";
        } else if (x1 * pow10(p1) > x2 * pow10(p2)) {
            cout << ">\n";
        } else if (x1 * pow10(p1) == x2 * pow10(p2)) {
            cout << "=\n";
        } else {
            cout << "<\n";
        }
    }
}