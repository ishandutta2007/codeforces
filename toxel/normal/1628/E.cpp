//
// Created by  on 2022/1/23.
//

//
// Created by  on 2022/1/6.
//

#include <bits/stdc++.h>
#define mp std::make_pair
#define scanf dont_use_scanf
#define printf dont_use_printf
#define endl dont_use_endl

using ll = int64_t;
using pii = std::pair <int, int>;
using piii = std::tuple <int, int, int>;

//
// Created by  on 2022/1/23.
//
#include <bits/stdc++.h>

class EulerTour{
public:
    std::vector <std::vector <int>> e, st;
    std::vector <int> dfn, right, dep, tour;
    std::vector <int> bit;
    int dfn_cnt;
    int n, root;

    explicit EulerTour(int sz, int root):n(sz), dfn_cnt(0), root(root){
        sz += 10;
        e.resize(sz);
        dfn.resize(sz);
        right.resize(sz);
        dep.resize(sz);
        tour = {0};
    }

    void add_edge(int u, int v){
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }

    void dfs(int u, int fa){
        dfn[u] = right[u] = ++ dfn_cnt;
        tour.emplace_back(u);
        for (auto v : e[u]){
            if (v == fa){
                continue;
            }
            dep[v] = dep[u] + 1;
            dfs(v, u);
            right[u] = ++ dfn_cnt;
            tour.emplace_back(u);
        }
    }

    void solve(){
        dfs(root, 0);
        int sz = tour.size();
        int sz1 = sz + 10;
        bit.resize(sz1);
        for (int i = 2; i < sz1; ++ i){
            bit[i] = bit[i >> 1] + 1;
        }
        const int max_bit = bit.back();
        st.resize(max_bit + 1);
        st[0] = tour;
        for (int i = 1; i <= max_bit; ++ i){
            st[i].resize(sz);
            for (int j = 1; j + (1 << i) - 1 < sz; ++ j){
                int a = st[i - 1][j], b = st[i - 1][j + (1 << (i - 1))];
                st[i][j] = dep[a] < dep[b] ? a : b;
            }
        }
    }

    int lca(int u, int v){
        int l = dfn[u], r = right[v];
        if (l > r){
            std::swap(l, r);
        }
        int bt = bit[r - l + 1];
        int a = st[bt][l], b = st[bt][r - (1 << bt) + 1];
        return dep[a] < dep[b] ? a : b;
    }
};

//
// Created by  on 2022/1/23.
//

#include <bits/stdc++.h>

class DisjointSet{
public:
    std::vector <int> fa, sz;

    explicit DisjointSet(int n){
        n += 10;
        fa.resize(n);
        sz.resize(n);
        for (int i = 0; i < n; ++ i){
            fa[i] = i;
            sz[i] = 1;
        }
    }

    int find(int u){
        return fa[u] == u ? u : (fa[u] = find(fa[u]));
    }

    void unite(int u, int v){
        u = find(u), v = find(v);
        fa[u] = v;
        sz[v] += sz[u];
    }
};

#include <bits/stdc++.h>

namespace Seg{
    using T = int;

    class Node{
    public:
        T value;
        T lazy;
        T base;

        Node():value(), lazy(), base(){}
        Node(T value, T lazy, T base):value(value), lazy(lazy), base(base){}
    };

    class Seg{
#define ls(u) ((u) << 1)
#define rs(u) (((u) << 1) | 1)
// #define OPERATE +
    public:
        int maximum;
        std::vector <Node> seg;
        EulerTour *eu;

        explicit Seg(int range):seg(){
            maximum = 1;
            while (maximum <= range + 10){
                maximum <<= 1;
            }
            seg.resize(maximum << 1);
        }

        void init(){
            for (int i = maximum - 1; i; -- i){
                pull(i);
                seg[i].base = merge(seg[ls(i)].base, seg[rs(i)].base);
            }
        }

        T merge(T u, T v){
            if (u == 0 || v == 0){
                return u | v;
            }
            return eu -> lca(u, v);
        }

        void update(int sit, T value){
            if (value == 1){
                seg[sit].value = seg[sit].base;
            }
            else if (value == -1){
                seg[sit].value = 0;
            }
            seg[sit].lazy = value;
        }

        void push(int sit){
            if (seg[sit].lazy == 0){
                return;
            }
            update(ls(sit), seg[sit].lazy);
            update(rs(sit), seg[sit].lazy);
            seg[sit].lazy = 0;
        }

        void pull(int sit){
            seg[sit].value = merge(seg[ls(sit)].value, seg[rs(sit)].value);
        }

        void add(int sit, int l, int r, int ql, int qr, T value){
            if (ql > r || qr < l){
                return;
            }
            if (ql <= l && qr >= r){
                update(sit, value);
                return;
            }
            push(sit);
            int mid = (l + r) / 2;
            add(ls(sit), l, mid, ql, qr, value);
            add(rs(sit), mid + 1, r, ql, qr, value);
            pull(sit);
        }

        void add(int l, int r, T value){
            add(1, 0, maximum - 1, l, r, value);
        }

        T query(int sit, int l, int r, int ql, int qr){
            if (ql > r || qr < l){
                return 0;
            }
            if (ql <= l && qr >= r){
                return seg[sit].value;
            }
            push(sit);
            int mid = (l + r) / 2;
            return merge(query(ls(sit), l, mid, ql, qr),
                    query(rs(sit), mid + 1, r, ql, qr));
        }

        T query(int l, int r){
            return query(1, 0, maximum - 1, l, r);
        }
    };
}

void solve(){
    int n, q;
    std::cin >> n >> q;
    std::vector <piii> edges;
    for (int i = 0, u, v, w; i < n - 1; ++ i){
        std::cin >> u >> v >> w;
        edges.emplace_back(w, u, v);
    }
    std::sort(edges.begin(), edges.end());
    EulerTour eulerTour(2 * n - 1, 2 * n - 1);
    DisjointSet disjointSet(2 * n - 1);
    int cur = n;
    for (auto [w, u, v]: edges){
        ++ cur;
        u = disjointSet.find(u);
        v = disjointSet.find(v);
        eulerTour.add_edge(u, cur);
        eulerTour.add_edge(v, cur);
        disjointSet.unite(u, cur);
        disjointSet.unite(v, cur);
    }
    eulerTour.solve();
    Seg::Seg seg(n);
    seg.eu = &eulerTour;
    for (int i = 1; i <= n; ++ i){
        seg.seg[seg.maximum + i].base = i;
    }
    /*for (int i = 1; i <= n; ++ i){
        for (int j = i + 1; j <= n; ++ j){
            std::cout << i << ' ' << j << ' ' << eulerTour.lca(i, j) << '\n';
        }
    }*/
    seg.init();
    while (q --){
        int type;
        std::cin >> type;
        if (type == 1){
            int l, r;
            std::cin >> l >> r;
            seg.add(l, r, 1);
        }
        else if (type == 2){
            int l, r;
            std::cin >> l >> r;
            seg.add(l, r, -1);
        }
        else if (type == 3){
            int x;
            std::cin >> x;
            int ans = seg.merge(x, seg.query(1, n));
            if (ans <= n){
                ans = -1;
            }
            else{
                ans = std::get <0>(edges[ans - n - 1]);
            }
            std::cout << ans << '\n';
        }
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int test = 1;
    // std::cin >> test;
    while (test --){
        solve();
    }
    return 0;
}