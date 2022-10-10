#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int n;
    std::cin >> n;
    std::vector<int> old;
    for(int i = 0; i < 3; i++) {
        std::vector<int> other(n-i);
        for(auto &x : other) std::cin >> x;
        std::sort(other.begin(), other.end());
        if(i) {
            int j = 0;
            while(j < (int) other.size() && other[j] == old[j]) j++;
            std::cout << old[j] << '\n';
        }
        old = other;
    }
}