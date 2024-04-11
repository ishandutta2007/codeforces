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
        int n, m;
        std::string s, t;
        std::cin >> n >> m >> s >> t;
        bool got = false;
        for(int i = 0; i <= (n-m); i++) {
            got = got || s[i] == t[0];
        }
        std::cout << (got && s.substr(n-m+1) == t.substr(1) ? "YES\n" : "NO\n");
    }
}