#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <map>
#include <algorithm>

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
        if(u != anc) ans.emplace_back(in[anc] + 1, in[u] + 1);
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

const int ms = 300300;
std::map<long long, int> mp[ms];

struct Path {
    int u, v, lca;
    int other1, other2;

    template<class F>
    void applySets(F f) {
        f(lca, -1, 1);
        if(other1 >= 0) {
            f(lca, other1, -1);
        }
        if(other2 >= 0) {
            f(lca, other2, -1);
            f(lca, (long long) other1 * ms + other2, 1);
        }
    }
};

class SegmentTree {
public:
    void init(int _n) {
        n = _n;
        tree.resize(2 * n, 0);
    }
    
    void upd(int l, int r, int v) {
        for(l += n, r += n; l < r; l /= 2, r /= 2) {
            if(l & 1) tree[l++] += v;
            if(r & 1) tree[--r] += v;
        }
    }
    
    int qry(int pos) {
        int ans = 0;
        for(pos += n; pos > 0; pos /= 2) {
            ans += tree[pos];
        }
        return ans;
    }
    
private:
    int n;
    std::vector<int> tree;
};


int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int n;
    std::cin >> n;
    HLD tree;
    tree.init(n);
    for(int i = 1; i < n; i++) {
        int u, v;
        std::cin >> u >> v;
        u--;v--;
        tree.addEdge(u, v);
    }
    tree.setRoot(0);
    int m;
    std::cin >> m;
    auto getBelowEdge = [&](int u, int anc) {
        if(u == anc) return -1;
        return tree.getPathtoAncestor(u, anc).back().first;
    };
    std::vector<Path> paths;
    long long ans = 0;
    auto sumAndInsert = [&](int lca, long long hash, int val) {
        ans += val * mp[lca][hash]++;
    };
    SegmentTree st;
    st.init(n);
    for(int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        u--;v--;
        int lca = tree.getLCA(u, v);
        int other1 = getBelowEdge(u, lca), other2 = getBelowEdge(v, lca);
        if(other1 < other2) std::swap(other1, other2);
        paths.push_back({u, v, lca, other1, other2});
        paths.back().applySets(sumAndInsert);
        for(auto [l, r] : tree.getPathtoAncestor(u, lca)) st.upd(l, r, 1);
        for(auto [l, r] : tree.getPathtoAncestor(v, lca)) st.upd(l, r, 1);
    }
    std::sort(paths.begin(), paths.end(), [](auto v1, auto v2) { return v1.lca < v2.lca; });
    for(int ptL = 0, ptR = 0; ptL < m; ptL = ptR) {
        while(ptR < m && paths[ptR].lca == paths[ptL].lca) ptR++;
        for(int i = ptL; i < ptR; i++) {
            int u = paths[i].u, v = paths[i].v, lca = paths[i].lca;
            for(auto [l, r] : tree.getPathtoAncestor(u, lca)) st.upd(l, r, -1);
            for(auto [l, r] : tree.getPathtoAncestor(v, lca)) st.upd(l, r, -1);
        }
        for(int i = ptL; i < ptR; i++) {
            int u = paths[i].other1, v = paths[i].other2, lca = tree.in[paths[i].lca];
            ans += st.qry(lca);
            if(u > -1) {
                ans -= st.qry(u);
            }
            if(v > -1) {
                ans -= st.qry(v);
            }
        }
        for(int i = ptL; i < ptR; i++) {
            int u = paths[i].u, v = paths[i].v, lca = paths[i].lca;
            for(auto [l, r] : tree.getPathtoAncestor(u, lca)) st.upd(l, r, 1);
            for(auto [l, r] : tree.getPathtoAncestor(v, lca)) st.upd(l, r, 1);
        }
    }
    std::cout << ans << '\n';
}