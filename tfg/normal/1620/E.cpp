#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int q;
    std::cin >> q;
    std::vector<std::pair<int, int>> a(q);
    for(int i = 0; i < q; i++) {
        int t, x, y;
        std::cin >> t >> x;
        if(t == 1) {
            a[i] = {x, -1};
        } else {
            std::cin >> y;
            a[i] = {x, y};
        }
    }
    const int ms = 500500;
    std::vector<int> to(ms);
    for(int i = 0; i < ms; i++) to[i] = i;
    for(int i = q-1; i >= 0; i--) {
        if(a[i].second == -1) {
            a[i].first = to[a[i].first];
        } else {
            to[a[i].first] = to[a[i].second];
        }
    }
    for(int i = 0; i < q; i++) {
        if(a[i].second == -1) {
            std::cout << a[i].first << ' ';
        }
    }
    std::cout << '\n';
}