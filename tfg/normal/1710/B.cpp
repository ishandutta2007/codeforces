#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int tt;
    std::cin >> tt;
    while(tt--) {
        int n, m;
        std::cin >> n >> m;
        std::vector<std::pair<int, int>> rain(n);
        std::vector<std::pair<int, int>> events;
        std::vector<int> uni;
        for(auto &[x, p] : rain) {
            std::cin >> x >> p;
            events.emplace_back(x - p, +1);
            events.emplace_back(x, -2);
            events.emplace_back(x + p, +1);
            uni.push_back(x - p);
            uni.push_back(x);
            uni.push_back(x + p);
        }
        std::sort(uni.begin(), uni.end());
        auto getId = [&](int x) { return std::lower_bound(uni.begin(), uni.end(), x) - uni.begin(); };
        std::sort(events.begin(), events.end());
        int last = 0, slope = 0;
        long long f = 0;
        const long long INF = 1e18;
        std::vector<long long> left(uni.size(), -INF), right(uni.size(), -INF);
        for(auto [x, t] : events) {
            f += (long long) slope * (x - last);
            if(last != x && f > m) {
                int id = getId(x);
                left[id] = std::max(left[id], -m + f - x);
                right[id] = std::max(right[id], -m + f + x);
            }
            last = x;
            slope += t;
        }
        for(int i = (int) uni.size() - 2; i >= 0; i--) {
            right[i] = std::max(right[i], right[i+1]);
        }
        for(int i = 1; i < (int) uni.size(); i++) {
            left[i] = std::max(left[i], left[i-1]);
        }
        for(auto [x, p] : rain) {
            int id = getId(x);
            if(p - x >= left[id] && p + x >= right[id]) {
                std::cout << '1';
            } else {
                std::cout << '0';
            }
        }
        std::cout << '\n';
    }
}