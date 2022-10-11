#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while(t--) {
        std::string str, pat;
        std::cin >> str >> pat;
        if(pat != "abc") {
            std::sort(str.begin(), str.end());
        } else {
            std::sort(str.begin(), str.end());
            if(str[0] == 'a') std::sort(str.begin(), str.end(), [](char c1, char c2) {
                if((c1 == 'b' || c1 == 'c') && (c2 == 'b' || c2 == 'c')) return c1 > c2;
                else return c1 < c2;
            });
        }
        std::cout << str << '\n';
    }
}