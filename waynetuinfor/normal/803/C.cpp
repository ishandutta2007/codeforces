#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, k; cin >> n >> k;
    int ans = -1;
    // if ((unsigned long long)k * (unsigned long long)(k + 1) / (unsigned long long)2 > (unsigned long long)n) return cout << "-1" << endl, 0;
    if (k > 2 * sqrt(n)) return cout << "-1\n", 0;
    for (int i = 1; i <= sqrt(n); ++i) if (n % i == 0) {
        if (n - (long long)i * k * (k - 1) / 2 > (k - 1) * (long long)i) ans = max(ans, i);
        long long t = (n / i) * (k - 1);
        if (t > 1e10) continue;
        if (n - (long long)(n / i) * k * (k - 1) / 2 > (k - 1) * (long long)(n / i)) ans = max(ans, (int)(n / i));
    }
    if (ans == -1) return cout << ans << endl, 0;
    for (int i = 1; i < k; ++i) cout << (long long)ans * (long long)i << ' ';
    cout << n - (long long)ans * k * (k - 1) / 2; cout << endl;
    return 0;
}