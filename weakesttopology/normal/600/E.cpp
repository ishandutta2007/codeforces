#include <bits/stdc++.h>
using namespace std;
template<typename T>
struct ImplicitSegmentTree {
    struct Node {
        T value = T();
        Node *left = nullptr, *right = nullptr;
        int l, r, m, tag;
        Node(int l, int r, int tag) : l(l), r(r), m((l + r) / 2), tag(tag) {}
    };
    int num_tags = 0;
    deque<Node> deq;
    Node* create(int l, int r, int tag = -1) {
        return &deq.emplace_back(l, r, tag == -1 ? num_tags++ : tag);
    }
    Node* copy(Node* p, int tag = -1) {
        Node* q = &deq.emplace_back(*p);
        q->tag = tag == -1 ? num_tags++ : tag;
        return q;
    }
    Node* get_left(Node* p) {
        if (p->left == nullptr) {
            p->left = create(p->l, p->m, p->tag);
        } else if (p->left->tag != p->tag) {
            p->left = copy(p->left, p->tag);
        }
        return p->left;
    }
    Node* get_right(Node* p) {
        if (p->right == nullptr) {
            p->right = create(p->m, p->r, p->tag);
        } else if (p->right->tag != p->tag) {
            p->right = copy(p->right, p->tag);
        }
        return p->right;
    }
    T get_value(Node* p) {
        return p ? p->value : T();
    }
    void modify(Node* p, int i, T value) {
        if (p->l + 1 == p->r) {
            p->value = value;
        } else {
            modify(i < p->m ? get_left(p) : get_right(p), i, value);
            p->value = get_value(p->left) + get_value(p->right);
        }
    }
    T query(Node* p, int ql, int qr) const {
        if (p == nullptr || p->r <= ql || qr <= p->l) {
            return T();
        } else if (ql <= p->l && p->r <= qr) {
            return p->value;
        } else {
            return query(p->left, ql, qr) + query(p->right, ql, qr);
        }
    }
    template<typename Iterator>
    void build(Node* p, Iterator first) {
        if (p->l + 1 == p->r) {
            p->value = first[p->l];
        } else {
            build(get_left(p), first);
            build(get_right(p), first);
            p->value = p->left->value + p->right->value;
        }
    }
    template<typename Iterator>
    Node* build(Iterator first, Iterator last) {
        Node* root = create(0, int(last - first), num_tags++);
        build(root, first);
        return root;
    }
    // merges in p 'into' q
    template<typename LeafMerger>
    void merge(Node* p, Node* q, LeafMerger&& leaf_merger) {
        if (p == nullptr) {
            return;
        } else if (p->l + 1 < p->r) {
            if (q->left == nullptr) {
                q->left = p->left;
            } else {
                merge(p->left, get_left(q), leaf_merger);
            }
            if (q->right == nullptr) {
                q->right = p->right;
            } else {
                merge(p->right, get_right(q), leaf_merger);
            }
            q->value = get_value(q->left) + get_value(q->right);
        } else {
            q->value = leaf_merger(p->value, q->value);
        }
    }
    void merge(Node* p, Node* q) {
        merge(p, q, std::plus<T>());
    }
};
struct MaxSumMonoid {
    int mx;
    long long sum;
    MaxSumMonoid() : mx(-1), sum(0) {}
    MaxSumMonoid(int x, long long v) : mx(x), sum(v) {}
    MaxSumMonoid operator+(const MaxSumMonoid& rhs) const {
        MaxSumMonoid res;
        res.mx = max(mx, rhs.mx);
        if (res.mx == mx) {
            res.sum += sum;
        }
        if (res.mx == rhs.mx) {
            res.sum += rhs.sum;
        }
        return res;
    }
};
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    ImplicitSegmentTree<MaxSumMonoid> st;
    vector<ImplicitSegmentTree<MaxSumMonoid>::Node*> rt(N);
    for (int u = 0; u < N; ++u) {
        int c;
        cin >> c;
        rt[u] = st.create(1, N + 1);
        st.modify(rt[u], c, {1, c});
    }
    vector<vector<int>> E(N);
    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        E[u].push_back(v);
        E[v].push_back(u);
    }
    vector<long long> ans(N);
    auto dfs = [&](auto& self, int u, int p) -> void {
        for (auto v : E[u]) {
            if (v == p) continue;
            self(self, v, u);
            st.merge(rt[v], rt[u], [](auto x, auto y) { return MaxSumMonoid(x.mx + y.mx, x.sum); });
        }
        ans[u] = st.query(rt[u], 1, N + 1).sum;
    };
    dfs(dfs, 0, -1);
    for (int u = 0; u < N; ++u) {
        cout << ans[u] << "\n "[u + 1 < N];
    }
    exit(0);
}