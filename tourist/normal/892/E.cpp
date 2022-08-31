/**
 *    author:  tourist
 *    created: 17.10.2018 17:13:02       
**/
#include <bits/stdc++.h>

using namespace std;

class node {
  public:
  int id;
  node* l;
  node* r;
  node* p;
  bool rev;
  int sz;
  // declare extra variables:


  node(int _id) {
    id = _id;
    l = r = p = NULL;
    rev = false;
    sz = 1;
    // init extra variables:

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
      if (l != NULL) {
        l->unsafe_reverse();
      }
      if (r != NULL) {
        r->unsafe_reverse();
      }
      rev = 0;
    }
    // now push everything else:

  }

  void pull() {
    sz = 1;
    // now init from self:

    if (l != NULL) {
      l->p = this;
      sz += l->sz;
      // now pull from l:

    }
    if (r != NULL) {
      r->p = this;
      sz += r->sz;
      // now pull from r:

    }
  }
};

namespace splay_tree {
  bool is_bst_root(node* v) {
    if (v == NULL) {
      return false;
    }
    return (v->p == NULL || (v->p->l != v && v->p->r != v));
  }

  void rotate(node* v) {
    node* u = v->p;
    assert(u != NULL);
    u->push();
    v->push();
    if (v == u->l) {
      u->l = v->r;
      v->r = u;
    } else {
      u->r = v->l;
      v->l = u;
    }
    v->p = u->p;
    if (v->p != NULL) {
      if (v->p->l == u) {
        v->p->l = v;
      }
      if (v->p->r == u) {
        v->p->r = v;
      }
    }
    u->pull();
    v->pull();
  }

  void splay(node* v) {
    if (v == NULL) {
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

  pair<node*,int> find(node* v, const function<int(node*)> &go_to) {
    // go_to returns: 0 -- found; -1 -- go left; 1 -- go right
    if (v == NULL) {
      return {NULL, 0};
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
      if (u == NULL) {
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
    pair<node*,int> p = find(v, [&](node* u) {
      if (u->l != NULL) {
        if (u->sz > k) {
          return -1;
        }
        k -= u->sz;
      }
      if (k == 0) {
        return 0;
      }
      k--;
      return 1;
    });
    return (p.second == 0 ? p.first : NULL);
  }

  int get_position(node* v) { // 0-indexed
    splay(v);
    return (v->l != NULL ? v->sz : 0);
  }

  node* get_bst_root(node* v) {
    splay(v);
    return v;
  }

  pair<node*,node*> split(node* v, const function<bool(node*)> &is_right) {
    if (v == NULL) {
      return {NULL, NULL};
    }
    pair<node*,int> p = find(v, [&](node* u) { return is_right(u) ? -1 : 1; });
    v = p.first;
    v->push();
    if (p.second == -1) {
      node* u = v->l;
      if (u == NULL) {
        return {NULL, v};
      }
      v->l = NULL;
      u->p = v->p;
      u = get_rightmost(u);
      v->p = u;
      v->pull();
      return {u, v};
    } else {
      node* u = v->r;
      if (u == NULL) {
        return {v, NULL};
      }
      v->r = NULL;
      v->pull();
      return {v, u};
    }
  }

  pair<node*,node*> split_leftmost_k(node* v, int k) {
    return split(v, [&](node* u) {
      int left_and_me = (u->l != NULL ? u->l->sz : 0) + 1;
      if (k >= left_and_me) {
        k -= left_and_me;
        return false;
      }
      return true;
    });
  }

  node* merge(node* v, node* u) {
    if (v == NULL) {
      return u;
    }
    if (u == NULL) {
      return v;
    }
    v = get_rightmost(v);
    assert(v->r == NULL);
    splay(u);
    v->push();
    v->r = u;
    v->pull();
    return v;
  }

  node* remove(node* v) {
    splay(v);
    v->push();
    node* x = v->l;
    node* y = v->r;
    v->l = v->r = NULL;
    node* z = merge(x, y);
    z->p = v->p;
    v->p = NULL;
    return z;
  }

  int get_size(node* v) {
    splay(v);
    return v->sz;
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
}

using namespace splay_tree;

template<bool rooted>
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
    node* r = NULL;
    node* u = v;
    while (u != NULL) {
      splay(u);
      u->push();
      u->r = r;
      u->pull();
      r = u;
      u = u->p;
    }
    splay(v);
    assert(v->p == NULL);
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
      assert(v->p == NULL && v->l == NULL); // must be a root
    } else {
      make_root(i);
    }
    expose(u);
    if (v->p != NULL) {
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
    v->p = NULL;
    return true;
  }

  bool connected(int i, int j) {
    if (i == j) {
      return true;
    }
    node* v = nodes[i];
    node* u = nodes[j];
    expose(v);
    assert(v->p == NULL);
    expose(u);
    return v->p != NULL;
  }

  int lca(int i, int j) {
    if (i == j) {
      return i;
    }
    node* v = nodes[i];
    node* u = nodes[j];
    expose(v);
    assert(v->p == NULL);
    expose(u);
    if (v->p == NULL) {
      return -1;
    }
    splay(v);
    if (v->p == NULL) {
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
    assert(u->p == NULL);
    splay(v);
    return v->p == NULL && u->p != NULL;
  }

  void make_root(int i) {
    assert(!rooted);
    node* v = nodes[i];
    expose(v);
    assert(v->r == NULL);
    reverse(v);
  }

  node* get_path_from_root(int i) {
    node* v = nodes[i];
    expose(v);
    return v;
  }

  template<typename... T>
  void apply(int i, T... args) {
    node* v = nodes[i];
    splay_tree::apply(v, args...);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  const int MAX = 500010;
  vector<vector<int>> g(MAX);
  vector<map<int,vector<int>>> t(MAX);
  vector<int> from(m), to(m), cost(m);
  for (int i = 0; i < m; i++) {
    cin >> from[i] >> to[i] >> cost[i];
    from[i]--; to[i]--;
    g[cost[i]].push_back(i);
  }
  int tt;
  cin >> tt;
  for (int qq = 0; qq < tt; qq++) {
    int foo;
    cin >> foo;
    for (int i = 0; i < foo; i++) {
      int bar;
      cin >> bar;
      bar--;
      t[cost[bar]][qq].push_back(bar);
    }
  }
  vector<int> res(tt, 1);
  link_cut_tree<false> lct(n);
  for (int i = 0; i < MAX; i++) {
    for (auto &p : t[i]) {
      if (res[p.first] == 0) {
        continue;
      }
      int cc = 0;
      for (int id = 0; id < (int) p.second.size(); id++) {
        int j = p.second[id];
        if (lct.connected(from[j], to[j])) {
          res[p.first] = 0;
          break;
        }
        cc++;
        lct.link(from[j], to[j]);
      }
      for (int id = 0; id < cc; id++) {
        int j = p.second[id];
        lct.cut(from[j], to[j]);
      }
    }
    for (int j : g[i]) {
      lct.link(from[j], to[j]);
    }
  }
  for (int i = 0; i < tt; i++) {
    cout << (res[i] ? "YES" : "NO") << '\n';
  }
  return 0;
}