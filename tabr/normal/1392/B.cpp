#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<ll> b(n);
        ll mx = *max_element(a.begin(), a.end());
        for (int i = 0; i < n; i++) {
            b[i] = mx - a[i];
        }
        vector<ll> c(n);
        mx = *max_element(b.begin(), b.end());
        for (int i = 0; i < n; i++) {
            c[i] = mx - b[i];
        }
        debug(b, c);
        if (k % 2 == 0) {
            swap(b, c);
        }
        for (auto i : b) {
            cout << i << " ";
        }
        cout << '\n';
    }
    return 0;
}