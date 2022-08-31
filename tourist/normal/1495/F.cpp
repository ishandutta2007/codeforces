/**
 *    author:  tourist
 *    created: 10.03.2021 16:13:46       
**/
#include <bits/stdc++.h>

using namespace std;

template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) {
  return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string((string) s);
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}

template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}

template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

class node {
 public:
  int id;
  node* l;
  node* r;
  node* p;
  bool rev;
  int sz;
  // declare extra variables:
  long long cost;
  long long sum;

  node(int _id) {
    id = _id;
    l = r = p = nullptr;
    rev = false;
    sz = 1;
    // init extra variables:
    cost = 0;
    sum = 0;
  }

  void unsafe_reverse() {
    rev ^= 1;
    swap(l, r);
    pull();
  }

  // apply changes:
  void unsafe_apply() {
    
  }

  void push() {
    if (rev) {
      if (l != nullptr) {
        l->unsafe_reverse();
      }
      if (r != nullptr) {
        r->unsafe_reverse();
      }
      rev = 0;
    }
    // now push everything else:

  }

  void pull() {
    sz = 1;
    // now init from self:
    sum = cost;
    if (l != nullptr) {
      l->p = this;
      sz += l->sz;
      // now pull from l:
      sum += l->sum;
    }
    if (r != nullptr) {
      r->p = this;
      sz += r->sz;
      // now pull from r:
      sum += r->sum;
    }
  }
};

void debug_node(node* v, string pref = "") {
  #ifdef LOCAL
    if (v != nullptr) {
      debug_node(v->r, pref + " ");
      cerr << pref << "-" << " " << v->id << '\n';
      debug_node(v->l, pref + " ");
    } else {
      cerr << pref << "-" << " " << "nullptr" << '\n';
    }
  #endif
}

namespace splay_tree {

bool is_bst_root(node* v) {
  if (v == nullptr) {
    return false;
  }
  return (v->p == nullptr || (v->p->l != v && v->p->r != v));
}

void rotate(node* v) {
  node* u = v->p;
  assert(u != nullptr);
  u->push();
  v->push();
  v->p = u->p;
  if (v->p != nullptr) {
    if (v->p->l == u) {
      v->p->l = v;
    }
    if (v->p->r == u) {
      v->p->r = v;
    }
  }
  if (v == u->l) {
    u->l = v->r;
    v->r = u;
  } else {
    u->r = v->l;
    v->l = u;
  }
  u->pull();
  v->pull();
}

void splay(node* v) {
  if (v == nullptr) {
    return;
  }
  while (!is_bst_root(v)) {
    node* u = v->p;
    if (!is_bst_root(u)) {
      if ((u->l == v) ^ (u->p->l == u)) {
        rotate(v);
      } else {
        rotate(u);
      }
    }
    rotate(v);
  }
}

pair<node*, int> find(node* v, const function<int(node*)> &go_to) {
  // go_to returns: 0 -- found; -1 -- go left; 1 -- go right
  // find returns the last vertex on the descent and its go_to
  if (v == nullptr) {
    return {nullptr, 0};
  }
  splay(v);
  int dir;
  while (true) {
    v->push();
    dir = go_to(v);
    if (dir == 0) {
      break;
    }
    node* u = (dir == -1 ? v->l : v->r);
    if (u == nullptr) {
      break;
    }
    v = u;
  }
  splay(v);
  return {v, dir};
}

node* get_leftmost(node* v) {
  return find(v, [&](node*) { return -1; }).first;
}

node* get_rightmost(node* v) {
  return find(v, [&](node*) { return 1; }).first;
}

node* get_kth(node* v, int k) { // 0-indexed
  pair<node*, int> p = find(v, [&](node* u) {
    if (u->l != nullptr) {
      if (u->l->sz > k) {
        return -1;
      }
      k -= u->l->sz;
    }
    if (k == 0) {
      return 0;
    }
    k--;
    return 1;
  });
  return (p.second == 0 ? p.first : nullptr);
}

int get_position(node* v) { // 0-indexed
  splay(v);
  return (v->l != nullptr ? v->l->sz : 0);
}

node* get_bst_root(node* v) {
  splay(v);
  return v;
}

pair<node*, node*> split(node* v, const function<bool(node*)> &is_right) {
  if (v == nullptr) {
    return {nullptr, nullptr};
  }
  pair<node*, int> p = find(v, [&](node* u) { return is_right(u) ? -1 : 1; });
  v = p.first;
  v->push();
  if (p.second == -1) {
    node* u = v->l;
    if (u == nullptr) {
      return {nullptr, v};
    }
    v->l = nullptr;
    u->p = v->p;
    u = get_rightmost(u);
    v->p = u;
    v->pull();
    return {u, v};
  } else {
    node* u = v->r;
    if (u == nullptr) {
      return {v, nullptr};
    }
    v->r = nullptr;
    v->pull();
    return {v, u};
  }
}

pair<node*, node*> split_leftmost_k(node* v, int k) {
  return split(v, [&](node* u) {
    int left_and_me = (u->l != nullptr ? u->l->sz : 0) + 1;
    if (k >= left_and_me) {
      k -= left_and_me;
      return false;
    }
    return true;
  });
}

node* merge(node* v, node* u) {
  if (v == nullptr) {
    return u;
  }
  if (u == nullptr) {
    return v;
  }
  v = get_rightmost(v);
  assert(v->r == nullptr);
  splay(u);
  v->push();
  v->r = u;
  v->pull();
  return v;
}

int count_left(node* v, const function<bool(node*)> &is_right) {
  if (v == nullptr) {
    return 0;
  }
  pair<node*, int> p = find(v, [&](node* u) { return is_right(u) ? -1 : 1; });
  node* u = p.first;
  return (u->l != nullptr ? u->l->sz : 0) + (p.second == 1);
}

node* add(node* r, node* v, const function<bool(node*)> &go_left) {
  pair<node*, node*> p = split(r, go_left);
  return merge(p.first, merge(v, p.second));
}

node* remove(node* v) { // returns the new root
  splay(v);
  v->push();
  node* x = v->l;
  node* y = v->r;
  v->l = v->r = nullptr;
  node* z = merge(x, y);
  if (z != nullptr) {
    z->p = v->p;
  }
  v->p = nullptr;
  v->push();
  v->pull(); // now v might be reusable...
  return z;
}

node* next(node* v) {
  splay(v);
  v->push();
  if (v->r == nullptr) {
    return nullptr;
  }
  v = v->r;
  while (v->l != nullptr) {
    v->push();
    v = v->l;
  }
  splay(v);
  return v;
}

node* prev(node* v) {
  splay(v);
  v->push();
  if (v->l == nullptr) {
    return nullptr;
  }
  v = v->l;
  while (v->r != nullptr) {
    v->push();
    v = v->r;
  }
  splay(v);
  return v;
}

int get_size(node* v) {
  splay(v);
  return (v != nullptr ? v->sz : 0);
}

template<typename... T>
void apply(node* v, T... args) {
  splay(v);
  v->unsafe_apply(args...);
}

void reverse(node* v) {
  splay(v);
  v->unsafe_reverse();
}

}  // namespace splay_tree

