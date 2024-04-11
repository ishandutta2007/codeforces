#include <bits/stdc++.h>
using namespace std;
 
class Solver {
    using wgt = long long;
 
    class IntervalTree {
        using wgt = long long;
 
        static constexpr wgt no_val = -(1LL<<60);
 
        struct node {
            wgt val, add;
        };
 
        int b;
        vector<node> T;
 
        inline __attribute__((always_inline)) void upd(int i, bool leaf) {
            wgt add = T[i].add;
            if(add == 0) return;
            T[i].val += add;
            T[i].add = 0;
            if(!leaf) {
                T[2*i].add += add;
                T[2*i+1].add += add;
            }
        }
 
        void get_internal(int l, int r, int i, int n_l, int n_r, wgt & max_val) {
            if(n_l >= r || l >= n_r) return;
            upd(i, n_l+1 == n_r);
            if((n_l == l && n_r == r) || T[i].val <= max_val) {
                max_val = max(max_val, T[i].val);
                return;
            }
            int c = (n_l + n_r) / 2;
            get_internal(l, min(r, c), 2*i, n_l, c, max_val);
            get_internal(max(l, c), r, 2*i+1, c, n_r, max_val);
        }
 
      public:
        IntervalTree() {}
 
        IntervalTree(int N) {
            b = 1;
            while(b < N) b *= 2;
            T.resize(2*b+1, {0, 0});
        }
 
        void add(int l, int r, wgt w_add, int i = 1, int n_l = 0, int n_r = 0) {
            if(i == 1) n_r = b;
            if(n_l == l && n_r == r) {
                T[i].add += w_add;
                upd(i, n_l+1 == n_r);
                return;
            }
            upd(i, n_l+1 == n_r);
            if(n_l >= r || l >= n_r) return;
            int c = (n_l + n_r) / 2;
            add(l, min(r, c), w_add, 2*i, n_l, c);
            add(max(l, c), r, w_add, 2*i+1, c, n_r);
            T[i].val = max(T[2*i].val, T[2*i+1].val);
        }
 
        void put(int pos, wgt w, int i = 1, int n_l = 0, int n_r = 0) {
            if(i == 1) n_r = b;
            if(n_l == pos && n_r == pos+1) {
                T[i].val = w;
                T[i].add = 0;
                return;
            }
            upd(i, n_l+1 == n_r);
            if(n_l > pos || pos >= n_r) return;
            int c = (n_l + n_r) / 2;
            if(pos < c) {
                upd(2*i+1, c+1 == n_r);
                put(pos, w, 2*i, n_l, c);
            }
            else {
                upd(2*i, n_l+1 == c);
                put(pos, w, 2*i+1, c, n_r);
            }
            T[i].val = max(T[2*i].val, T[2*i+1].val);
        }
 
        pair<wgt, int> get(int l, int r, bool with_id = false) { // max [l..r)
            wgt ret = no_val;
            get_internal(l, r, 1, 0, b, ret);
            if(!with_id) return {ret, 0};
            int cur = 1, n_l = 0, n_r = b;
            while(n_l+1 != n_r) {
                int c = (n_l + n_r) / 2;
                upd(2*cur, n_l+1 == c);
                if(T[2*cur].val == ret) {
                    cur = 2*cur;
                    n_r = c;
                }
                else {
                    upd(2*cur+1, c+1 == n_r);
                    n_l = c;
                    cur = 2*cur+1;
                }
            }
            return {ret, n_l};
        }
 
        wgt get_pos(int pos) { // max [pos]
            int cur = 1, n_l = 0, n_r = b;
            while(true) {
                upd(cur, n_l+1 == n_r);
                if(n_l+1 == n_r) {
                    return T[cur].val;
                    break;
                }
                int c = (n_l + n_r) / 2;
                if(pos < c) {
                    n_r = c;
                    cur = 2*cur;
                }
                else {
                    n_l = c;
                    cur = 2*cur+1;
                }
            }
            return no_val;
        }
    };
 
    int N, R, P; // R = root, P = number of paths
    vector<int> par;
    vector< vector<int> > G; // sons
    vector< pair<int, int> > interval_renumbering;
    vector<int> v_from_interval_id;
    vector<int> subtree_size;
    vector< vector<int> > paths;
    vector<int> path_id, path_pos; // paths[path_id[i]][path_pos[i]] == i
    vector< vector< vector< pair<int, int> > > > down_edges; // light edges (child, index in tree) + dummy self-loops
    vector<int> down_edge_id;
    vector< vector<int> > last_down_edge; // largest index of light edge from (parent) + 1
 
    vector<wgt> W;
    IntervalTree max_dist_down;
    vector<IntervalTree> tree_over_path;
 
    void DFS_construct(int v, const vector< vector< pair<int, wgt> > > & G_) {
        interval_renumbering[v].second = interval_renumbering[v].first+1;
        v_from_interval_id[interval_renumbering[v].first] = v;
        subtree_size[v] = 1;
        int max_subtree_size = 0, son_in_path = -1;
        for(auto p : G_[v]) if(par[p.first] == -1) {
            int w = p.first;
            par[w] = v;
            G[v].push_back(w);
            W[w] = p.second;
            interval_renumbering[w].first = interval_renumbering[v].second;
            DFS_construct(w, G_);
            interval_renumbering[v].second = interval_renumbering[w].second;
            max_dist_down.add(interval_renumbering[w].first, interval_renumbering[w].second, p.second);
            subtree_size[v] += subtree_size[w];
            if(subtree_size[w] > max_subtree_size) {
                max_subtree_size = subtree_size[w];
                son_in_path = w;
            }
        }
        if(son_in_path == -1) {
            path_id[v] = P++;
            paths.push_back({});
        }
        else path_id[v] = path_id[son_in_path];
        paths[path_id[v]].push_back(v);
    }
 
