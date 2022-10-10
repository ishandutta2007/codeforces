#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const long long INF = 1.1e18;

long long safeMul(long long a, long long b) {
    if(a == 0 || b == 0) return 0;
    else if(INF / a / b == 0) return INF;
    else return a * b;
}

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while(t--) {
        int n;
        long long k, x;
        std::cin >> n >> k >> x;
        std::string str;
        std::cin >> str;
        std::vector<std::pair<char, int>> groups;
        for(int l = 0, r = 0; l < n; l = r) {
            while(r < n && str[l] == str[r]) r++;
            groups.emplace_back(str[l], r - l);
        }
        n = (int) groups.size();
        std::vector<long long> dp(n+1, 1);
        for(int i = n-1; i >= 0; i--) {
            dp[i] = dp[i+1];
            if(groups[i].first == '*') {
                dp[i] = safeMul(dp[i], k * groups[i].second + 1);
            }
        }
        x--;
        //std::cout << "dp[0] is " << dp[0] << ", x is " << x << std::endl;
        assert(dp[0] > x);
        std::string ans;
        for(int i = 0; i < n; i++) {
            if(groups[i].first == 'a') {
                ans += std::string(groups[i].second, 'a');
            } else {
                int use = (int) (x / dp[i+1]);
                x %= dp[i+1];
                ans += std::string(use, 'b');
            }
        }
        std::cout << ans << '\n';
    }
}