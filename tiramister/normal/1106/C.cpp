#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

template <typename T>
inline T sq(T a) { return a * a; }

int main() {
    int n;
    cin >> n;
    ll a[n];
    for (int i = 0; i < n; ++i) cin >> a[i];

    sort(a, a + n);
    ll ans = 0;
    for (int i = 0; i < n / 2; ++i) ans += sq(a[i] + a[n - i - 1]);
    cout << ans << endl;
    return 0;
}