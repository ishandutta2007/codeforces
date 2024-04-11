#include <bits/stdc++.h>
 
using i64 = long long;
 
void solve() {
    int n, k;
    std::cin >> n >> k;
 
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
 
    std::vector<int> ord(n);
    std::iota(ord.begin(), ord.end(), 0);
    std::sort(ord.begin(), ord.end(), [&](int i, int j) { return a[i] < a[j]; });
 
    std::vector<int> pos(n);
    for (int i = 0; i < n; i++) {
        pos[ord[i]] = i;
    }
 
    int cnt = 1;
    for (int i = 1; i < n; i++) {
        if (pos[i] != pos[i - 1] + 1) cnt++;
    }
 
    std::cout << (cnt <= k ? "Yes\n" : "No\n");
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