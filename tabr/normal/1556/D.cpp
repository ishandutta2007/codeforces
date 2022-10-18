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
    int n, k;
    cin >> n >> k;
    auto f = [&](int x, int y) {
        int z = 0;
        for (int i = 0; i < 31; i++) {
            if ((x & (1 << i)) != (y & (1 << i))) {
                z += 1 << i;
            }
        }
        return z + y * 2;
    };
    vector<int> a(n);
    int x, y;
    cout << "or 2 3" << endl;
    cin >> x;
    cout << "and 2 3" << endl;
    cin >> y;
    a[0] = f(x, y);
    for (int i = 1; i < n; i++) {
        cout << "or 1 " << i + 1 << endl;
        cin >> x;
        cout << "and 1 " << i + 1 << endl;
        cin >> y;
        a[i] = f(x, y);
    }
    vector<int> b(n);
    b[0] = (a[1] + a[2] - a[0]) / 2;
    for (int i = 1; i < n; i++) {
        b[i] = a[i] - b[0];
    }
    debug(b);
    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int i, int j) { return b[i] < b[j]; });
    cout << "finish " << b[order[k - 1]] << endl;
    return 0;
}