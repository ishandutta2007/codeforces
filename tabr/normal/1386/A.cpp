#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int get_rand(int a, int b) {  // [a, b]
    return uniform_int_distribution<int>(a, b)(rng);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        ll n;
        cin >> n;
        // n = get_rand(1, 64);
        debug(n);
        if (n == 1) {
            cout << "= 1" << endl;
            continue;
        }
        ll lo = 0, hi = n;
        ll mx = 0, mn = 0;
        ll lox = 0;
        ll sgn = 1;
        ll cur = 0;
        while (hi - lox > 1) {
            ll mid = (hi + lox) / 2;
            cur += mid * sgn;
            mx = max(mx, cur);
            mn = min(mn, cur);
            sgn *= -1;
            lox = mid;
        }
        debug(mx, mn);
        sgn = 1;
        cur = n - mx;
        set<ll> st;
        st.emplace(cur);
        cout << "? " << cur << endl;
        cin >> lox;
        while (hi - lo > 1) {
            ll mid = (hi + lo) / 2;
            cur += mid * sgn;
            assert(!st.count(cur));
            assert(1 <= cur && cur <= n);
            cout << "? " << cur << endl;
            st.emplace(cur);
            sgn *= -1;
            cin >> lox;
            // lox = get_rand(0, 1);
            if (lox == 1) {
                hi = mid;
            } else {
                lo = mid;
            }
        }
        cout << "= " << hi << endl;
    }
    return 0;
}