#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 200200;

std::vector<int> edges[ms];
int sz[ms];

void prep(int on, int par) {
    sz[on] = 1;
    for(int i = 0; i < (int) edges[on].size(); i++) {
        int to = edges[on][i];
        if(to == par) {
            std::swap(edges[on][i], edges[on].back());
            edges[on].pop_back();
            i--;
            continue;
        }
        prep(to, on);
        sz[on] = std::max(sz[on], sz[to] + 1);
        if(sz[to] > sz[edges[on][0]]) {
            std::swap(edges[on][0], edges[on][i]);
        }
    }
}

std::vector<int> sizes;

void go(int on) {
    int got = 1;
    while(!edges[on].empty()) {
        got++;
        for(int i = 1; i < (int) edges[on].size(); i++) go(edges[on][i]);
        on = edges[on][0];
    }
    sizes.push_back(got);
}

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int n, k;
    std::cin >> n >> k;
    for(int i = 1; i < n; i++) {
        int u, v;
        std::cin >> u >> v;
        u--;v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    prep(0, 0);
    go(0);
    std::sort(sizes.rbegin(), sizes.rend());
    long long ans = (long long) - (n / 2) * (n - n / 2);
    int got = 0;
    auto cost = [&](int a, int b) { return (long long) (n - a - b) * (a - b); };
    sizes.resize(n+1, 0);
    for(int i = 0, j = n / 2; i < (int) sizes.size() && k > 0; i++) {
        k--;
        got += sizes[i];
        j = std::min(j, n - got);
        while(j < n - got && cost(i+1, j+1) < cost(i+1, j)) j++;
        while(j > 0 && cost(i+1, j-1) < cost(i+1, j)) j--;
        //std::cout << "(" << i+1 << ", " << j << ") cost " << cost(i+1, j) << '\n';
        ans = std::max(ans, cost(i+1, j));
    }

    std::cout << ans << '\n';
}