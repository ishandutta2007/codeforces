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
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (n == 1) {
        for (int l = 0; l < 3; l++) {
            cout << 1 << " " << 1 << '\n';
            cout << -a[0] << '\n';
            a[0] = 0;
        }
        return 0;
    }
    cout << 1 << " " << n << '\n';
    for (int i = 0; i < n; i++) {
        ll b = a[i] % (n - 1);
        cout << -b * n << " ";
        a[i] -= b * n;
    }
    cout << '\n';
    cout << 1 << " " << n - 1 << '\n';
    for (int i = 0; i < n - 1; i++) {
        cout << -a[i] << " ";
    }
    cout << '\n';
    cout << n << " " << n << '\n';
    cout << -a[n - 1] << '\n';
    return 0;
}