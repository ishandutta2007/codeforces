/**
 *    author:  tourist
 *    created: 30.07.2021 17:54:21       
**/
#include <bits/stdc++.h>

using namespace std;

int n;

class node {
 public:
  int id;
  node* l;
  node* r;
  node* p;
  bool rev;
  int sz;
  // declare extra variables:
  int fake_sz;
  int w;
  int sum_w;
  int b;
  int add_b;
  int sum_b;

  node(int _id, int _w) {
    id = _id;
    l = r = p = nullptr;
    rev = false;
    sz = 1;
    // init extra variables:
    fake_sz = (id >= n);
    w = _w;
    sum_w = w;
    b = 0;
    add_b = 0;
    sum_b = 0;
  }

  // push everything else:
  void push_stuff() {
    if (add_b != 0) {
      if (l != nullptr) {
        l->unsafe_apply(add_b);
      }
      if (r != nullptr) {
        r->unsafe_apply(add_b);
      }
      add_b = 0;
    }
  }

  void unsafe_reverse() {
    push_stuff();
    rev ^= 1;
    swap(l, r);
    pull();
  }

  // apply changes:
  void unsafe_apply(int bb) {
    if (id >= n) {
      b += bb;
    }
    add_b += bb;
    sum_b += bb * fake_sz;
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
    push_stuff();
  }

  void pull() {
    sz = 1;
    // now init from self:
    sum_w = w;
    sum_b = b;
    fake_sz = (id >= n);
    if (l != nullptr) {
      l->p = this;
      sz += l->sz;
      // now pull from l:
      sum_w += l->sum_w;
      sum_b += l->sum_b;
      fake_sz += l->fake_sz;
    }
    if (r != nullptr) {
      r->p = this;
      sz += r->sz;
      // now pull from r:
      sum_w += r->sum_w;
      sum_b += r->sum_b;
      fake_sz += r->fake_sz;
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
void my_apply(node* v, T... args) {
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
      nodes[i] = new node(i, 0);
    }
  }

  int add_node(int x) {
    int id = (int) nodes.size();
    nodes.push_back(new node(id, x));
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
  void my_apply(int i, T... args) {
    node* v = nodes[i];
    splay_tree::my_apply(v, args...);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> n >> tt;
  link_cut_tree<false> lct(n);
  while (tt--) {
    int u, v, x;
    cin >> u >> v >> x;
    --u; --v;
    if (lct.connected(u, v)) {
      lct.make_root(u);
      auto t = lct.get_path_from_root(v);
      if (t->sum_b == 0 && (t->sum_w + x) % 2 == 1) {
        cout << "YES" << '\n';
        my_apply(t, 1);
      } else {
        cout << "NO" << '\n';
      }
    } else {
      cout << "YES" << '\n';
      int tmp = lct.add_node(x);
      lct.link(u, tmp);
      lct.link(v, tmp);
    }
  }
  return 0;
}