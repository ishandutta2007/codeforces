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
        std::string str;
        int n;
        std::cin >> n >> str;
        long long ans = (int) str.size();
        for(int i = 1; i < (int) str.size(); i++) {
            if(str[i] != str[i-1]) {
                ans += i;
            }
        }
        std::cout << ans << '\n';
    }
}