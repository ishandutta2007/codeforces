#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::vector<int> b(n);
    const int bs = 330;
    int ans = n-1;
    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for(int i = -bs; i <= bs; i++) {
        for(int j = 0; j < n; j++) {
            b[j] = a[j] + i * j;
        }
        std::sort(b.begin(), b.end());
        int mx = 0;
        for(int l = 0, r = 0; l < n; l = r) {
            while(r < n && b[l] == b[r]) r++;
            mx = std::max(mx, r-l);
        }
        ans = std::min(ans, n-mx);
    }
    for(int i = 0; i < n; i++) {
        int sz = 0;
        for(int j = std::max(0, i-bs); j < n && j <= i+bs; j++) {
            if(i != j && (a[j] - a[i]) % (j-i) == 0) {
                b[sz++] = (a[j] - a[i]) / (j-i);
            }
        }
        std::sort(b.begin(), b.begin() + sz);
        int mx = 0;
        for(int l = 0, r = 0; l < sz; l = r) {
            while(r < sz && b[l] == b[r]) r++;
            mx = std::max(mx, r-l);
        }
        ans = std::min(ans, n-mx-1);
    }
    std::cout << ans << '\n';
}