#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

class HLD {
public:
    void init(int n) {
        // this doesn't delete edges!
        sz.resize(n);
        in.resize(n);
        out.resize(n);
        rin.resize(n);
        p.resize(n);
        edges.resize(n);
        nxt.resize(n);
        h.resize(n);
    }

    void addEdge(int u, int v) {
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    void setRoot(int n) {
        t = 0;
        p[n] = n;
        h[n] = 0;
        prep(n, n);
        nxt[n] = n;
        hld(n);
    }

    int getLCA(int u, int v) {
        while(!inSubtree(nxt[u], v)) {
            u = p[nxt[u]];
        }
        while(!inSubtree(nxt[v], u)) {
            v = p[nxt[v]];
        }
        return in[u] < in[v] ? u : v;
    }

    bool inSubtree(int u, int v) {
        // is v in the subtree of u?
        return in[u] <= in[v] && in[v] < out[u];
    }

    std::vector<std::pair<int, int>> getPathtoAncestor(int u, int anc) {
        // returns ranges [l, r) that the path has
        std::vector<std::pair<int, int>> ans;
        //assert(inSubtree(anc, u));
        while(nxt[u] != nxt[anc]) {
            ans.emplace_back(in[nxt[u]], in[u] + 1);
            u = p[nxt[u]];
        }
        // this includes the ancestor!
        ans.emplace_back(in[anc], in[u] + 1);
        return ans;
    }
//private:
    std::vector<int> in, out, p, rin, sz, nxt, h;
    std::vector<std::vector<int>> edges;
    int t;

    void prep(int on, int par) {
        sz[on] = 1;
        p[on] = par;
        for(int i = 0; i < (int) edges[on].size(); i++) {
            int &u = edges[on][i];
            if(u == par) {
                std::swap(u, edges[on].back());
                edges[on].pop_back();
                i--;
            } else {
                h[u] = 1 + h[on];
                prep(u, on);
                sz[on] += sz[u];
                if(sz[u] > sz[edges[on][0]]) {
                    std::swap(edges[on][0], u);
                }
            }
        }
    }

    void hld(int on) {
        in[on] = t++;
        rin[in[on]] = on;
        for(auto u : edges[on]) {
            nxt[u] = (u == edges[on][0] ? nxt[on] : u);
            hld(u);
        }
        out[on] = t;
    }
};


int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int n;
    std::cin >> n;
    HLD hld;
    hld.init(n);
    for(int i = 1; i < n; i++) {
        int u, v;
        std::cin >> u >> v;
        hld.addEdge(u-1, v-1);
    }
    hld.setRoot(0);
    int q;
    std::cin >> q;
    while(q--) {
        int u, v;
        std::cin >> u >> v;
        u--;v--;
        int lca = hld.getLCA(u, v);
        int dist = hld.h[u] + hld.h[v] - 2 * hld.h[lca];
        if(dist % 2 == 1) {
            std::cout << "0\n";
            continue;
        } else if(dist == 0) {
            std::cout << n << '\n';
            continue;
        }
        // make u deepest
        if(hld.h[u] < hld.h[v]) {
            std::swap(u, v);
        }
        auto goUp = [&](int x, int up) {
            for(auto [l, r] : hld.getPathtoAncestor(x, 0)) {
                if(r - l <= up) {
                    up -= r - l;
                } else {
                    return hld.rin[r - 1 - up];
                }
            }
            return 0;
        };
        if(hld.h[u] == hld.h[v]) {
            std::cout << n - hld.sz[goUp(u, dist/2-1)] - hld.sz[goUp(v, dist/2-1)] << '\n';
        } else {
            std::cout << n - hld.sz[goUp(u, dist/2-1)] - (n - hld.sz[goUp(u, dist/2)]) << '\n';
        }
    }
}