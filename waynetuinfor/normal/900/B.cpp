#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
    int a, b, c; cin >> a >> b >> c;
    int g = __gcd(a, b);
    a /= g; b /= g;
    for (int i = 0; i < 100000; ++i) {
        int now;
        now = a / b, a %= b;
        if (now == c && i > 0) return cout << i << endl, 0;
        a *= 10;
    }
    cout << "-1" << endl;
    return 0;
}