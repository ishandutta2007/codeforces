#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

// Range update, range query segment tree

#include <vector>

struct LazyContext {
    LazyContext(long long _v = 0) {
        v = _v;
    }
    
    void reset() {
        v = 0;
    }
    
    void operator += (LazyContext o) {
        v += o.v;
    }
    
    // atributes
    long long v;
};

struct Node {
    Node() {
        size = 0;
        ans = 0;
    }
    
    Node(int v) {
        // init
        size = 1;
        ans = v;
    }
    
    Node(Node &l, Node &r) {
        // merge
        ans = l.ans + r.ans;
        size = l.size + r.size;
    }
    
    void apply(LazyContext lazy) {
        ans += lazy.v * size;
    }
    
    // atributes
    int size;
    long long ans;
};

template <class i_t, class e_t, class lazy_cont = int>
class SegmentTree {
public:
    void init(std::vector<e_t> base) {
        n = base.size();
        h = 0;
        while((1 << h) < n) h++;
        tree.resize(2 * n);
        dirty.assign(n, false);
        lazy.resize(n);
        for(int i = 0; i < n; i++) {
            tree[i + n] = i_t(base[i]);
        }
        for(int i = n - 1; i > 0; i--) {
            tree[i] = i_t(tree[i<<1], tree[(i<<1)|1]);
            lazy[i].reset();
        }
    }
    
    i_t qry(int l, int r) {
        if(l >= r) return i_t();
        l += n, r += n;
        push(l);
        push(r - 1);
        i_t lp, rp;
        for(; l < r; l >>= 1, r >>= 1) {
            if(l & 1) lp = i_t(lp, tree[l++]);
            if(r & 1) rp = i_t(tree[--r], rp);
        }
        return i_t(lp, rp);
    }
    
    void upd(int l, int r, lazy_cont lc) {
        if(l >= r) return;
        l += n, r += n;
        push(l);
        push(r - 1);
        int l0 = l, r0 = r;
        for(; l < r; l >>= 1, r >>= 1) {
            if(l & 1) apply(l++, lc);
            if(r & 1) apply(--r, lc);
        }
        build(l0);
        build(r0 - 1);
    }
    
private:
    int n, h;
    std::vector<bool> dirty;
    std::vector<i_t> tree;
    std::vector<lazy_cont> lazy;
    
    void apply(int p, lazy_cont &lc) {
        tree[p].apply(lc);
        if(p < n) {
            dirty[p] = true;
            lazy[p] += lc;
        }
    }
    
    void push(int p) {
        for(int s = h; s > 0; s--) {
            int i = p >> s;
            if(dirty[i]) {
                apply(i + i, lazy[i]);
                apply(i + i + 1, lazy[i]);
                lazy[i].reset();
                dirty[i] = false;
            }
        }
    }
    
    void build(int p) {
        for(p >>= 1; p > 0; p >>= 1) {
            tree[p] = i_t(tree[(p<<1)], tree[(p<<1)|1]);
            if(dirty[p]) {
                tree[p].apply(lazy[p]);
            }
        }
    }
};

struct Node1 {
    Node1() {
        // empty constructor
        ans = std::pair<int, int>(-1, -1);
    }
    
    Node1(std::pair<int, int> v) {
        // init
        ans = v;
    }
    
    Node1(Node1 l, Node1 r) {
        // merge
        ans = std::max(l.ans, r.ans);
    }

    // atributes
    std::pair<int, int> ans;
};

template <class i_t, class e_t>
class SegmentTree1 {
public:
    void init(std::vector<e_t> base) {
        n = base.size();
        tree.resize(2 * n);
        for(int i = 0; i < n; i++) {
            tree[i + n] = i_t(base[i]);
        }
        for(int i = n - 1; i > 0; i--) {
            tree[i] = i_t(tree[i<<1], tree[(i<<1)|1]);
        }
    }
    
    i_t qry(int l, int r) {
        i_t lp, rp;
        for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if(l & 1) lp = i_t(lp, tree[l++]);
            if(r & 1) rp = i_t(tree[--r], rp);
        }
        return i_t(lp, rp);
    }
    
    void upd(int pos, e_t v) {
        pos += n;
        tree[pos] = i_t(v);
        for(pos >>= 1; pos > 0; pos >>= 1) {
            tree[pos] = i_t(tree[(pos<<1)], tree[(pos<<1)|1]);
        }
    }
    
private:
    int n;
    std::vector<i_t> tree;
};

SegmentTree1<Node1, std::pair<int, int>> tree;
std::vector<std::pair<int, int>> out;

void build(int l, int r) {
    if(l >= r) return;
    int mid = tree.qry(l, r).ans.second;
    build(l, mid);
    build(mid + 1, r);
    out[mid] = std::pair<int, int>(l, r);
}

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int n, q;
    std::cin >> n >> q;
    out.resize(n);
    std::vector<std::pair<int, int>> a(n);
    for(int i = 0; i < n; i++) {
        a[i].second = i;
        std::cin >> a[i].first;
    }
    tree.init(a);
    build(0, n);
    std::vector<std::pair<int, int>> ranges(q);
    std::vector<std::vector<int>> lp(n + 1), rp(n + 1);
    std::vector<long long> ans(q, 0);
    for(int i = 0; i < q; i++) {
        std::cin >> ranges[i].first;
        ranges[i].first--;
        lp[ranges[i].first].push_back(i);
    }
    for(int i = 0; i < q; i++) {
        std::cin >> ranges[i].second;
        rp[ranges[i].second].push_back(i);
    }
    SegmentTree<Node, int, LazyContext> sum;
    sum.init(std::vector<int>(n, 0));
    for(int i = 0; i <= n; i++) {
        if(i) {
            sum.upd(out[i-1].first, out[i-1].second, LazyContext(1));
        }
        for(auto id : lp[i]) {
            ans[id] -= sum.qry(ranges[id].first, ranges[id].second).ans;
        }
        for(auto id : rp[i]) {
            ans[id] += sum.qry(ranges[id].first, ranges[id].second).ans;
        }
    }
    for(int i = 0; i < q; i++) {
        std::cout << ans[i] << '\n';
    }
}