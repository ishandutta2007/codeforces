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

#include<bits/stdc++.h>

using ll = long long;
using pii = std::pair <int, int>;
using T = int; // value type
const int DIM = 2;

using Node = std::array <int, DIM>;

struct KD_Tree{
#define ls(u) (ch[(u)][0])
#define rs(u) (ch[(u)][1])
    const static int N = 300010;

    Node low[N], high[N];
    T seg[N];
    int ch[N][2], sz, root;
    std::vector<Node> vec;
    std::vector<T> vec1;

    int newnode(){
        ++ sz;
        memset(ch[sz], 0, sizeof(ch[0]));
        return sz;
    }

    void init(){
        sz = 0;
        root = newnode();
    }

    void pull(int u){
        for (int i = 0; i < DIM; ++ i){
            low[u][i] = std::min(low[ls(u)][i], low[rs(u)][i]);
            high[u][i] = std::max(high[ls(u)][i], high[rs(u)][i]);
        }
        pull1(u);
    }

    // modify it
    void pull1(int u){
        seg[u] = std::min(seg[ls(u)], seg[rs(u)]);
    }

    void build(int u, int l, int r, int dep){ // ensure vec assigned and non-empty!
        if (l == r){
            low[u] = high[u] = vec[l];
            seg[u] = vec1[l];
            return;
        }
        int mid = (l + r) / 2;
        std::nth_element(vec.begin() + l, vec.begin() + mid, vec.begin() + r + 1,
                         [&](const Node &n1, const Node &n2){
                             return n1[dep] < n2[dep];
                         });
        ls(u) = newnode();
        rs(u) = newnode();
        build(ls(u), l, mid, (dep + 1) % DIM);
        build(rs(u), mid + 1, r, (dep + 1) % DIM);
        pull(u);
    }

    void build(){
        if (vec.empty()) return;
        build(root, 0, int(vec.size()) - 1, 0);
    }

    // modify it
    void add(int sit, Node ql, Node qr, T value){
        if (!sit) return;
        for (int i = 0; i < DIM; ++ i){
            if (qr[i] < low[sit][i] || ql[i] > high[sit][i]) return;
        }
        for (int i = 0; i < DIM; ++ i){
            if (!(ql[i] <= low[sit][i] && high[sit][i] <= qr[i])){
                add(ls(sit), ql, qr, value);
                add(rs(sit), ql, qr, value);
                pull1(sit);
                return;
            }
        }
        seg[sit] = value;
    }

    // modify it
    T query(int sit, Node ql, Node qr){
        if (!sit) return INT_MAX;
        for (int i = 0; i < DIM; ++ i){
            if (qr[i] < low[sit][i] || ql[i] > high[sit][i]) return INT_MAX;
        }
        for (int i = 0; i < DIM; ++ i){
            if (!(ql[i] <= low[sit][i] && high[sit][i] <= qr[i])){
                return std::min(query(ls(sit), ql, qr), query(rs(sit), ql, qr));
            }
        }
        return seg[sit];
    }
};

const int N = 100010;

KD_Tree kd_tree;
int l[N], r[N], ans[N];
std::vector <int> vec[N];

int solve1(int l1, int r1, int len){
    if (r1 - l1 + 1 < len){
        return 0;
    }
    int id = kd_tree.query(kd_tree.root, {l1, -INT_MAX}, {INT_MAX, r1});
    if (id == INT_MAX){
        return 0;
    }
    return r[id] - l[id] + 1 + solve1(l1, l[id] - 1, len) + solve1(r[id] + 1, r1, len);
}

void solve(){
    int n, m;
    std::cin >> n >> m;
    std::set <pii> set;
    for (int i = 0; i < m; ++ i){
        std::cin >> l[i] >> r[i];
    }
    for (int i = 0; i < m; ++ i){
        if (set.count({l[i], r[i]})){
            continue;
        }
        vec[r[i] - l[i] + 1].emplace_back(i);
        set.emplace(l[i], r[i]);
        kd_tree.vec.push_back({l[i], r[i]});
        kd_tree.vec1.emplace_back(INT_MAX);
    }
    kd_tree.init();
    kd_tree.build();
    for (int i = n; i >= 1; -- i){
        for (auto u : vec[i]){
            kd_tree.add(kd_tree.root, {l[u], r[u]}, {l[u], r[u]}, u);
        }
        ans[i] = solve1(1, n, i);
    }
    for (int i = 1; i <= n; ++ i){
        std::cout << ans[i] << '\n';
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