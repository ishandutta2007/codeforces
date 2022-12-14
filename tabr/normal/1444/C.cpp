#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

class BSTNode {
   public:
    const int from, to;
    int sz;
    bool subtree_edge, subofftree_edge, exact_level;
    BSTNode *left, *right, *par;
    unordered_set<int> adjacent;
    BSTNode(const int _ver) noexcept : from(_ver), to(_ver), sz(1), subtree_edge(false), subofftree_edge(false), exact_level(false), left(nullptr), right(nullptr), par(nullptr) {}
    BSTNode(const int _from, const int _to, const bool _flag) noexcept : from(_from), to(_to), sz(0), subtree_edge(false), subofftree_edge(false), exact_level((from < to) && _flag), left(nullptr), right(nullptr), par(nullptr) {}
    inline bool IsRoot() const noexcept { return !par; }
    inline bool IsVertex() const noexcept { return (from == to); }
    inline void eval() noexcept {
        if (IsVertex())
            sz = 1, subtree_edge = false, subofftree_edge = !adjacent.empty();
        else
            sz = 0, subtree_edge = exact_level, subofftree_edge = false;
        if (left) {
            sz += left->sz, subtree_edge |= left->subtree_edge, subofftree_edge |= left->subofftree_edge;
        }
        if (right) {
            sz += right->sz, subtree_edge |= right->subtree_edge, subofftree_edge |= right->subofftree_edge;
        }
    }
    inline void subtree_edge_eval() {
        subtree_edge = exact_level;
        if (left) subtree_edge |= left->subtree_edge;
        if (right) subtree_edge |= right->subtree_edge;
    }
    inline void subofftree_edge_eval() {
        subofftree_edge = !adjacent.empty();
        if (left) subofftree_edge |= left->subofftree_edge;
        if (right) subofftree_edge |= right->subofftree_edge;
    }
    inline bool subofftree_check() {
        return !adjacent.empty() ||
               (left ? left->subofftree_edge : false) || (right ? right->subofftree_edge : false);
    }
    inline bool offtree_check() {
        return adjacent.empty() ||
               (left ? left->subofftree_edge : false) || (right ? right->subofftree_edge : false);
    }
    void rotate(const bool right_) noexcept {
        BSTNode *p = par, *g = p->par;
        if (right_) {
            if ((p->left = right)) right->par = p;
            right = p, p->par = this;
        } else {
            if ((p->right = left)) left->par = p;
            left = p, p->par = this;
        }
        p->eval(), eval();
        if (!(par = g)) return;
        if (g->left == p) g->left = this;
        if (g->right == p) g->right = this;
        g->eval();
    }
};

BSTNode *splay(BSTNode *u) noexcept {
    if (!u) return nullptr;
    while (!(u->IsRoot())) {
        BSTNode *p = u->par, *gp = p->par;
        if (p->IsRoot()) {
            u->rotate((u == p->left));
        } else {
            bool flag = (u == p->left);
            if ((u == p->left) == (p == gp->left)) {
                p->rotate(flag), u->rotate(flag);
            } else {
                u->rotate(flag), u->rotate(!flag);
            }
        }
    }
    return u;
}

BSTNode *join(BSTNode *root1, BSTNode *root2) noexcept {
    if (!root1 || !root2) return root1 ? root1 : root2;
    BSTNode *cur = nullptr, *nx = root1;
    do {
        cur = nx, nx = cur->right;
    } while (nx);
    BSTNode *ver = splay(cur);
    ver->right = root2, ver->eval(), root2->par = ver;
    return ver;
}

class EulerTourTree {
   public:
    struct pair_hash {
        template <class T1, class T2>
        size_t operator()(const pair<T1, T2> &p) const {
            size_t lhs = hash<T1>()(p.first), rhs = hash<T2>()(p.second);
            return lhs ^ (rhs + 0x9e3779b9 + (lhs << 6) + (lhs >> 2));
        }
    };
    const int V;
    BSTNode **vertex_set;
    unordered_map<pair<int, int>, pair<BSTNode *, BSTNode *>, pair_hash> edge_set;