using namespace splay_tree;

template <bool rooted>
class link_cut_tree {
 public:
  int n;
  vector<node*> nodes;

  link_cut_tree(int _n) : n(_n) {
    nodes.resize(n);
    for (int i = 0; i < n; i++) {
      nodes[i] = new node(i);
    }
  }

  int add_node() {
    int id = (int) nodes.size();
    nodes.push_back(new node(id));
    return id;
  }

  void expose(node* v) {
    node* r = nullptr;
    node* u = v;
    while (u != nullptr) {
      splay(u);
      u->push();
      u->r = r;
      u->pull();
      r = u;
      u = u->p;
    }
    splay(v);
    assert(v->p == nullptr);
  }

  int get_root(int i) {
    node* v = nodes[i];
    expose(v);
    return get_leftmost(v)->id;
  }

  bool link(int i, int j) { // for rooted: (x, parent[x])
    if (i == j) {
      return false;
    }
    node* v = nodes[i];
    node* u = nodes[j];
    if (rooted) {
      splay(v);
      if (v->p != nullptr || v->l != nullptr) {
        return false; // not a root
      }
    } else {
      make_root(i);
    }
    expose(u);
    if (v->p != nullptr) {
      return false;
    }
    v->p = u;
    return true;
  }

  bool cut(int i, int j) { // for rooted: (x, parent[x])
    if (i == j) {
      return false;
    }
    node* v = nodes[i];
    node* u = nodes[j];
    expose(u);
    splay(v);
    if (v->p != u) {
      if (rooted) {
        return false;
      }
      swap(u, v);
      expose(u);
      splay(v);
      if (v->p != u) {
        return false;
      }
    }
    v->p = nullptr;
    return true;
  }

  bool cut(int i) { // only for rooted
    assert(rooted);
    node* v = nodes[i];
    expose(v);
    v->push();
    if (v->l == nullptr) {
      return false; // already a root
    }
    v->l->p = nullptr;
    v->l = nullptr;
    v->pull();
    return true;
  }

  bool connected(int i, int j) {
    if (i == j) {
      return true;
    }
    node* v = nodes[i];
    node* u = nodes[j];
    expose(v);
    expose(u);
    return v->p != nullptr;
  }

