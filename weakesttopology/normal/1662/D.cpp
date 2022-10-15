#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

std::string reduce(std::string str) {
    int parity = 0;
    std::string ans = "B";
    for(auto ch : str) {
        if(ch == 'B') {
            parity ^= 1;
        } else {
            if(ans.back() == ch) {
                ans.pop_back();
            } else {
                ans += ch;
            }
        }
    }
    if(parity) {
        ans += 'B';
    }
    return ans;
}

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int tt;
    std::cin >> tt;
    while(tt--) {
        std::string s, t;
        std::cin >> s >> t;
        std::cout << (reduce(s) == reduce(t) ? "YES\n" : "NO\n");
    }
}