   private:
    void dfs(const int u, const int p, const BSTNode *cur,
             bool *visit, vector<BSTNode *> &nodes, const vector<vector<int>> &G) noexcept {
        visit[u] = true;
        nodes.push_back(vertex_set[u]);
        for (auto &v : G[u]) {
            if (!visit[v]) {
                BSTNode *e1 = new BSTNode(u, v, true);
                nodes.push_back(e1);
                dfs(v, u, cur, visit, nodes, G);
                BSTNode *e2 = new BSTNode(v, u, true);
                if (u < v)
                    edge_set[{u, v}] = {e1, e2};
                else
                    edge_set[{v, u}] = {e2, e1};
                nodes.push_back(e2);
            } else if (v != p) {
                vertex_set[u]->adjacent.insert(v);
                vertex_set[u]->subofftree_edge = true;
            }
        }
    }
    void bst_build(vector<BSTNode *> &nodes) noexcept {
        int i, n = (int)nodes.size(), st = 2, isolate = ((n % 4 == 1) ? (n - 1) : -1);
        while (st <= n) {
            for (i = st - 1; i < n; i += 2 * st) {
                nodes[i]->left = nodes[i - st / 2], nodes[i - st / 2]->par = nodes[i];
                if (i + st / 2 < n)
                    nodes[i]->right = nodes[i + st / 2], nodes[i + st / 2]->par = nodes[i];
                else if (isolate >= 0)
                    nodes[i]->right = nodes[isolate], nodes[isolate]->par = nodes[i];
                nodes[i]->eval();
            }
            isolate = ((n % (4 * st) >= st && (n % (4 * st) < 2 * st)) ? (i - 2 * st) : isolate);
            st <<= 1;
        }
    }
    void build_forest(const vector<vector<int>> &G) {
        bool *visit = new bool[V]();
        for (int i = 0; i < V; ++i) {
            if (!visit[i]) {
                vector<BSTNode *> nodes;
                BSTNode *cur = nullptr;
                dfs(i, -1, cur, visit, nodes, G);
                bst_build(nodes);
            }
        }
    }
    BSTNode *reroot(BSTNode *ver) noexcept {
        BSTNode *res = splay(ver)->left;
        if (!res) return ver;
        ver->left = nullptr, ver->eval();
        while (ver->right) ver = ver->right;
        splay(ver), ver->right = res, ver->eval(), res->par = ver;
        return ver;
    }
    void link(BSTNode *ver1, BSTNode *ver2, const bool flag) noexcept {
        BSTNode *e1 = new BSTNode(ver1->from, ver2->from, flag);
        BSTNode *e2 = new BSTNode(ver2->from, ver1->from, flag);
        edge_set[{ver1->from, ver2->from}] = {e1, e2};
        join(join(reroot(ver1), e1), join(reroot(ver2), e2));
    }
    void cut(BSTNode *edge1, BSTNode *edge2) noexcept {
        splay(edge1), splay(edge2);
        BSTNode *p = edge1->par;
        bool _right = (edge1 == edge2->right);
        if (p != edge2) {
            _right = (p == edge2->right);
            p->par = nullptr, edge1->rotate((edge1 == p->left));
        }
        if (edge1->left) edge1->left->par = nullptr;
        if (edge1->right) edge1->right->par = nullptr;
        if (_right) {
            if (edge2->left) edge2->left->par = nullptr;
            join(edge2->left, edge1->right);
        } else {
            if (edge2->right) edge2->right->par = nullptr;
            join(edge1->left, edge2->right);
        }
        delete edge1;
        delete edge2;
    }
    bool connected(BSTNode *ver1, BSTNode *ver2) noexcept {
        splay(ver1), splay(ver2);
        return ver1->par;
    }
    int component_size(BSTNode *ver) noexcept { return splay(ver)->sz; }

