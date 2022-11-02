#include <iostream>

using namespace std;
using ll = long long;

int main() {
    ll a[14];
    for (int i = 0; i < 14; ++i) cin >> a[i];

    ll ans = 0;
    for (int i = 0; i < 14; ++i) {
        ll b[14];
        copy(a, a + 14, b);
        b[i] = 0;

        for (int j = 0; j < 14; ++j) b[j] += a[i] / 14;
        for (int j = 1; j <= a[i] % 14; ++j) ++b[(i + j) % 14];

        ll score = 0;
        for (int j = 0; j < 14; ++j) {
            if (b[j] % 2 == 0) score += b[j];
        }
        ans = max(ans, score);
    }

    cout << ans << endl;
    return 0;
}