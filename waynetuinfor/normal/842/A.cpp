#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
    int l, r, x, y, k; cin >> l >> r >> x >> y >> k;
    for (int i = x; i <= y; ++i) {
        if (i * k >= l && i * k <= r) return cout << "YES" << endl, 0;
    }
    cout << "NO" << endl;
    return 0;
}