// COPIED
#include <bits/stdc++.h>
 
constexpr int Lim = 2e5 + 1;
constexpr int64_t Inf = 1e18;
 
struct SegTree {
    int64_t tag, mn;
    SegTree *lc, *rc;
};
SegTree *null = new SegTree;
 
SegTree *newTree() {
    auto t = new SegTree;
    t->lc = t->rc = null;
    t->tag = 0;
    t->mn = Inf;
    return t;
}
 
void add(SegTree *t, int64_t v) {
    t->tag += v;
    t->mn += v;
}
 
void push(SegTree *t) {
    if (t->lc != null) add(t->lc, t->tag);
    if (t->rc != null) add(t->rc, t->tag);
    t->tag = 0;
}
 
void pull(SegTree *t) { t->mn = std::min(t->lc->mn, t->rc->mn); }
 
void modify(SegTree *&t, int l, int r, int x, int64_t v) {
    if (t == null) t = newTree();
    if (r - l == 1) {
        t->mn = v;
        return;
    }
    int m = (l + r) / 2;
    push(t);
    if (x < m) modify(t->lc, l, m, x, v);
    else modify(t->rc, m, r, x, v);
    pull(t);
}
 
int64_t query(SegTree *t, int l, int r, int x) {
    if (r - l == 1 || t == null) return t->mn;
    int m = (l + r) / 2;
    push(t);
    if (x < m) return query(t->lc, l, m, x);
    else return query(t->rc, m, r, x);
}
 
SegTree *merge(SegTree *t1, SegTree *t2) {
    if (t1 == null) return t2;
    if (t2 == null) return t1;
    t1->mn = std::min(t1->mn, t2->mn);
    push(t1);
    push(t2);
    t1->lc = merge(t1->lc, t2->lc);
    t1->rc = merge(t1->rc, t2->rc);
    return t1;
}
 
SegTree *solve(int s, int64_t v, int ban) {
    SegTree *t = null;
    modify(t, 0, Lim, s, v);
    std::string opt;
    while (std::cin >> opt) {
        if (opt == "end") return t;
        if (opt == "set") {
            int y, v;
            std::cin >> y >> v;
            int64_t mn = t->mn;
            add(t, v);
            if (y != ban) modify(t, 0, Lim, y, mn);
        } else {
            int y;
            std::cin >> y;
            auto t1 = solve(y, query(t, 0, Lim, y), ban);
            modify(t, 0, Lim, y, Inf);
            t = merge(t, t1);
        }
    }
    return t;
}
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    null->mn = Inf;
    null->lc = null->rc = null;
    
    int n, s;
    std::cin >> n >> s;
    
    auto t = solve(0, 0, s);
    
    std::cout << t->mn << "\n";
    
    return 0;
}