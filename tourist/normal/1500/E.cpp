/**
 *    author:  tourist
 *    created: 13.03.2021 13:07:39       
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

// https://github.com/kth-competitive-programming/kactl/blob/master/content/data-structures/FenwickTree.h

/**
 * Author: Lukas Polacek
 * Date: 2009-10-30
 * License: CC0
 * Source: folklore/TopCoder
 * Description: Computes partial sums a[0] + a[1] + ... + a[pos - 1], and updates single elements a[i],
 * taking the difference between the old and new value.
 * Time: Both operations are $O(\log N)$.
 * Status: Stress-tested
 */

typedef long long ll;

struct FT {
	vector<ll> s;
	FT(int n) : s(n) {}
	void update(int pos, ll dif) { // a[pos] += dif
		for (; pos < (int) s.size(); pos |= pos + 1) s[pos] += dif;
	}
	ll query(int pos) { // sum of values in [0, pos)
		ll res = 0;
		for (; pos > 0; pos &= pos - 1) res += s[pos-1];
		return res;
	}
	int lower_bound(ll sum) {// min pos st sum of [0, pos] >= sum
		// Returns n if no sum is >= sum, or -1 if empty sum is.
		if (sum <= 0) return -1;
		int pos = 0;
		for (int pw = 1 << 25; pw; pw >>= 1) {
			if (pos + pw <= (int) s.size() && s[pos + pw-1] < sum)
				pos += pw, sum -= s[pos-1];
		}
		return pos;
	}
};

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
  long long val;
  long long sum;
  long long sum_i; // sum (i * a[i])

  node(int _id, long long _val) {
    id = _id;
    l = r = p = nullptr;
    rev = false;
    sz = 1;
    // init extra variables:
    P = rng();
    val = _val;
    sum = val;
    sum_i = 0;
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
    sum = val;
    sum_i = 0;
    if (l != nullptr) {
      l->p = this;
      // now pull from l:
      sum_i = l->sum_i + l->sz * sum + sum_i;
      sum += l->sum;
      sz += l->sz;
    }
    if (r != nullptr) {
      r->p = this;
      // now pull from r:
      sum_i = sum_i + sz * r->sum + r->sum_i;
      sum += r->sum;
      sz += r->sz;
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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<long long> _s(n);
  for (int i = 0; i < n; i++) {
    cin >> _s[i];
  }
  vector<int> t(q);
  vector<long long> _a(q);
  for (int i = 0; i < q; i++) {
    cin >> t[i] >> _a[i];
  }
  vector<long long> all(n + q);
  for (int i = 0; i < n; i++) {
    all[i] = _s[i];
  }
  for (int i = 0; i < q; i++) {
    all[n + i] = _a[i];
  }
  sort(all.begin(), all.end());
  all.resize(unique(all.begin(), all.end()) - all.begin());
  int sz = (int) all.size();

  FT has(sz);
  FT val(sz);
  int cnt = 0;
  vector<node*> nodes(sz);
  for (int i = 0; i < sz; i++) {
    nodes[i] = new node(i, all[i]);
  }
  node* r = nullptr;

  auto Add = [&](int i) {
    has.update(i, +1);
    val.update(i, +all[i]);
    r = add(r, nodes[i], [&](node* nd) {
      return all[i] < nd->val;
    });
    ++cnt;
  };
  auto Remove = [&](int i) {
    has.update(i, -1);
    val.update(i, -all[i]);
    r = remove(nodes[i]);
    --cnt;
  };
  auto Calc = [&]() -> long long {
    if (cnt <= 1) {
      return 0LL;
    }
    int low = 1;
    int high = (cnt + 1) / 2;
    while (low < high) {
      int mid = (low + high) >> 1;
      int pos = has.lower_bound(mid + 1);
      long long small = val.query(pos + 1);
      pos = has.lower_bound(cnt - mid);
      long long big = val.query(sz) - val.query(pos + 1);
      if (big > small) {
        high = mid;
      } else {
        low = mid + 1;
      }
    }
    if (low == (cnt + 1) / 2) {
      long long ret = 2 * r->sum_i - r->sum * (cnt - 1);
      return ret;
    }
    auto p = split_leftmost_k(r, low);
    auto q = split_leftmost_k(p.second, cnt - 2 * low);
    long long ret = 0;
    ret += p.first->sum_i * 2 - p.first->sum * (2 * low - 1);
    ret += q.first->sum;
    ret += q.second->sum_i * 2 + q.second->sum;
    r = merge(p.first, merge(q.first, q.second));
    return ret;
  };
  
  
  vector<int> s(n);
  for (int i = 0; i < n; i++) { 
    s[i] = (int) (lower_bound(all.begin(), all.end(), _s[i]) - all.begin());
  }
  vector<int> a(q);
  for (int i = 0; i < q; i++) { 
    a[i] = (int) (lower_bound(all.begin(), all.end(), _a[i]) - all.begin());
  }
  for (int i = 0; i < n; i++) {
    Add(s[i]);
  }
  for (int i = 0; i <= q; i++) {
    cout << Calc() << '\n';
    if (i == q) {
      break;
    }
    if (t[i] == 1) {
      Add(a[i]);
    } else {
      Remove(a[i]);
    }
  }
  return 0;
}