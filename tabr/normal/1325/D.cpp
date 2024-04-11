#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...) 0
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll u, v;
    cin >> u >> v;
    ll w = v - u;
    if (w < 0 || w & 1LL) {
        cout << -1 << endl;
        return 0;
    }
    vector<ll> a = {u, w >> 1, w >> 1, 0};
    if ((a[0] & a[2]) == 0) {
        a[0] |= a[2];
        a[2] = 0;
    }
    sort(a.rbegin(), a.rend());
    for (int i = 0; i <= 3; i++) {
        if (a[i] == 0) {
            cout << i << endl;
            for (int j = 0; j < i; j++) {
                cout << a[j] << ' ';
            }
            break;
        }
    }
    cout << endl;
    return 0;
}