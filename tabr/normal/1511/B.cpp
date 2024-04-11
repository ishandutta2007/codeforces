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
        int a, b, c;
        cin >> a >> b >> c;
        a -= c - 1;
        b -= c - 1;
        long long p = 2, q = 3;
        while ((int)to_string(p).size() < a) {
            p *= 2;
        }
        while ((int)to_string(q).size() < b) {
            q *= 3;
        }
        cout << p << string(c - 1, '0') << " " << q << string(c - 1, '0') << '\n';
    }
    return 0;
}