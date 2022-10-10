#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while(t--) {
        int n;
        std::cin >> n;
        std::vector<int> par(n);
        for(int i = 1; i < n; i++) {
            std::cin >> par[i];
            par[i]--;
        }
        std::vector<long long> l(n, 0), r(n, 0), wantL(n), wantR(n);
        std::vector<int> dp(n);
        for(int i = 0; i < n; i++) {
            std::cin >> wantL[i] >> wantR[i];
        }
        for(int i = n-1; i >= 0; i--) {
            assert(l[i] <= r[i]);
            assert(l[i] == 0);
            if(wantL[i] <= r[i]) {
                // can do it without extra thing
                r[i] = std::min(r[i], wantR[i]);
            } else {
                // has to use extra thing
                r[i] = wantR[i];
                dp[i]++;
            }
            if(i) {
                dp[par[i]] += dp[i];
                r[par[i]] += r[i];
            }
        }
        std::cout << dp[0] << '\n';
    }
}