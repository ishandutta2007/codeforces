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
        int n;
        cin >> n;
        int a = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            a = max(a, x);
        }
        cin >> n;
        int b = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            b = max(b, x);
        }
        if (a >= b) {
            cout << "Alice" << '\n';
        } else {
            cout << "Bob" << '\n';
        }
        if (a <= b) {
            cout << "Bob" << '\n';
        } else {
            cout << "Alice" << '\n';
        }
    }
    return 0;
}