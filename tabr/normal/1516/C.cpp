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
    int n;
    cin >> n;
    vector<int> a(n);
    int g = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        g = __gcd(g, a[i]);
    }
    for (int i = 0; i < n; i++) {
        a[i] /= g;
    }
    int s = accumulate(a.begin(), a.end(), 0);
    if (s % 2 == 1) {
        cout << 0 << '\n';
        return 0;
    }
    bitset<300000> bt;
    bt[0] = true;
    for (int i = 0; i < n; i++) {
        bt |= bt << a[i];
    }
    if (bt[s / 2]) {
        cout << 1 << '\n';
        for (int i = 0; i < n; i++) {
            if (a[i] % 2 == 1) {
                cout << i + 1 << '\n';
                break;
            }
        }
    } else {
        cout << 0 << '\n';
    }
    return 0;
}