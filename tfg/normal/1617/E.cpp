#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

struct Info {
    int x, y, cost;
    int size, id;
};

Info solve(const std::vector<std::vector<int>> &a, int l, int r, int h) {
    if(l + 1 == r) {
        return Info({-1, -1, -1, (int) a[l].size() - 1, -a[l].back()});
    }
    Info best = Info({-1, -1, -1, -100, -1});
    for(int i = l; i < r; i++) assert((int) a[i].size() > h);
    for(int i = l, j = l; i < r; i = j) {
        while(j < r && a[i][h] == a[j][h]) j++;
        auto got = solve(a, i, j, h+1);
        if(got.size + best.size - 2 * h >= best.cost) {
            best.x = best.id, best.y = got.id, best.cost = got.size + best.size - 2 * h;
        }
        if(got.cost >= best.cost) {
            best.x = got.x, best.y = got.y, best.cost = got.cost;
        }
        if(got.size > best.size) {
            best.size = got.size, best.id = got.id;
        }
    }
    return best;
}

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> a(n);
    for(int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        std::vector<int> vec;
        for(int j = 29; j >= 0; j--) if(x & (1 << j)) {
            if(x == (1 << j)) {
                vec.push_back(j);
            } else {
                vec.push_back(j+1);
            }
            x = (1 << vec.back()) - x;
            assert(x < (1 << j));
        }
        assert(x == 0);
        std::reverse(vec.begin(), vec.end());
        vec.push_back(-(i+1));
        a[i] = vec;
    }
    std::sort(a.begin(), a.end());
    auto ans = solve(a, 0, n, 0);
    std::cout << ans.x << ' ' << ans.y << ' ' << ans.cost << '\n';
}