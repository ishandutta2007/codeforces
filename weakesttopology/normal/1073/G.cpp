#include <bits/stdc++.h>

template <typename Iterator>
std::vector<int> sort_cyclic_shifts(Iterator first, Iterator last) {
  int N = last - first;
  std::vector<int> p(N), inv(N), tmp(N), cnt(N);
  std::iota(p.begin(), p.end(), 0);
  std::sort(
      p.begin(), p.end(), [&](int i, int j) { return first[i] < first[j]; });
  inv[p[0]] = 0;
  for (int i = 1; i < N; ++i) {
    inv[p[i]] = inv[p[i - 1]] + (first[p[i]] != first[p[i - 1]] ? 1 : 0);
  }
  for (int shift = 1; shift < N; shift *= 2) {
    std::fill(cnt.begin(), cnt.end(), 0);
    for (int i = 0; i < N; ++i) {
      tmp[N - 1 - i] = (p[i] + N - shift) % N;
      cnt[inv[p[i]]] += 1;
    }
    std::partial_sum(cnt.begin(), cnt.end(), cnt.begin());
    for (auto i : tmp) p[--cnt[inv[i]]] = i;
    auto key = [&](int i) { return std::pair(inv[i], inv[(i + shift) % N]); };
    tmp[p[0]] = 0;
    for (int i = 1; i < N; ++i) {
      tmp[p[i]] = tmp[p[i - 1]] + (key(p[i - 1]) != key(p[i]) ? 1 : 0);
    }
    std::swap(tmp, inv);
  }
  return p;
}
struct SuffixArray {
  int N;
  std::vector<int> p, pos, lcp;
  SuffixArray(std::string S) {
    S.push_back(0);
    N = S.size();
    p = sort_cyclic_shifts(S.begin(), S.end());
    pos.resize(N);
    lcp.resize(N);
    for (int i = 0; i < N; ++i) {
      pos[p[i]] = i;
    }
    for (int i = 0, k = 0; i < N - 1; ++i, k = std::max(0, k - 1)) {
      if (pos[i] == N - 1) {
        k = 0;
        continue;
      }
      int j = p[pos[i] + 1];
      while (std::max(i, j) + k < N && S[i + k] == S[j + k]) ++k;
      lcp[pos[i]] = k;
    }
  }
  template <typename RMQ>
  int lcp_query(int i, int j, const RMQ& rmq) const {
    if (i == j) return N - i - 1;
    if (pos[i] > pos[j]) {
      std::swap(i, j);
    }
    return rmq.query(pos[i], pos[j]);  // range query should be [l, r)
  }
};


struct SuffixTreeNode {
  int link, len, idx;
  SuffixTreeNode(int len, int idx) : link(-1), len(len), idx(idx) {}
};
std::vector<SuffixTreeNode> build_suffix_tree(
    const std::vector<int>& p, const std::vector<int>& lcp) {
  std::vector<SuffixTreeNode> st;
  std::stack<int> stk;
  auto create = [&](int len, int idx) {
    stk.push(st.size());
    st.emplace_back(len, idx);
  };
  create(0, 0);
  int N = p.size();
  for (int i = 1; i < N; ++i) {
    for (auto len : {N - 1 - p[i], lcp[i]}) {
      int l = p[i];
      while (st[stk.top()].len > len) {
        int v = stk.top();
        stk.pop();
        l = st[v].idx;
        if (len > st[stk.top()].len) create(len, l);
        st[v].link = stk.top();
      }
      if (len > st[stk.top()].len) create(len, l);
    }
  }
  int M = st.size();
  std::vector<int> V(M), label(M);
  std::iota(V.begin(), V.end(), 0);
  std::sort(
      V.begin(), V.end(), [&](int u, int v) { return st[u].len < st[v].len; });
  std::vector<SuffixTreeNode> relabeled;
  for (int j = 0; j < M; ++j) {
    label[V[j]] = j;
    relabeled.push_back(st[V[j]]);
  }
  for (int u = 1; u < M; ++u) {
    relabeled[u].link = label[relabeled[u].link];
  }
  return relabeled;
}

// Range update, range query segment tree

struct LazyContext {
  int64_t x;
	LazyContext(int64_t x = 0) : x(x) {}
	
	void reset() {
    x = 0;
	}
	
	void operator += (LazyContext o) {
    x += o.x;
	}
	
	// atributes
};

struct Node {
  int64_t a, b;
	Node() : a(0), b(0) {}
  Node(int64_t x) : a(x), b(0) {}
	Node(int64_t a, int64_t b) : a(a), b(b) {}
	
	Node(const Node &l, const Node &r) {
    a = l.a + r.a;
    b = l.b + r.b;
	}
	
