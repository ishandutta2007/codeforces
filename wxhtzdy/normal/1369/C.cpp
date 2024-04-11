
#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n, k;
        std::cin >> n >> k;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i)
            std::cin >> a[i];
        std::sort(a.begin(), a.end());
        std::vector<int> w(k);
        for (int i = 0; i < k; ++i)
            std::cin >> w[i];
        std::sort(w.begin(), w.end());
        long long ans = 0;
        for (int i = n - k; i < n; ++i)
            ans += a[i];
        for (int i = 0, j = n - k; i < k; ++i) {
            j -= w[i] - 1;
            if (w[i] == 1) {
                ans += a[n - i - 1];
            } else {
                ans += a[j];
            }
        }
        std::cout << ans << "\n";
    }
    return 0;
}