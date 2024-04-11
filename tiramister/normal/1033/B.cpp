#include <iostream>

using namespace std;
using ll = long long;

bool isprime(ll n) {
    for (ll i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int Q;
    cin >> Q;
    for (int q = 0; q < Q; ++q) {
        ll a, b;
        cin >> a >> b;
        cout << (a - b == 1 && isprime(a + b) ? "YES" : "NO") << endl;
    }
    return 0;
}