#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int x1, p1, x2, p2;
        cin >> x1 >> p1 >> x2 >> p2;
        int q = min(p1, p2);
        p1 -= q;
        p2 -= q;
        int s1 = (int) to_string(x1).size() + p1;
        int s2 = (int) to_string(x2).size() + p2;
        if (s1 > s2) {
            cout << ">" << '\n';
        } else if (s1 < s2) {
            cout << "<" << '\n';
        } else {
            long long y1 = x1, y2 = x2;
            for (int i = 0; i < p1; i++) {
                y1 *= 10;
            }
            for (int i = 0; i < p2; i++) {
                y2 *= 10;
            }
            if (y1 > y2) {
                cout << ">" << '\n';
            } else if (y1 < y2) {
                cout << "<" << '\n';
            } else {
                cout << "=" << '\n';
            }
        }
    }
    return 0;
}