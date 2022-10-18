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
    long long k, l, r, t, x, y;
    cin >> k >> l >> r >> t >> x >> y;
    set<long long> st;
    k -= l;
    r -= l;
    long long c = 0;
    if (x > y) {
        if (k + y <= r) {
            k += y;
        }
        k -= x;
        if (k < 0) {
            cout << "No" << '\n';
            return 0;
        }
        c++;
        c += max(0LL, k / (x - y));
        if (c < t) {
            cout << "No" << '\n';
        } else {
            cout << "Yes" << '\n';
        }
        return 0;
    }
    while (c < t) {
        if (k + y <= r) {
            if (st.count(k % x)) {
                cout << "Yes" << '\n';
                return 0;
            }
            st.emplace(k % x);
            k += y;
        }
        k -= x;
        if (k < 0) {
            cout << "No" << '\n';
            return 0;
        }
        c++;
        if (k + y > r) {
            long long a = (k + y - r + x - 1) / x;
            a = min(a, k / x);
            k -= a * x;
            c += a;
        }
    }
    cout << "Yes" << '\n';
    return 0;
}