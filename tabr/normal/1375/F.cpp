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
    vector<ll> a(3);
    for (int i = 0; i < 3; i++) {
        cin >> a[i];
    }
    cout << "First" << endl;
    int z = -1;
    while (true) {
        vector<ll> b = a;
        sort(b.begin(), b.end());
        ll x = b[1] - b[0], y = b[2] - b[1];
        if (z != -1 && a[z - 1] == b[2] && x == y) {
            cout << x << endl;
            break;
        }
        if (x * y == 0) {
            break;
        }
        cout << x + y * 2 << endl;
        cin >> z;
        if (z == 0) {
            break;
        }
        a[z - 1] += x + y * 2;
    }
    return 0;
}