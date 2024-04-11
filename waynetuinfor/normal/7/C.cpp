#include <bits/stdc++.h>
#define int long long
using namespace std;

template <typename T> tuple<T, T, T> extgcd(T a, T b) {
    if (!b) return make_tuple(a, 1, 0);
    T d, x, y;
    tie(d, x, y) = extgcd(b, a % b);
    return make_tuple(d, y, x - (a / b) * y);
}

int32_t main() {
    int a, b, c; cin >> a >> b >> c;
    int x, y, d;
    tie(d, x, y) = extgcd<int>(a, b);
    if (c % d != 0) return cout << "-1" << endl, 0;
    int k = -c / d;
    cout << x * k << ' ' << y * k << endl;
    return 0;
}