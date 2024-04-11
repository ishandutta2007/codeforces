#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    std::string s;
    std::cin >> s;
    int f = 0;
    if(s.back() == 'A') {
        std::cout << "NO\n";
        return;
    }
    for(auto ch : s) {
        if(ch == 'A') {
            f++;
        } else if(f) {
            f--;
        } else {
            std::cout << "NO\n";
            return;
        }
    }
    std::cout << "YES\n";
}

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while(t--) {
        solve();
    }
}