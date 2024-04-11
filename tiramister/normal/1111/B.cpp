#include <iomanip>
#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    ll n, k, m;
    cin >> n >> k >> m;

    long double a[n];
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n, greater<double>());
    for (int i = 1; i < n; ++i) a[i] += a[i - 1];

    long double ans = 0;
    for (int i = 0; i <= min(n - 1, m); ++i) {
        // i
        long double sum = a[n - i - 1];
        sum += min(m - i, k * (n - i));
        ans = max(ans, sum / (n - i));
    }

    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}