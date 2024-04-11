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
        int n, r;
        std::cin >> n >> r;
        r--;
        std::vector<std::vector<int>> edges(n);
        for(int i = 1; i < n; i++) {
            int u, v;
            std::cin >> u >> v;
            u--;v--;
            edges[u].push_back(v);
            edges[v].push_back(u);
        }
        std::vector<int> p(n);
        bool alreadyGood = true;
        for(int i = 0; i < n; i++) {
            int x;
            std::cin >> x;
            x--;
            p[x] = i;
            alreadyGood = alreadyGood && x == i;
        }
        int center = 0;
        while(center < n && (int) edges[center].size() + 1 < n) center++;
        if(center == n || alreadyGood) {
            std::cout << "Alice\n";
            continue;
        }
        std::vector<bool> vis(n, false);
        int cyc = 0;
        int sz = 0;
        for(int i = 0; i < n; i++) if(!vis[i]) {
            cyc++;
            for(int j = i; !vis[j]; j = p[j]) vis[j] = true, sz++;
        }
        assert(sz == n);
        if(r == center) {
            // p[r] must be r
            if(p[r] != r) {
                std::cout << "Bob\n";
                continue;
            }
            // must find number of cycles, number of cycles must be different from the number of vertices
            // they must have different parities
            std::cout << ((cyc + n) % 2 == 1 ? "Alice\n" : "Bob\n");
        } else {
            if(p[r] == center || (n == 3 && p[center] == center)) {
                std::cout << "Bob\n";
                continue;
            }
            std::cout << ((cyc + n) % 2 == 0 || (cyc == n-1 && p[r] == r) ? "Alice\n" : "Bob\n");
        }
    }
}