	void apply(LazyContext lazy) {
    b += lazy.x * a;
	}
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
			tree[i] = i_t(tree[i + i], tree[i + i + 1]);
			lazy[i].reset();
		}
	}
	
	i_t qry(int l, int r) {
		if(l >= r) return i_t();
		l += n, r += n;
		push(l), push(r - 1);
		i_t lp, rp;
		for(; l < r; l /= 2, r /= 2) {
			if(l & 1) lp = i_t(lp, tree[l++]);
			if(r & 1) rp = i_t(tree[--r], rp);
		}
		return i_t(lp, rp);
	}
	
	void upd(int l, int r, lazy_cont lc) {
		if(l >= r) return;
		l += n, r += n;
		push(l), push(r - 1);
		int l0 = l, r0 = r;
		for(; l < r; l /= 2, r /= 2) {
			if(l & 1) apply(l++, lc);
			if(r & 1) apply(--r, lc);
		}
		build(l0), build(r0 - 1);
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
			pushNode(i);
		}
	}

	inline void pushNode(int i) {
		if(dirty[i]) {
			apply(i + i, lazy[i]);
			apply(i + i + 1, lazy[i]);
			lazy[i].reset();
			dirty[i] = false;
		}
	}
	
	void build(int p) {
		for(p /= 2; p > 0; p /= 2) {
			tree[p] = i_t(tree[p + p], tree[p + p + 1]);
			if(dirty[p]) {
				tree[p].apply(lazy[p]);
			}
		}
	}
};

struct HLD {
  int N;
  std::vector<std::vector<int>> E;
  std::vector<int> p, h, head, L, R;
  HLD(const std::vector<std::vector<int>>& E, int root)
      : N(E.size()), E(E), p(N, -1), h(N), head(N), L(N), R(N) {
    dfs_sz(root);
    head[root] = root;
    dfs_hld(root);
  }
  int dfs_sz(int u) {
    int sz = 1, mx = 0;
    for (auto& v : E[u]) {
      if (v == p[u]) continue;
      p[v] = u, h[v] = h[u] + 1;
      int x = dfs_sz(v);
      sz += x;
      if (x > mx) {
        mx = x;
        std::swap(v, E[u][0]);
      }
    }
    return sz;
  }
  int timer = 0;
  void dfs_hld(int u) {
    L[u] = timer++;
    for (auto v : E[u]) {
      if (v == p[u]) continue;
      head[v] = (v == E[u][0] ? head[u] : v);
      dfs_hld(v);
    }
    R[u] = timer;
  }
  // boolean is true if path should be 'reversed' (for uncommutative operations)
  const std::vector<std::tuple<bool, int, int>>& get_path(int u, int v) const {
    static std::vector<std::tuple<bool, int, int>> left, right;
    left.clear();
    right.clear();
    while (head[u] != head[v]) {
      if (h[head[u]] > h[head[v]]) {
        left.emplace_back(true, L[head[u]], L[u] + 1);
        u = p[head[u]];
      } else {
        right.emplace_back(false, L[head[v]], L[v] + 1);
        v = p[head[v]];
      }
    }
    if (h[u] > h[v]) {
      left.emplace_back(true, L[v], L[u] + 1);
    } else {
      right.emplace_back(false, L[u], L[v] + 1);
    }
    left.insert(left.end(), right.rbegin(), right.rend());
    return left;
  }
  int lca(int u, int v) const {
    while (head[u] != head[v]) {
      if (h[head[u]] < h[head[v]]) std::swap(u, v);
      u = p[head[u]];
    }
    return h[u] < h[v] ? u : v;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int N, Q;
  std::cin >> N >> Q;
  std::string s;
  std::cin >> s;
  SuffixArray sa(s);
  auto st = build_suffix_tree(sa.p, sa.lcp);
  int M = st.size();
  std::vector<std::vector<int>> E(M);
  std::vector<int> state(N, -1);
  for (int u = 1; u < M; ++u) {
    E[st[u].link].push_back(u);
    if (st[u].idx + st[u].len == N) {
      state[st[u].idx] = u;
    }
  }
  HLD hld(E, 0);
  std::vector<int> len(M);
  for (int u = 1; u < M; ++u) {
    int p = st[u].link;
    len[hld.L[u]] = st[u].len - st[p].len;
  }
  SegmentTree<Node, int, LazyContext> seg;
  seg.init(len);
  auto query = [&](const auto& a) {
    int64_t res = 0;
    for (auto i : a) {
      int u = state[i];
      for (auto [rev, l, r] : hld.get_path(0, u)) {
        res += seg.qry(l, r).b;
      }
    }
    return res;
  };
  auto update = [&](const auto& a, int sgn) {
    for (auto i : a) {
      int u = state[i];
      for (auto [rev, l, r] : hld.get_path(0, u)) {
        seg.upd(l, r, sgn);
      }
    }
  };
  for (int q = 0; q < Q; ++q) {
    int K, L;
    std::cin >> K >> L;
    std::vector<int> a(K), b(L);
    for (int k = 0; k < K; ++k) {
      std::cin >> a[k];
      --a[k];
    }
    for (int l = 0; l < L; ++l) {
      std::cin >> b[l];
      --b[l];
    }
    update(b, +1);
    int64_t ans = query(a);
    if (q + 1 < Q) {
      update(b, -1);
    }
    std::cout << ans << '\n';
  }
  exit(0);
}