  int lca(int i, int j) {
    if (i == j) {
      return i;
    }
    node* v = nodes[i];
    node* u = nodes[j];
    expose(v);
    expose(u);
    if (v->p == nullptr) {
      return -1;
    }
    splay(v);
    if (v->p == nullptr) {
      return v->id;
    }
    return v->p->id;
  }

  bool is_ancestor(int i, int j) {
    if (i == j) {
      return true;
    }
    node* v = nodes[i];
    node* u = nodes[j];
    expose(u);
    splay(v);
    return v->p == nullptr && u->p != nullptr;
  }

  void make_root(int i) {
    assert(!rooted);
    node* v = nodes[i];
    expose(v);
    reverse(v);
  }

  node* get_path_from_root(int i) {
    node* v = nodes[i];
    expose(v);
    return v;
  }

  template <typename... T>
  void apply(int i, T... args) {
    node* v = nodes[i];
    splay_tree::apply(v, args...);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    --p[i];
  }
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<long long> b(n);
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  vector<int> x(q);
  for (int i = 0; i < q; i++) {
    cin >> x[i];
    --x[i];
  }
  p.push_back(n);
  vector<int> nxt(n + 1);
  nxt[n] = n;
  vector<int> st(1, n);
  for (int i = n - 1; i >= 0; i--) {
    while (!st.empty() && p[st.back()] < p[i]) {
      st.pop_back();
    }
    nxt[i] = st.back();
    st.push_back(i);
  }
  const int LOG = 20;
  vector<vector<int>> pr(n + 1, vector<int>(LOG));
  vector<vector<long long>> pc(n + 1, vector<long long>(LOG));
  for (int i = 0; i <= n; i++) {
    pr[i][0] = nxt[i];
  }
  for (int j = 1; j < LOG; j++) {
    for (int i = 0; i <= n; i++) {
      pr[i][j] = pr[pr[i][j - 1]][j - 1];
    }
  }
  vector<long long> cost(n + 1);
  for (int i = n - 1; i >= 0; i--) {
    int x = i + 1;
    cost[i] = a[i];
    for (int j = LOG - 1; j >= 0; j--) {
      if (pr[x][j] <= nxt[i]) {
        cost[i] += pc[x][j];
        x = pr[x][j];
      }
    }
    assert(x == nxt[i]);
    cost[i] = min(cost[i], b[i]);
    pc[i][0] = cost[i];
    for (int j = 1; j < LOG; j++) {
      pc[i][j] = pc[i][j - 1] + pc[pr[i][j - 1]][j - 1];
    }
  }
  debug(nxt);
  debug(cost);
  vector<vector<tuple<int, int, int>>> at(n + 1);
  vector<long long> delta(q);
  set<int> must;
  must.insert(0);
  must.insert(n);
  at[n].emplace_back(0, 0, +1);
  for (int i = 0; i < q; i++) {
    if (x[i] == 0) {
      continue;
    }
    auto it = must.find(x[i]);
    if (it != must.end()) {
      assert(it != must.begin());
      int L = *prev(it);
      assert(next(it) != must.end());
      int R = *next(it);
      at[R].emplace_back(L, i, +1);
      at[R].emplace_back(x[i], i, -1);
      at[x[i]].emplace_back(L, i, -1);
      must.erase(it);
    } else {
      it = must.lower_bound(x[i]);
      assert(it != must.end());
      int R = *it;
      assert(it != must.begin());
      int L = *prev(it);
      at[R].emplace_back(L, i, -1);
      at[R].emplace_back(x[i], i, +1);
      at[x[i]].emplace_back(L, i, +1);
      must.insert(x[i]);
    }
  }
  vector<vector<int>> for_whom(n + 1);
  for (int i = 0; i < n; i++) {
    for_whom[nxt[i]].push_back(i);
  }
  link_cut_tree<true> lct(n + 1);
  for (int i = 0; i <= n; i++) {
    for (int j : for_whom[i]) {
      lct.cut(j, j + 1);
      splay(lct.nodes[j]);
      lct.nodes[j]->cost = cost[j];
      lct.nodes[j]->pull();
      lct.link(j, i);
    }
    for (auto& e : at[i]) {
      delta[get<1>(e)] += get<2>(e) * lct.get_path_from_root(get<0>(e))->sum;
    }
    if (i < n) {
      splay(lct.nodes[i]);
      lct.nodes[i]->cost = a[i];
      lct.nodes[i]->pull();
      lct.link(i, i + 1);
    }
  }
  long long ans = 0;
  for (int i = 0; i < q; i++) {
    ans += delta[i];
    cout << ans << '\n';
  }
  return 0;
}