#include <bits/stdc++.h>

template <typename T>
struct ImplicitSegmentTree {
  struct Node {
    T value = T();
    Node *left = nullptr, *right = nullptr;
    int l, r, m, tag;
    Node(int l, int r, int tag) : l(l), r(r), m((l + r) / 2), tag(tag) {}
  };
  int num_tags = 0;
  std::deque<Node> deq;
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
  void update(Node* p, int i, T value) {
    if (p->l + 1 == p->r) {
      p->value = p->value + value;
    } else {
      update(i < p->m ? get_left(p) : get_right(p), i, value);
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
  template <typename Iterator>
  void build(Node* p, Iterator first) {
    if (p->l + 1 == p->r) {
      p->value = first[p->l];
    } else {
      build(get_left(p), first);
      build(get_right(p), first);
      p->value = p->left->value + p->right->value;
    }
  }
  template <typename Iterator>
  Node* build(Iterator first, Iterator last) {
    Node* root = create(0, last - first, num_tags++);
    build(root, first);
    return root;
  }
};

struct Minimum {
  int min;
  Minimum(int min = std::numeric_limits<int>::max()) : min(min) {}
  Minimum operator+(Minimum rhs) const {
    return std::min(min, rhs.min);
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int N, root;
  std::cin >> N >> root;
  --root;
  std::vector<int> a(N);
  for (int u = 0; u < N; ++u) {
    std::cin >> a[u];
  }
  std::vector<std::vector<int>> E(N);
  for (int i = 0; i < N - 1; ++i) {
    int u, v;
    std::cin >> u >> v;
    --u, --v;
    E[u].push_back(v);
    E[v].push_back(u);
  }
  ImplicitSegmentTree<Minimum> st;
  std::vector<decltype(st)::Node*> node(N);
  std::vector<int> h(N), L(N), R(N), inv(N);
  auto W = [&](int u) {
    return R[u] - L[u];
  };
  int timer = 0;
  auto dfs = [&](auto& self, int u, int p) -> void {
    inv[L[u] = timer++] = u;
    int heavy = -1;
    for (auto v : E[u]) {
      if (v == p) continue;
      h[v] = h[u] + 1;
      self(self, v, u);
      if (heavy == -1 || W(heavy) < W(v)) {
        heavy = v;
      }
    }
    R[u] = timer;
    if (heavy == -1) {
      node[u] = st.create(0, N);
    } else {
      node[u] = st.copy(node[heavy]);
      for (auto v : E[u]) {
        if (v == p || v == heavy) continue;
        for (int i = L[v]; i < R[v]; ++i) {
          int x = inv[i];
          st.update(node[u], h[x], a[x]);
        }
      }
    }
    st.update(node[u], h[u], a[u]);
  };
  dfs(dfs, root, -1);
  int M;
  std::cin >> M;
  int last = 0;
  for (int j = 0; j < M; ++j) {
    int p, q;
    std::cin >> p >> q;
    int x = (p + last) % N, k = (q + last) % N;
    last = st.query(node[x], h[x], std::min(N, h[x] + k + 1)).min;
    std::cout << last << '\n';
  }
  exit(0);
}