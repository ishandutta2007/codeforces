#include <iostream>

using namespace std;
using ll = long long;

template <typename T>
T iceil(T n, T d) {
    return (n + d - 1) / d;
}

int main() {
    ll n, m, k, l;
    cin >> n >> m >> k >> l;

    ll ans = iceil(k + l, m);
    cout << (ans * m > n ? -1 : ans) << endl;
    return 0;
}