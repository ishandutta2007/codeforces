#include <iostream>

using namespace std;
using ll = long long;

template <typename T>
T gcd(T a, T b) {
    if (a < b) return gcd(b, a);
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    ll N, M, K;
    cin >> N >> M >> K;

    if (N * M * 2 % K != 0) {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;
    ll x[3], y[3];
    x[0] = y[0] = x[1] = y[2] = 0;

    ll g = gcd(N, K);
    if (g > 1) {
        g = gcd(N * 2, K);
        x[2] = N * 2 / g;
        y[1] = M / (K / g);
    } else {
        x[2] = N / g;
        y[1] = M * 2 / (K / g);
    }

    for (int i = 0; i < 3; ++i) {
        cout << x[i] << " " << y[i] << endl;
    }
    return 0;
}