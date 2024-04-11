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
    std::vector<std::pair<int, int>> ranges(n, std::pair<int, int>(n+1, -1));
    for(int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        x--;
        ranges[x].first = std::min(ranges[x].first, i);
        ranges[x].second = std::max(ranges[x].second, i);
    }
    std::vector<std::pair<int, int>> validRanges;
    for(auto [l, r] : ranges) {
        if(r != -1) {
            validRanges.emplace_back(l, r);
        }
    }
    std::sort(validRanges.begin(), validRanges.end());
    std::vector<std::pair<int, int>> outsiders;
    for(auto [l, r] : validRanges) {
        if(outsiders.empty() || outsiders.back().second < r) {
            if((int) outsiders.size() >= 2 && outsiders[(int) outsiders.size() - 2].second >= l) outsiders.pop_back();
            outsiders.emplace_back(l, r);
        }
    }
    int ans = (int) outsiders.size() * 2;
    for(auto [l, r] : outsiders) {
        if(l == r) ans--;
        //std::cout << "[" << l << ", " << r << "]\n";
    }
    for(int i = 0; i+1 < (int) outsiders.size(); i++) {
        if(outsiders[i].second >= outsiders[i+1].first) {
            ans--;
        }
    }
    ans = n - ans;
    std::cout << ans << '\n';
}