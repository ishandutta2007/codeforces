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
        std::cin >> str;
        std::vector<int> f(26);
        for(auto ch : str) f[ch - 'a']++;
        int x = 0;
        while(f[str[x] - 'a'] > 1) {
            f[str[x++] - 'a']--;
        }
        std::cout << str.substr(x, (int) str.size() - x) << '\n';
    }
}