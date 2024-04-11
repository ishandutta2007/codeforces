#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int tt;
    std::cin >> tt;
    while(tt--) {
        int n;
        std::string s, t;
        std::cin >> n >> s >> t;
        int ans = n+1;
        for(int rep = 0; rep < 2; rep++) {
            auto cur = s;
            int cost = 0;
            int freq[2] = {0, 0};
            if(rep) {
                freq[s[n-1]-'0']++;
                for(int i = 0; i+1 < n; i++) {
                    cur[i] ^= 1;
                }
                cost++;
            }
            int wtf = 0;
            for(int i = n-2; i >= 0; i--) if((cur[i] != cur[i+1]) != (t[i] != t[i+1])) {
                freq[s[i]-'0']++;
                cur[i] ^= 1;
                cost++;
                wtf ^= 1;
            }
            for(int i = 0; i < n; i++) {
                cur[i] ^= wtf;
            }
            if(cur == t && (freq[1] == freq[0] || freq[1] == freq[0] + 1)) {
                ans = std::min(ans, cost);
            }
        }
        std::cout << (ans == n+1 ? -1 : ans) << '\n';
    }
}