    wgt get_max_dist_down(int v) {
        return max_dist_down.get(interval_renumbering[v].first, interval_renumbering[v].second).first;
    }
 
    wgt get_dep(int v) {
        return max_dist_down.get_pos(interval_renumbering[v].first);
    }
 
public:
    Solver(vector< vector< pair<int, wgt> > > & G_) : N(G_.size()), R(0), P(0) {
        par.resize(N, -1);
        G.resize(N);
        interval_renumbering.resize(N, {0, 0});
        subtree_size.resize(N);
        path_id.resize(N);
        path_pos.resize(N);
        W.resize(N, 0);
        v_from_interval_id.resize(N);
        max_dist_down = IntervalTree(N);
 
        par[R] = R;
        DFS_construct(R, G_);
        for(int i = 0; i < P; i++) reverse(begin(paths[i]), end(paths[i]));
 
        tree_over_path.resize(P);
        down_edges.resize(P);
        last_down_edge.resize(P);
        down_edge_id.resize(N);
        for(int i = 0; i < P; i++) {
            int num_edges = 0, L = paths[i].size();
            down_edges[i].resize(L);
            last_down_edge[i].resize(L);
            for(int j = 0; j < L; j++) {
                path_pos[paths[i][j]] = j;
                for(auto son : G[paths[i][j]]) if(path_id[son] != i) {
                    down_edge_id[son] = num_edges;
                    down_edges[i][j].push_back({son, num_edges++});
                }
                down_edges[i][j].push_back({paths[i][j], num_edges++});
                last_down_edge[i][j] = num_edges;
            }
            tree_over_path[i] = IntervalTree(num_edges);
            wgt dist_from_top = 0;
            for(int j = 0; j < L; j++) {
                if(j > 0) dist_from_top += W[paths[i][j]];
                for(auto edge : down_edges[i][j]) {
                    wgt val = 0;
                    if(edge.first != paths[i][j])
                        val = get_max_dist_down(edge.first) - get_dep(edge.first) + W[edge.first];
                    tree_over_path[i].put(edge.second, val - dist_from_top);
                }
            }
        }
    }
 
    void update(int u, int v, wgt w) {
        if(par[u] == v) swap(u, v);
        // update weight(par[v]--v) to w
        max_dist_down.add(interval_renumbering[v].first, interval_renumbering[v].second, w-W[v]);
        if(path_id[v] == path_id[u])
            tree_over_path[path_id[v]].add(last_down_edge[path_id[u]][path_pos[u]], last_down_edge[path_id[u]].back(), W[v]-w);
        W[v] = w;
        v = paths[path_id[v]][0];
        while(v != R) {
            int v_old = v;
            v = par[v];
            int r = last_down_edge[path_id[v]][path_pos[v]];
            wgt dist_from_top = -tree_over_path[path_id[v]].get_pos(r-1);
            tree_over_path[path_id[v]].put(down_edge_id[v_old], get_max_dist_down(v_old) - get_dep(v) - dist_from_top);
            v = paths[path_id[v]][0];
        }
    }
 
    wgt query() {
        // return diameter
        pair<wgt, int> p = max_dist_down.get(0, N, true);
        int v = v_from_interval_id[p.second];
        wgt ret = p.first, dist_up = 0;
        int last_edge_id = -1;
        while(true) {
            int r = last_down_edge[path_id[v]][path_pos[v]];
            wgt dist_from_top = -tree_over_path[path_id[v]].get_pos(r-1);
            ret = max(ret, dist_up + dist_from_top + tree_over_path[path_id[v]].get(0, last_edge_id).first);
            ret = max(ret, dist_up + dist_from_top + tree_over_path[path_id[v]].get(last_edge_id+1, r).first);
            if(path_pos[v]+1 < (int)paths[path_id[v]].size())
                ret = max(ret, dist_up + get_max_dist_down(paths[path_id[v]][path_pos[v]+1]) - get_dep(v));
            dist_up += dist_from_top;
            v = paths[path_id[v]][0];
            if(v == R) break;
            last_edge_id = down_edge_id[v];
            dist_up += W[v];
            v = par[v];
        }
        return ret;
    }
};
 
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(10);
    int N, Q;
    long long W;
    cin >> N >> Q >> W;
    vector< pair<int, int> > E(N-1);
    vector< vector< pair<int, long long> > > G(N);
    for(int i = 0; i < N-1; i++) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        G[--u].push_back({--v, w});
        G[v].push_back({u, w});
        E[i] = {u, v};
    }
    Solver solver(G);
    long long last = 0;
    for(int i = 0; i < Q; i++) {
        long long e, w;
        cin >> e >> w;
        e = (e + last) % (N-1);
        w = (w + last) % W;
        int u = E[e].first, v = E[e].second;
        solver.update(u, v, w);
        last = solver.query();
        cout << last << "\n";
    }
    return 0;
}