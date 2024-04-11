/**
 *    author:  tourist
 *    created: 03.04.2020 18:38:46       
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

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());

class node {
 public:
  int id;
  node* l;
  node* r;
  node* p;
  bool rev;
  int sz;
  // declare extra variables:
  int P;

  node(int _id) {
    id = _id;
    l = r = p = nullptr;
    rev = false;
    sz = 1;
    // init extra variables:
    P = rng();
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

    if (l != nullptr) {
      l->p = this;
      sz += l->sz;
      // now pull from l:

    }
    if (r != nullptr) {
      r->p = this;
      sz += r->sz;
      // now pull from r:

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

namespace treap {

pair<node*, int> find(node* v, const function<int(node*)> &go_to) {
  // go_to returns: 0 -- found; -1 -- go left; 1 -- go right
  // find returns the last vertex on the descent and its go_to
  if (v == nullptr) {
    return {nullptr, 0};
  }
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
  int k = (v->l != nullptr ? v->l->sz : 0);
  while (v->p != nullptr) {
    if (v == v->p->r) {
      k++;
      if (v->p->l != nullptr) {
        k += v->p->l->sz;
      }
    }
    v = v->p;
  }
  return k;
}

node* get_bst_root(node* v) {
  while (v->p != nullptr) {
    v = v->p;
  }
  return v;
}

pair<node*, node*> split(node* v, const function<bool(node*)> &is_right) {
  if (v == nullptr) {
    return {nullptr, nullptr};
  }
  v->push();
  if (is_right(v)) {
    pair<node*, node*> p = split(v->l, is_right);
    if (p.first != nullptr) {
      p.first->p = nullptr;
    }
    v->l = p.second;
    v->pull();
    return {p.first, v};
  } else {
    pair<node*, node*> p = split(v->r, is_right);
    v->r = p.first;
    if (p.second != nullptr) {
      p.second->p = nullptr;
    }
    v->pull();
    return {v, p.second};
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
  if (v->P > u->P) {
//    if (rng() % (v->sz + u->sz) < (unsigned int) v->sz) {
    v->push();
    v->r = merge(v->r, u);
    v->pull();
    return v;
  } else {
    u->push();
    u->l = merge(v, u->l);
    u->pull();
    return u;
  }
}

int count_left(node* v, const function<bool(node*)> &is_right) {
  if (v == nullptr) {
    return 0;
  }
  v->push();
  if (is_right(v)) {
    return count_left(v->l, is_right);
  }
  return (v->l != nullptr ? v->l->sz : 0) + 1 + count_left(v->r, is_right);
}

node* add(node* r, node* v, const function<bool(node*)> &go_left) {
  pair<node*, node*> p = split(r, go_left);
  return merge(p.first, merge(v, p.second));
}

node* remove(node* v) { // returns the new root
  v->push();
  node* x = v->l;
  node* y = v->r;
  node* p = v->p;
  v->l = v->r = v->p = nullptr;
  v->push();
  v->pull(); // now v might be reusable...
  node* z = merge(x, y);
  if (p == nullptr) {
    if (z != nullptr) {
      z->p = nullptr;
    }
    return z;
  }
  if (p->l == v) {
    p->l = z;
  }
  if (p->r == v) {
    p->r = z;
  }
  while (true) {
    p->push();
    p->pull();
    if (p->p == nullptr) {
      break;
    }
    p = p->p;
  }
  return p;
}

node* next(node* v) {
  if (v->r == nullptr) {
    while (v->p != nullptr && v->p->r == v) {
      v = v->p;
    }
    return v->p;
  }
  v->push();
  v = v->r;
  while (v->l != nullptr) {
    v->push();
    v = v->l;
  }
  return v;
}

node* prev(node* v) {
  if (v->l == nullptr) {
    while (v->p != nullptr && v->p->l == v) {
      v = v->p;
    }
    return v->p;
  }
  v->push();
  v = v->l;
  while (v->r != nullptr) {
    v->push();
    v = v->r;
  }
  return v;
}

int get_size(node* v) {
  return (v != nullptr ? v->sz : 0);
}

template<typename... T>
void apply(node* v, T... args) {
  v->unsafe_apply(args...);
}

void reverse(node* v) {
  v->unsafe_reverse();
}

}  // namespace treap

using namespace treap;

const int ALPHA = 26;

int cnt[ALPHA];
vector<int> good[ALPHA];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    int n = (int) s.size();
    node* r = nullptr;
    for (int i = 0; i < n; i++) {
      r = merge(r, new node(i));
    }
    vector<pair<int, int>> st;
    vector<pair<int, int>> ops;
    auto Do = [&](int L, int R) {
      auto q = split(r, [&](node* nd) { return nd->id >= L; });
      auto w = split(q.second, [&](node* nd) { return nd->id >= R; });
      int sz = get_size(q.first);
      ops.emplace_back(sz, sz + get_size(w.first) - 1);
      r = merge(q.first, w.second);
    };
    for (int i = 0; i < n - 1; i++) {
      if (s[i] == s[i + 1]) {
        pair<int, int> p = make_pair(i + 1, (int) (s[i] - 'a'));
        st.push_back(p);
      }
    }
    int sz = (int) st.size();
    vector<int> pr(sz);
    vector<int> ne(sz);
    for (int i = 0; i < sz; i++) {
      pr[i] = i - 1;
      ne[i] = i + 1;
    }
    vector<bool> alive(sz, true);
    for (int i = 0; i < ALPHA; i++) {
      cnt[i] = 0;
      good[i].clear();
    }
    auto IsGood = [&](int i) -> bool {
      return (alive[i] && ((pr[i] != -1 && st[pr[i]].second != st[i].second) || (ne[i] != sz && st[ne[i]].second != st[i].second)));
    };
    auto Check = [&](int i) {
      if (0 <= i && i < sz && IsGood(i)) {
        good[st[i].second].push_back(i);
      }
    };
    auto Remove = [&](int i) {
      if (pr[i] != -1) {
        ne[pr[i]] = ne[i];
      }
      if (ne[i] != sz) {
        pr[ne[i]] = pr[i];
      }
      alive[i] = false;
      cnt[st[i].second] -= 1;
      Check(pr[i]);
      Check(ne[i]);
    };
    for (int i = 0; i < sz; i++) {
      cnt[st[i].second] += 1;
      Check(i);
    }
    while (true) {
      int id = 0;
      int sum = 0;
      for (int i = 0; i < ALPHA; i++) {
        if (cnt[i] > cnt[id]) {
          id = i;
        }
        sum += cnt[i];
      }
      if (sum == cnt[id]) {
        break;
      }
      while (!good[id].empty() && !IsGood(good[id].back())) {
        good[id].pop_back();
      }
      assert(!good[id].empty());
      int x = good[id].back();
      int y = ((pr[x] != -1 && st[pr[x]].second != st[x].second) ? pr[x] : ne[x]);
      assert(0 <= y && y < sz);
      if (x > y) {
        swap(x, y);
      }
      Do(st[x].first, st[y].first);
      Remove(x);
      Remove(y);
    }
    vector<int> all(1, 0);
    for (int i = 0; i < sz; i++) {
      if (alive[i]) {
        all.push_back(st[i].first);
      }
    }
    all.push_back(n);
    for (int i = 0; i < (int) all.size() - 1; i++) {
      Do(all[i], all[i + 1]);
    }
    cout << ops.size() << '\n';
    for (int i = 0; i < (int) ops.size(); i++) {
      cout << ops[i].first + 1 << " " << ops[i].second + 1 << '\n';
    }
  }
  return 0;
}