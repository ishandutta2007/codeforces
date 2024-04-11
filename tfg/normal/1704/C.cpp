#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int tt;
    std::cin >> tt;
    while(tt--) {
        int n, m;
        std::cin >> n >> m;
        std::vector<int> a(m);
        for(auto &x : a) {
            std::cin >> x;
            x--;
        }
        std::sort(a.begin(), a.end());
        std::vector<int> b(m);
        for(int i = 0; i+1 < m; i++) {
            b[i] = a[i+1] - a[i] - 1;
        }
        b[m-1] = a[0] - a[m-1] + n - 1;
        std::sort(b.rbegin(), b.rend());
        int ans = 0;
        int days = 0;
        for(int i = 0; i < (int) b.size(); i++) {
            int x = b[i];
            x -= 2 * days;
            if(x <= 0) break;
            if(x <= 2) {
                days++;
                ans++;
            } else if(x >= 3) {
                days += 2;
                ans += x - 1;
            }
        }
        std::cout << n - ans << '\n';
    }
}