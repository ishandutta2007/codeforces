// Stack of interval trees over implicit HLD.
// O(N log^2 N)
#include <bits/stdc++.h>
using namespace std;

using wgt = unsigned long long;

class Solver {
    using day = int;

    class IntervalTree {
        struct node {
            wgt val, add;
        };

        int b;
        vector<node> T;

        inline __attribute__((always_inline)) void upd(int i, bool leaf) {
            wgt add = T[i].add;
            if(add == 0) return;
            T[i].add = 0;
            T[i].val += add;
            if(!leaf) {
                T[2*i].add += add;
                T[2*i+1].add += add;
            }
        }

        void traverse_add_internal(vector< pair<int, wgt> > & L_values, int & pos, wgt & cur_max, int i, int n_l, int n_r) {
            if(n_l+1 == n_r) {
                T[i].val = cur_max = max(cur_max, T[i].val + T[i].add);
                T[i].add = 0;
                if(pos+1 != (int)L_values.size() && L_values[pos+1].first == n_l) pos++;
                T[i].val += L_values[pos].second;
                return;
            }
            if(L_values[pos].first < n_l && (pos+1 == (int)L_values.size() || n_r <= L_values[pos+1].first)) {
                cur_max = max(cur_max, T[i].val + T[i].add);
                T[i].add += L_values[pos].second;
                upd(i, n_l+1 == n_r);
                return;
            }
            upd(i, n_l+1 == n_r);
            int c = (n_l + n_r) / 2;
            traverse_add_internal(L_values, pos, cur_max, 2*i, n_l, c);
            traverse_add_internal(L_values, pos, cur_max, 2*i+1, c, n_r);
            T[i].val = max(T[2*i].val, T[2*i+1].val);
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

        void put(int pos, wgt w) {
            int cur = 1, n_l = 0, n_r = b;
            while(n_l+1 != n_r) {
                upd(cur, false);
                int c = (n_l + n_r) / 2;
                if(pos < c) {
                    upd(2*cur+1, c+1 == n_r);
                    cur = 2*cur;
                    n_r = c;
                }
                else {
                    upd(2*cur, n_l+1 == c);
                    cur = 2*cur+1;
                    n_l = c;
                }
            }
            T[cur].val = w;
            T[cur].add = 0;
            for(cur /= 2; cur > 0; cur /= 2)
                T[cur].val = max(T[2*cur].val, T[2*cur+1].val);
        }

        wgt get_max(int pos) { // max [0..pos]
            wgt ret = 0;
            int cur = 1, n_l = 0, n_r = b;
            while(true) {
                upd(cur, n_l+1 == n_r);
                if(pos+1 == n_r) {
                    ret = max(ret, T[cur].val);
                    break;
                }
                if(T[cur].val <= ret) break;
                int c = (n_l + n_r) / 2;
                if(pos < c) {
                    cur = 2*cur;
                    n_r = c;
                    continue;
                }
                upd(2*cur, n_l+1 == c);
                ret = max(ret, T[2*cur].val);
                cur = 2*cur+1;
                n_l = c;
            }
            return ret;
        }

        void traverse_add(vector< pair<int, wgt> > & L_values) {
            int pos = 0;
            wgt cur_max = 0;
            traverse_add_internal(L_values, pos, cur_max, 1, 0, b);
        }

        void traverse_extract_clear(vector< pair<int, wgt> > & L_values, wgt add = 0, int i = 1, int n_l = 0, int n_r = 0) {
            if(i == 1) n_r = b;
            add += T[i].add;
            T[i].add = 0;
            if(T[i].val == 0 || n_l+1 == n_r) {
                if(add+T[i].val > 0)
                    if(L_values.empty() || L_values.back().second < add+T[i].val)
                        L_values.push_back({n_l, add+T[i].val});
                T[i].val = 0;
                return;
            }
            T[i].val = 0;
            int c = (n_l + n_r) / 2;
            traverse_extract_clear(L_values, add, 2*i, n_l, c);
            traverse_extract_clear(L_values, add, 2*i+1, c, n_r);
        }
    };

    int N, K;
    vector< vector<int> > son;
    vector<wgt> W;
    vector<day> D;
    vector<int> sz, max_son;
    vector<wgt> LIS_W; // largest increasing subgraph weight
    vector<IntervalTree> interval_trees;
    int tree_stack_depth;

    void DFS_init(int R) {
        int max_son_sz = 0;
        for(auto v : son[R]) {
            DFS_init(v);
            sz[R] += sz[v];
            if(sz[v] > max_son_sz) {
                max_son_sz = sz[v];
                max_son[R] = v;
            }
        }
    }

    void DFS_solve(int R, IntervalTree & this_itree) {
        if(max_son[R] == 0) {
            if(D[R] > 0) {
                LIS_W[R] = W[R];
                this_itree.put(D[R]-1, W[R]);
            }
            return;
        }

        DFS_solve(max_son[R], this_itree);

        for(auto v : son[R]) if(v != max_son[R]) {
            IntervalTree & subtree_itree = interval_trees[tree_stack_depth];
            tree_stack_depth++;

            DFS_solve(v, subtree_itree);

            vector< pair<int, wgt> > subtree_L_values;
            subtree_L_values.reserve(sz[v]+1);
            subtree_itree.traverse_extract_clear(subtree_L_values);
            tree_stack_depth--;

            if(subtree_L_values.empty()) continue;
            if(subtree_L_values[0].first > 0) subtree_L_values.insert(begin(subtree_L_values), {0, 0});
            this_itree.traverse_add(subtree_L_values);
        }

        if(D[R] > 0) {
            LIS_W[R] = this_itree.get_max(D[R]-1) + W[R];
            this_itree.put(D[R]-1, LIS_W[R]);
        }
    }

public:
    Solver(vector< vector<int> > & son_, vector<wgt> & W_, vector<day> & D_, int K_)
            : N(son_.size()), W(W_), K(K_), son(son_), D(D_) {
        // D[v] == 0: v is empty
        sz.resize(N, 1);
        max_son.resize(N, 0); // 0: leaf
        LIS_W.resize(N, 0);
        interval_trees.resize(18, IntervalTree(K));
        tree_stack_depth = 0;

        DFS_init(0);
    }

    wgt solve() {
        IntervalTree & full_itree = interval_trees[tree_stack_depth];
        tree_stack_depth++;

        DFS_solve(0, full_itree);

        wgt ans = full_itree.get_max(K-1);

        vector< pair<int, wgt> > V;
        full_itree.traverse_extract_clear(V);
        tree_stack_depth--;

        return ans;
    }
};

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> par(N, 0);
    vector< vector<int> > son(N);
    for(int i = 1; i < N; i++) {
        cin >> par[i];
        par[i]--;
        son[par[i]].push_back(i);
    }
    vector<wgt> W(N, 0);
    vector<int> D(N, 0);
    for(int i = 0; i < M; i++) {
        int v, d, w;
        cin >> v >> d >> w;
        v--;
        D[v] = d;
        W[v] = w;
    }
    Solver solver(son, W, D, K);
    cout << solver.solve() << "\n";
}