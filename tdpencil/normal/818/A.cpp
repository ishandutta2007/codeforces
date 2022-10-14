#include <iostream>
using ll = int64_t;
using namespace std;
int main() {
    ll n, k;
    cin >> n >> k;

    // 2x + x <= n / 2
    ll t = n / (k+1) / 2;
    cout << t << " " << t * k << " " << n - t * (k + 1) << '\n';
}