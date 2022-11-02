#include <iostream>

using namespace std;
using ll = long long;

int main() {
    int n;
    ll t;
    cin >> n >> t;

    ll a[n];
    for (int i = 0; i < n; ++i) cin >> a[i];

    ll ans = 0;
    while (true) {
        ll cnt = 0, cost = 0;
        for (int i = 0; i < n; ++i) {
            if (t - cost >= a[i]) {
                cost += a[i];
                ++cnt;
            }
        }

        if (cnt == 0) break;
        ans += cnt * (t / cost);
        t %= cost;
    }

    cout << ans << endl;
    return 0;
}