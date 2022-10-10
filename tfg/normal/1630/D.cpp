#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while(t--) {
        int n, m;
        std::cin >> n >> m;
        int g = 0;
        std::vector<int> a(n);
        for(int i = 0; i < n; i++) {
            std::cin >> a[i];
        }
        long long ans = -1e18;
        while(m--) {
            int x;
            std::cin >> x;
            g = gcd(x, g);
        }
        for(int rep = 0; rep < 2; rep++) {
            long long sum = 0;
            for(int i = 0; i < g; i++) {
                bool bad = false;
                long long mn = 1e18;
                for(int j = i; j < n; j += g) {
                    long long v = std::max(a[j], -a[j]);
                    if(a[j] < 0) {
                        bad = !bad;
                    }
                    sum += v;
                    mn = std::min(mn, v);
                }
                if(bad) {
                    sum -= 2 * mn;
                }
            }
            ans = std::max(ans, sum);
            for(int i = 0; i < g; i++) {
                a[i] = -a[i];
            }
        }
        std::cout << ans << '\n';
    }
}