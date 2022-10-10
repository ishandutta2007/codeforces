#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 100100;

int vis[ms];
bool good[ms];

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<std::pair<int, int>>> edges(n);
    while(m--) {
        int u, v, c;
        std::cin >> u >> v >> c;
        u--;v--;
        edges[u].emplace_back(v, c);
        edges[v].emplace_back(u, c);
    }
    std::cin >> m;
    struct Query {
        int u, v, ans;
        void read() {
            ans = 2;
            std::cin >> u >> v;
            u--;v--;
        }
    };
    std::vector<Query> queries(m);
    for(int i = 0; i < m; i++) {
        queries[i].read();
    }
    auto go = [&](int mask) {
        for(int i = 0; i < n; i++) {
            vis[i] = 0;
            good[i+1] = false;
        }
        int c = 1;
        for(int i = 0; i < n; i++) if(vis[i] == 0) {
            std::vector<int> q(1, i);
            vis[i] = c;
            int tot = ~0;
            for(int j = 0; j < (int) q.size(); j++) {
                int on = q[j];
                for(auto [to, cost] : edges[on]) if((cost & mask) == mask) {
                    if(!vis[to]) {
                        q.push_back(to);
                        vis[to] = c;
                    }
                    tot &= cost;
                }
            }
            for(auto on : q) for(auto [to, cost] : edges[on]) {
                good[c] = good[c] || (cost & tot) == 0;
            }
            c++;
        }
        for(auto &[u, v, ans] : queries) {
            if(vis[u] == vis[v]) {
                ans = 0;
            } else if(good[vis[u]] && mask != 1) {
                ans = std::min(ans, 1);
            }
        }
    };
    const int me = 30;
    for(int i = 0; i < me; i++) {
        go(1 << i);
    }
    for(int i = 0; i < m; i++) {
        std::cout << queries[i].ans << '\n';
    }
}