#include <bits/stdc++.h>

using namespace std;

int n;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    int c = n - 1;
    int d = -1, m = 1;
    for (int i = 2; i * i <= n; ++i) if (n % i == 0) {
        d = i;
        break;
    }
    if (d == -1) return cout << "NO" << endl, 0;
    while (n % d == 0) n /= d, m *= d;
    if (n == 1) return cout << "NO" << endl, 0;
    if (n > m) swap(n, m);
    for (int i = 1; i < n; ++i) {
        int q = c - m * i;
        if (q % n == 0) {
            cout << "YES" << endl;
            cout << 2 << endl;
            int a = q / n, b = i;
            int _d = __gcd(a, m); m /= _d, a /= _d;
            _d = __gcd(b, n); n /= _d, b /= _d;
            cout << a << ' ' << m << endl;
            cout << b << ' ' << n << endl;
            return 0;
        }
    }
    return 0;
}