   public:
    EulerTourTree(const int node_size) : V(node_size), vertex_set(new BSTNode *[V]) {
        for (int i = 0; i < V; i++) vertex_set[i] = new BSTNode(i);
    }
    EulerTourTree(const vector<vector<int>> &G) : V((int)G.size()), vertex_set(new BSTNode *[V]) {
        for (int i = 0; i < V; i++) vertex_set[i] = new BSTNode(i);
        build_forest(G);
    }
    // ~EulerTourTree(){
    //     for(auto it : edge_set){
    //         delete (it.second).first;
    //         delete (it.second).second;
    //     }
    //     for(int i = 0; i < V; ++i) delete vertex_set[i];
    //     delete[] vertex_set;
    // }
    void reroot(const int node_id) noexcept { reroot(vertex_set[node_id]); }
    void link(int node1_id, int node2_id, bool flag = true) noexcept {
        if (node1_id > node2_id) swap(node1_id, node2_id);
        link(vertex_set[node1_id], vertex_set[node2_id], flag);
    }
    void cut(int node1_id, int node2_id) {
        if (node1_id > node2_id) swap(node1_id, node2_id);
        auto it = edge_set.find({node1_id, node2_id});
        assert(it != edge_set.end());
        BSTNode *edge1 = (it->second).first, *edge2 = (it->second).second;
        edge_set.erase(it);
        cut(edge1, edge2);
    }
    bool connected(const int node1_id, const int node2_id) noexcept {
        if (node1_id == node2_id) return true;
        return connected(vertex_set[node1_id], vertex_set[node2_id]);
    }
    int component_size(int node_id) noexcept { return component_size(vertex_set[node_id]); }
    void check_dfs(const BSTNode *cur) const noexcept {
        if (cur->left) check_dfs(cur->left);
        cout << "{" << (cur->from) << "," << (cur->to) << "} ";
        if (cur->right) check_dfs(cur->right);
    }
};

class DynamicConnectivity {
   private:
    BSTNode *level_up_dfs(BSTNode *cur, const int layer) noexcept {
        if (cur->exact_level) {
            splay(cur)->exact_level = false, cur->subtree_edge_eval();
            detect_layer[{cur->from, cur->to}]++, et[layer + 1].link(cur->from, cur->to);
            return cur;
        }
        if (cur->left && cur->left->subtree_edge) return level_up_dfs(cur->left, layer);
        if (cur->right && cur->right->subtree_edge) return level_up_dfs(cur->right, layer);
        return nullptr;
    }
    BSTNode *search_edge_dfs(BSTNode *cur, const int layer, const int another, bool &flag, pair<int, int> &rep_edge) noexcept {
        if (!cur->adjacent.empty()) {
            bool state = et[layer + 1].vertex_set[cur->from]->adjacent.empty();
            for (auto it = cur->adjacent.begin(); it != cur->adjacent.end();) {
                pair<int, int> e = {min(cur->from, *it), max(cur->from, *it)};
                BSTNode *correspond = et[layer].vertex_set[*it];
                if (et[layer].connected(another, *it)) {
                    flag = true, rep_edge = e;
                    cur->adjacent.erase(it), correspond->adjacent.erase(cur->from);
                    if (!correspond->subofftree_check()) {
                        splay(correspond)->subofftree_edge_eval();
                    }
                    break;
                } else {
                    if (!et[layer + 1].vertex_set[*it]->subofftree_check()) {
                        splay(et[layer + 1].vertex_set[*it])->subofftree_edge = true;
                    }
                    et[layer + 1].vertex_set[cur->from]->adjacent.insert(*it);
                    et[layer + 1].vertex_set[*it]->adjacent.insert(cur->from);
                    detect_layer[e]++, it = cur->adjacent.erase(it);
                    correspond->adjacent.erase(cur->from);
                    if (!correspond->subofftree_check()) {
                        splay(correspond)->subofftree_edge_eval();
                    }
                }
            }
            if (state && !et[layer + 1].vertex_set[cur->from]->offtree_check()) {
                splay(et[layer + 1].vertex_set[cur->from])->subofftree_edge = true;
            }
            splay(cur)->subofftree_edge_eval();
            return cur;
        }
        if (cur->left && cur->left->subofftree_edge) {
            return search_edge_dfs(cur->left, layer, another, flag, rep_edge);
        }
        if (cur->right && cur->right->subofftree_edge) {
            return search_edge_dfs(cur->right, layer, another, flag, rep_edge);
        }
        return nullptr;
    }
    bool replace(const int from, const int to, const int layer) noexcept {
        if (layer < 0) return true;
        int u, v;
        if (et[layer].component_size(from) <= et[layer].component_size(to))
            u = from, v = to;
        else
            u = to, v = from;
        BSTNode *ver = splay(et[layer].vertex_set[u]);
        while (ver->subtree_edge) ver = level_up_dfs(ver, layer);
        pair<int, int> rep_edge = {-1, -1};
        bool flag = false;
        while (ver->subofftree_edge) {
            ver = search_edge_dfs(ver, layer, v, flag, rep_edge);
            if (flag) break;
        }
        if (flag) {
            et[layer].link(rep_edge.first, rep_edge.second);
            for (int i = 0; i < layer; i++) et[i].link(rep_edge.first, rep_edge.second, false);
            return false;
        } else
            return replace(from, to, layer - 1);
    }

