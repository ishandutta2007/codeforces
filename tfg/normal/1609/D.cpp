#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

struct DSU {
    int getSize(int x) { return -par[getPar(x)]; }
    int getPar(int x) {
        while(par[x] >= 0) {
            x = par[x];
        }
        return x;
    }
 
    bool makeUnion(int a, int b) {
        a = getPar(a), b = getPar(b);
        if(a == b) return false;
        if(par[a] > par[b]) std::swap(a, b);
        op.emplace_back(a, par[a]);
        op.emplace_back(b, par[b]);
        par[a] += par[b];
        par[b] = a;
        return true;
    }
 
    void init(int n) {
        par.resize(n);
        for(int i = 0; i < n; i++) {
            par[i] = -1;
        }
        op.clear();
    }
 
    void rollBack() {
        par[op.back().first] = op.back().second;
        op.pop_back();
    }
 
    std::vector<int> par;
    std::vector<std::pair<int, int>> op;
};

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int n, d;
    std::cin >> n >> d;
    DSU dsu;
    dsu.init(n);
    int extra = 0;
    while(d--) {
        int u, v;
        std::cin >> u >> v;
        u--;v--;
        if(!dsu.makeUnion(u, v)) {
            extra++;
        }
        std::vector<int> sizes;
        for(int i = 0; i < n; i++) {
            if(dsu.getPar(i) == i) {
                sizes.push_back(dsu.getSize(i));
            }
        }
        std::sort(sizes.rbegin(), sizes.rend());
        int ans = 0;
        for(int i = 0; i <= extra && i < (int) sizes.size(); i++) {
            ans += sizes[i];
        }
        std::cout << ans - 1 << '\n';
    }
}