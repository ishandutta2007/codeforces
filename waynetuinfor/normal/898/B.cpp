#include <bits/stdc++.h>
using namespace std;

template <typename T> tuple<T, T, T> extgcd(T a, T b) {
    if (!b) return make_tuple(a, 1, 0);
    T d, x, y;
    tie(d, x, y) = extgcd(b, a % b);
    return make_tuple(d, y, x - (a / b) * y);
}

int main() {
    int n, a, b; cin >> n >> a >> b;
    if (a == 0 && b == 0) return cout << "NO" << endl, 0;
    if (a == 0) {
        if (n % b == 0) cout << "YES\n" << 0 << ' ' << n / b << endl;
        else cout << "NO" << endl;
        return 0;
    } 
    if (b == 0) {
        if (n % a == 0) cout << "YES\n" << 0 << ' ' << n / a << endl;
        else cout << "NO" << endl;
        return 0;
    } 
    for (int i = 0; ; ++i) {
        if (i * a > n) break;
        int dlt = n - i * a;
        if (dlt % b == 0) return cout << "YES\n" << i << ' ' << dlt / b << endl, 0;
    } 
    cout << "NO" << endl;
}