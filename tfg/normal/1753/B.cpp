#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int n, x;
    std::cin >> n >> x;
    std::vector<int> freq(x+1, 0);
    for(int i = 0; i < n; i++) {
        int val;
        std::cin >> val;
        freq[val]++;
    }
    for(int i = 1; i < x; i++) {
        if(freq[i] % (i+1) != 0) {
            std::cout << "No\n";
            return 0;
        }
        freq[i+1] += freq[i] / (i+1);
        freq[i] = 0;
    }
    std::cout << "Yes\n";
}