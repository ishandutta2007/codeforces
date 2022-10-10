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
        int one = 0;
        int zero = (int) str.size()-1;
        for(int i = 0; i < (int) str.size(); i++) {
            if(str[i] == '1') {
                one = std::max(one, i);
            } else if(str[i] == '0') {
                zero = std::min(zero, i);
            }
        }
        std::cout << zero - one + 1 << '\n';
    }
}