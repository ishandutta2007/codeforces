#include <bits/stdc++.h>
 
using i64 = long long;
 
void solve() {
    int n;
    std::cin >> n;
 
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
 
    std::sort(a.begin(), a.end());
 
    long double sum = 0;
    for (int i = 0; i < n; i++) sum += a[i];
 
    long double ans = -1e18, x = 0;
    for (int i = 0; i < n - 1; i++) {
        sum -= a[i], x += a[i];
        long double L = x / (double) (i + 1), R = sum / (double) (n - i - 1);
        ans = std::max(ans, L + R);
    }
 
    std::cout << std::setprecision(6);
    std::cout << std::fixed << ans << "\n";
}
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}