   public:
    const int V;
    int depth;
    vector<EulerTourTree> et;
    unordered_map<pair<int, int>, int, EulerTourTree::pair_hash> detect_layer;
    DynamicConnectivity(const int node_size) noexcept : V(node_size), depth(1) {
        et.emplace_back(V);
    }
    DynamicConnectivity(const vector<vector<int>> &G) noexcept : V((int)G.size()), depth(1) {
        for (int i = 0; i < V; ++i) {
            for (const int j : G[i]) {
                if (i < j) detect_layer[{i, j}] = 0;
            }
        }
        et.emplace_back(G);
    }
    bool link(int node1_id, int node2_id) noexcept {
        if (node1_id > node2_id) swap(node1_id, node2_id);
        detect_layer[{node1_id, node2_id}] = 0;
        if (et[0].connected(node1_id, node2_id)) {
            BSTNode *ver1 = et[0].vertex_set[node1_id], *ver2 = et[0].vertex_set[node2_id];
            splay(ver1)->subofftree_edge = true, ver1->adjacent.insert(node2_id);
            splay(ver2)->subofftree_edge = true, ver2->adjacent.insert(node1_id);
            return false;
        } else {
            et[0].link(node1_id, node2_id);
            return true;
        }
    }
    bool cut(int node1_id, int node2_id) noexcept {
        if (node1_id > node2_id) swap(node1_id, node2_id);
        auto it = detect_layer.find({node1_id, node2_id});
        assert(it != detect_layer.end());
        int layer = it->second;
        detect_layer.erase(it);
        auto &st = et[layer].vertex_set[node1_id]->adjacent;
        if (st.find(node2_id) == st.end()) {
            for (int i = 0; i <= layer; i++) et[i].cut(node1_id, node2_id);
            if (layer + 1 == depth) ++depth, et.emplace_back(V);
            return replace(node1_id, node2_id, layer);
        } else {
            et[layer].vertex_set[node1_id]->adjacent.erase(node2_id);
            if (!et[layer].vertex_set[node1_id]->subofftree_check()) {
                splay(et[layer].vertex_set[node1_id])->subofftree_edge_eval();
            }
            et[layer].vertex_set[node2_id]->adjacent.erase(node1_id);
            if (!et[layer].vertex_set[node2_id]->subofftree_check()) {
                splay(et[layer].vertex_set[node2_id])->subofftree_edge_eval();
            }
            return false;
        }
    }
    bool connected(const int node1_id, const int node2_id) noexcept {
        return et[0].connected(node1_id, node2_id);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> c(n);
    vector<vector<int>> s(k);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        c[i]--;
        s[c[i]].emplace_back(i);
    }
    vector<vector<int>> g(n);
    map<pair<int, int>, vector<pair<int, int>>> mp;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
        if (c[x] != c[y]) {
            if (c[x] > c[y]) {
                swap(x, y);
            }
            mp[make_pair(c[x], c[y])].emplace_back(x, y);
        }
    }
    // dsu uf(2 * n);
    DynamicConnectivity uf(2 * n);
    long long ans = 1LL * k * (k - 1) / 2;
    long long t = 0;
    vector<bool> b(k);
    for (int i = 0; i < k; i++) {
        if (s[i].empty()) {
            continue;
        }
        bool ok = true;
        for (int v : s[i]) {
            for (int to : g[v]) {
                if (c[v] == c[to]) {
                    uf.link(v + n, to);
                    uf.link(v, to + n);
                }
            }
            if (uf.connected(v, v + n)) {
                ok = false;
                break;
            }
        }
        if (!ok) {
            b[i] = true;
            t++;
            continue;
        }
    }
    ans -= t * (t - 1) / 2 + t * (k - t);
    for (auto e : mp) {
        auto p = e.first;
        if (b[p.first] || b[p.second]) {
            continue;
        }
        int x = 0;
        for (auto q : e.second) {
            uf.link(q.first, q.second + n);
            uf.link(q.first + n, q.second);
            x++;
            if (uf.connected(q.first, q.first + n)) {
                ans--;
                break;
            }
        }
        for (auto q : e.second) {
            uf.cut(q.first, q.second + n);
            uf.cut(q.first + n, q.second);
            x--;
            if (!x) {
                break;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}