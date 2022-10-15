#include <bits/stdc++.h>

constexpr int inf = std::numeric_limits<int>::max();

template <typename T, typename Op>
struct SparseTable {
  int N;
  Op op;
  std::vector<int> log;
  std::vector<std::vector<T>> st;
  template <typename Iterator>
  SparseTable(Iterator first, Iterator last, Op op = Op())
      : N(last - first), op(op), log(N + 1) {
    for (int x = 2; x <= N; ++x) {
      log[x] = 1 + log[x >> 1];
    }
    st.resize(log[N] + 1);
    st[0] = std::vector<T>(first, last);
    for (int x = 0; x < log[N]; ++x) {
      st[x + 1].resize(N);
      for (int i = 0; i + (1 << (x + 1)) <= N; ++i) {
        st[x + 1][i] = op(st[x][i], st[x][i + (1 << x)]);
      }
    }
  }
  T query(int l, int r) const {
    assert(l < r);
    int x = log[r - l];
    return op(st[x][l], st[x][r - (1 << x)]);
  }
};
template <typename T>
struct MinFunctor {
  T operator()(T x, T y) const {
    return std::min(x, y);
  }
};
template <typename T>
using RMQ = SparseTable<T, MinFunctor<T>>;

struct PeriodicSegmentTree {
  struct Node {
    int value, lazy, l, r, m;
    Node(int l, int r) : value(inf), lazy(-1), l(l), r(r), m((l + r) / 2) {}
    Node* left = nullptr;
    Node* right = nullptr;
  };
  int N;
  RMQ<int> rmq;
  std::deque<Node> deq;
  Node* create(int l, int r) {
    Node* node = &deq.emplace_back(l, r);
    if (r - l >= N) {
      node->value = rmq.query(0, N);
    } else {
      int ll = node->l % N, rr = node->r % N;
      if (ll < rr) {
        node->value = rmq.query(ll, rr);
      } else {
        node->value = rmq.query(ll, N);
        if (0 < rr) {
          node->value = std::min(node->value, rmq.query(0, rr));
        }
      }
    }
    return node;
  }
  Node* left(Node* node) {
    if (!node->left) {
      node->left = create(node->l, node->m);
    }
    return node->left;
  }
  Node* right(Node* node) {
    if (!node->right) {
      node->right = create(node->m, node->r);
    }
    return node->right;
  }
  void push(Node* node) {
    if (node->r - node->l > 1 && node->lazy != -1) {
      for (auto child : {left(node), right(node)}) {
        child->value = child->lazy = node->lazy;
      }
    }
    node->lazy = -1;
  }
  void update(Node* node, int ql, int qr, int x) {
    if (node->r <= ql || qr <= node->l) {
      return;
    } else if (ql <= node->l && node->r <= qr) {
      node->value = node->lazy = x;
    } else {
      push(node);
      update(left(node), ql, qr, x);
      update(right(node), ql, qr, x);
      node->value = std::min(left(node)->value, right(node)->value);
    }
  }
  int query(Node* node, int ql, int qr) {
    if (node->r <= ql || qr <= node->l) {
      return inf;
    } else if (ql <= node->l && node->r <= qr) {
      return node->value;
    } else {
      push(node);
      return std::min(query(left(node), ql, qr), query(right(node), ql, qr));
    }
  }

  template <typename Iterator>
  PeriodicSegmentTree(Iterator first, Iterator last) :
    N(last - first), rmq(first, last) {}
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int N, K;
  std::cin >> N >> K;
  std::vector<int> b(N);
  for (int i = 0; i < N; ++i) {
    std::cin >> b[i];
  }
  PeriodicSegmentTree seg(b.begin(), b.end());
  auto root = seg.create(0, N * K);
  int Q;
  std::cin >> Q;
  for (int q = 0; q < Q; ++q) {
    int t, l, r;
    std::cin >> t >> l >> r;
    --l;
    if (t == 1) {
      int x;
      std::cin >> x;
      seg.update(root, l, r, x);
    } else {
      std::cout << seg.query(root, l, r) << '\n';
    }
  }
  exit(0);
}