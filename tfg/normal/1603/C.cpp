#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int brute(std::vector<int> a) {
    int ans = 0;
    for(int r = (int) a.size() - 1; r >= 0; r--) {
        int tot = 0;
        int last = 1e9;
        for(int l = r; l >= 0; l--) {
            int cost = (a[l] + last - 1) / last;
            int newValue = a[l] / cost;
            tot += cost-1;
            last = newValue;
            ans += tot;
        }
    }
    return ans;
}

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while(t--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        for(int i = 0; i < n; i++) {
            std::cin >> a[i];
        }
        const int MOD = 998244353;
        struct Info {
            int freq, cost, x;
        };
        std::vector<Info> prev;
        int ans = 0;
        for(int i = n-1; i >= 0; i--) {
            std::vector<Info> nxt;
            for(auto info : prev) {
                int x = info.x;
                // ceil(a[i] / N) <= x
                // a[i] / N <= x
                // N >= a[i] / x
                int cost = (a[i] + x - 1) / x;
                int newValue = a[i] / cost;
                if(nxt.empty() || nxt.back().x != newValue) {
                    nxt.push_back({0, 0, newValue});
                }
                nxt.back().freq += info.freq;
                nxt.back().cost = (int)(((long long) info.freq * (cost - 1) + info.cost + nxt.back().cost) % MOD);
            }
            if(nxt.empty() || nxt.back().x != a[i]) {
                nxt.push_back({0, 0, a[i]});
            }
            nxt.back().freq++;
            for(auto info : nxt) {
                ans = (ans + info.cost) % MOD;
            }
            prev = nxt;
        }
        std::cout << ans << '\n';
    }
}