// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <chrono>
#include <random>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <iomanip>
#define dibs reserve
#define OVER9000 1234567890123456789LL
#define tisic 47
#define soclose 1e-8
#define patkan 9
#define ff first
#define ss second
using uint = unsigned int;
using cat = long long;
using dbl = long double;
constexpr dbl pi = 3.14159265358979323846;
using namespace std;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

template <typename T>
T abs(T x) { return (x < 0) ? (-x) : x; }

cat pw(cat a, cat e, cat mod) {
	if(e <= 0) return 1;
	cat x = pw(a, e/2, mod);
	x = x * x % mod;
	return (e&1) ? x * a % mod : x;
}

template <typename T>
class fin {
	vector<T> node_val;

	int lastone(int x) { return x & (x ^ (x-1)); }

public:
	fin(int N, T init_val) {
		node_val.resize(N+10, init_val);
	}

	void put(int pos, T val) {
		for(int i = pos+1; i < (int)node_val.size(); i += lastone(i))
			node_val[i] += val;
	}

	T get(int pos) {
		T ret = 0;
		for(int i = pos+1; i > 0; i -= lastone(i))
			ret += node_val[i];
		return ret;
	}
};

struct itree {
	vector<int> mx;
	int b;

	vector<int> save_val, save_used;

	itree(int N) {
		b = 1;
		while(b < N) b *= 2;
		mx.resize(2*b, 0);
		save_val.resize(2*b, -1);
	}

	void set(int pos, int val, int cur = 1, int l = 0, int r = 0) {
		if(cur == 1) r = b;
		if(l+1 == r) {
			mx[cur] = val;
			return;
		}
		int mid = (l+r)/2;
		if(pos < mid) set(pos, val, 2*cur, l, mid);
		else set(pos, val, 2*cur+1, mid, r);
		mx[cur] = max(mx[2*cur], mx[2*cur+1]);
	}

	int get_max(int I_l, int I_r, int cur = 1, int l = 0, int r = 0) {
		if(cur == 1) r = b;
		I_l = max(I_l, l);
		I_r = min(I_r, r);
		if(I_l >= I_r) return -1;
		if(I_l == l && I_r == r) return mx[cur];
		if(save_val[cur] != -1) return save_val[cur];
		save_used.push_back(cur);
		int mid = (l+r)/2;
		return save_val[cur] = max(get_max(I_l, I_r, 2*cur, l, mid), get_max(I_l, I_r, 2*cur+1, mid, r));
	}

	int get_ge_l(int I_l, int I_r, int val, int cur = 1, int l = 0, int r = 0) {
		// leftmost >= val
		if(cur == 1) r = b;
		I_l = max(I_l, l);
		I_r = min(I_r, r);
		if(l+1 == r) return l;
		int mid = (l+r)/2;
		if(I_l < mid && get_max(I_l, I_r, 2*cur, l, mid) >= val)
			return get_ge_l(I_l, I_r, val, 2*cur, l, mid);
		else return get_ge_l(I_l, I_r, val, 2*cur+1, mid, r);
	}

	int get_ge_r(int I_l, int I_r, int val, int cur = 1, int l = 0, int r = 0) {
		// rightmost >= val
		if(cur == 1) r = b;
		I_l = max(I_l, l);
		I_r = min(I_r, r);
		if(l+1 == r) return l;
		int mid = (l+r)/2;
		if(I_r > mid && get_max(I_l, I_r, 2*cur+1, mid, r) >= val)
			return get_ge_r(I_l, I_r, val, 2*cur+1, mid, r);
		else return get_ge_r(I_l, I_r, val, 2*cur, l, mid);
	}

	void clear_saved() {
		for(auto v : save_used) save_val[v] = -1;
		save_used.clear();
	}
};

struct elem {
	int val, pos;

	elem operator*(int c) const {
		return elem{.val = this->val * c, .pos = this->pos};
	}
	elem & operator*=(int c) {
		this->val *= c;
		return *this;
	}

	elem operator+(const elem & other) const {
		return elem{.val = this->val + other.val, .pos = this->pos};
	}
	elem & operator+=(const elem & other) {
		this->val += other.val;
		return *this;
	}

	bool operator<(const elem & other) const {
		return (this->pos < other.pos);
	}

	bool operator==(const elem & other) const {
		return (this->pos == other.pos);
	}

	elem max(const elem & other) const {
		return elem{.val = ::max(this->val, other.val), .pos = this->pos};
	}
};

#ifndef _TREAP_H
#define _TREAP_H

#include <algorithm> // std::sort
#include <vector> // std::vector
#include <utility> // std::pair
#include <random> // std::mt19937_64
#include <chrono>

template <typename T>
class treap {
 private:
  struct node;
  using pnode = struct node *;

  std::mt19937_64 * rng_;
  bool rng_owner_;
  bool is_sorted_;
  bool stop_; // for priority regeneration
  pnode root_;

  using priority_t = std::mt19937_64::result_type;

  priority_t next_priority () {
    priority_t priority = (*rng_)();
    return priority;
  }

  void regenerate_priorities_recursive (std::vector <int> & new_priors, pnode & t, int l, int r) {
    if (!t)
      return;
    t->priority = new_priors[r - 1];
    regenerate_priorities_recursive(new_priors, t->l, l, l + cnt(t->l));
    regenerate_priorities_recursive(new_priors, t->r, l + cnt(t->l), r - 1);
  }

  void regenerate_priorities () {
    int sz = size();
    std::vector <int> new_priors(sz);
    for (int i = 0; i < sz; i++)
      new_priors[i] = next_priority();
    std::sort(new_priors.begin(), new_priors.end());
    for (int i = 0; i < sz; i++)
      new_priors[i] += i;
    regenerate_priorities_recursive(new_priors, root_, 0, sz);
  }

  struct node {
    priority_t priority;
    int cnt, rev;
    T key, add, fmax;
    pnode l, r;

    node (T x, priority_t p) {
      add = x * 0;
      key = fmax = x;
      cnt = 1;
      rev = 0;
      l = r = nullptr;
      priority = p;
    }
  };

  int cnt (pnode t) {
    return t ? t->cnt : 0;
  }

  void upd_cnt (pnode t) {
    if (t)
      t->cnt = cnt(t->l) + cnt(t->r) + 1;
  }

  void upd_sum (pnode t) {
    if (t) {
      t->fmax = t->key;
      if (t->l)
        t->fmax = t->fmax.max(t->l->fmax);
      if (t->r)
        t->fmax = t->fmax.max(t->r->fmax);
    }
  }

  void update (pnode t, T add, int rev) {
    if (!t)
      return;
    t->add = t->add + add;
    t->rev = t->rev ^ rev;
    t->key = t->key + add;
    t->fmax = t->fmax + add;
  }

  void push (pnode t) {
    if (!t || (t->add.val == 0 && t->rev == 0))
      return;
    update(t->l, t->add, t->rev);
    update(t->r, t->add, t->rev);
    if (t->rev)
      std::swap(t->l, t->r);
    t->add = T() * 0;
    t->rev = 0;
  }

  void merge (pnode & t, pnode l, pnode r) {
    push(l);
    push(r);
    if (!l || !r)
      t = l ? l : r;
    else if (l->priority > r->priority) {
      merge(l->r, l->r, r);
      t = l;
    }
    else {
      merge(r->l, l, r->l);
      t = r;
    }
    upd_cnt(t);
    upd_sum(t);
  }

  void split (pnode t, pnode & l, pnode & r, int index) { // split at position
    if (!t) {
      l = r = 0;
      return;
    }
    push(t);
    if (index <= cnt(t->l)) {
      split(t->l, l, t->l, index);
      r = t;
    }
    else {
      split(t->r, t->r, r, index - 1 - cnt(t->l));
      l = t;
    }
    upd_cnt(t);
    upd_sum(t);
  }

  void split_at (pnode t, pnode & l, pnode & r, T & key, bool & eq) { // split by key
    if (!t) {
      l = r = 0;
      return;
    }
    push(t);
    if (key == t->key) {
      eq = true;
      return;
    }
    if (key < t->key) {
      split_at(t->l, l, t->l, key, eq);
      if (!eq)
        r = t;
    }
    else {
      split_at(t->r, t->r, r, key, eq);
      if (!eq)
        l = t;
    }
    if (!eq)
      upd_cnt(t);
    upd_sum(t);
  }

  void insert (pnode & t, pnode it, int index) { // insert at position
    push(t);
    if (!t)
      t = it;
    else if (it->priority == t->priority) {
      stop_ = true;
      regenerate_priorities();
    }
    else if (it->priority > t->priority) {
      split(t, it->l, it->r, index);
      t = it;
    }
    else if (index <= cnt(t->l))
      insert(t->l, it, index);
    else
      insert(t->r, it, index - cnt(t->l) - 1);
    if (stop_)
      return;
    upd_cnt(t);
    upd_sum(t);
  }

  void insert_at (pnode & t, pnode it, bool & eq) { // insert by key
    push(t);
    if (!t)
      t = it;
    else if (it->key == t->key) {
      eq = true;
      return;
    }
    else if (it->priority == t->priority) {
      stop_ = true;
      regenerate_priorities();
    }
    else if (it->priority > t->priority) {
      split_at(t, it->l, it->r, it->key, eq);
      if (!eq)
        t = it;
    }
    else if (it->key < t->key)
      insert_at(t->l, it, eq);
    else
      insert_at(t->r, it, eq);
    if (stop_)
      return;
    if (!eq)
      upd_cnt(t);
    upd_sum(t);
  }

  void erase (pnode & t, int index) {
    push(t);
    if (cnt(t->l) == index) {
      pnode l = t->l, r = t->r;
      delete t;
      t = nullptr;
      merge(t, l, r);
    }
    else if (index < cnt(t->l))
      erase(t->l, index);
    else
      erase(t->r, index - cnt(t->l) - 1);
    upd_cnt(t);
    upd_sum(t);
  }

  void erase_at (pnode & t, T key, bool & found) {
    push(t);
    if (key == t->key) {
      pnode l = t->l, r = t->r;
      delete t;
      t = nullptr;
      merge(t, l, r);
      found = true;
    }
    else if (key < t->key)
      erase_at(t->l, key, found);
    else
      erase_at(t->r, key, found);
    upd_cnt(t);
    upd_sum(t);
  }

  T get (pnode t, int index) {
    push(t);
    if (index < cnt(t->l))
      return get(t->l, index);
    else if (index > cnt(t->l))
      return get(t->r, index - cnt(t->l) - 1);
    return t->key;
  }

  int find (pnode t, T key) {
    push(t);
    if (!t || key == t->key)
      return cnt(t->l);
    if (key < t->key)
      return get(t->l, key);
    else
      return get(t->r, key) + 1 + cnt(t->l);
  }

  std::pair <T, int> lower_bound (pnode t, T key, int index) {
    push(t);
    if (!t)
      return {T(), size()};
    if (key == t->key)
      return {key, index + cnt(t->l)};
    if (key < t->key) {
      std::pair <T, int> ret = lower_bound(t->l, key, index);
      if (ret.second == size())
        ret = {t->key, index + cnt(t->l)};
      return ret;
    }
    return lower_bound(t->r, key, index + 1 + cnt(t->l));
  }

  std::pair <T, int> upper_bound (pnode t, T key, int index) {
    push(t);
    if (!t)
      return {T(), size()};
    if (key < t->key) {
      std::pair <T, int> ret = upper_bound(t->l, key, index);
      if (ret.second == size())
        ret = {t->key, index + cnt(t->l)};
      return ret;
    }
    return upper_bound(t->r, key, index + 1 + cnt(t->l));
  }

  void shift (pnode & t, int l, int r, T add) {
    pnode l1, r1;
    split(t, l1, r1, r + 1);
    pnode l2, r2;
    split(l1, l2, r2, l);
    update(r2, add, 0);
    pnode t2;
    merge(t2, l2, r2);
    merge(t, t2, r1);
  }

  void reverse (pnode & t, int l, int r) {
    pnode l1, r1;
    split(t, l1, r1, r + 1);
    pnode l2, r2;
    split(l1, l2, r2, l);
    update(r2, 0 * T(), 1);
    pnode t2;
    merge(t2, l2, r2);
    merge(t, t2, r1);
  }

  void move (pnode & t, int left, int right, int shift) {
    // [l, r) becomes [l+shift, r+shift)
    if (shift == 0)
      return;
    int l = left + std::min(0, shift);
    int r = right + std::max(0, shift);
    int m = (shift > 0) ? right : left;
    pnode prefix, tmp;
    split(root_, prefix, tmp, l);
    pnode suffix, middle;
    split(tmp, middle, suffix, r - l);
    pnode mid_prefix, mid_suffix;
    split(middle, mid_prefix, mid_suffix, m - l);
    merge(middle, mid_suffix, mid_prefix);
    merge(tmp, middle, suffix);
    merge(root_, prefix, tmp);
  }

  T get_max (pnode & t, int l, int r) {
    pnode l1, r1;
    split(t, l1, r1, r + 1);
    pnode l2, r2;
    split(l1, l2, r2, l);
    T ret = r2->fmax;
    pnode t2;
    merge(t2, l2, r2);
    merge(t, t2, r1);
    return ret;
  }

  pair<int,int> get_max_val_range_l(pnode t, int max_val) {
    push(t);
    int l = cnt(t), r = -1;
    if (!t || t->fmax.val != max_val) return {l, r};
    if (t->key.val == max_val) {
      l = r = cnt(t->l);
      pair<int,int> pr = get_max_val_range_l(t->r, max_val);
      if(pr.ss-pr.ff >= 0) r = pr.ss+cnt(t->l)+1;
    }
    else {
      pair<int,int> pl = get_max_val_range_l(t->l, max_val);
      if(pl.ss-pl.ff >= 0) return pl;
    }
    return {l, r};
  }

  pair<int,int> get_max_val_range_r(pnode t, int max_val) {
    push(t);
    int l = cnt(t), r = -1;
    if (!t || t->fmax.val != max_val) return {l, r};
    if (t->key.val == max_val) {
      l = r = cnt(t->l);
      pair<int,int> pl = get_max_val_range_r(t->l, max_val);
      if(pl.ss-pl.ff >= 0) l = pl.ff;
    }
    else {
      pair<int,int> pr = get_max_val_range_r(t->r, max_val);
      if(pr.ss-pr.ff >= 0) return {pr.ff+cnt(t->l)+1, pr.ss+cnt(t->l)+1};
    }
    return {l, r};
  }

  pair<int,int> get_max_val_range(pnode t, int max_val) {
    push(t);
    int l = cnt(t), r = -1;
    if (!t || t->fmax.val != max_val) return {l, r};
    if (t->key.val == max_val) {
      pair<int,int> pl = get_max_val_range_r(t->l, max_val);
      pair<int,int> pr = get_max_val_range_l(t->r, max_val);
      l = r = cnt(t->l);
      if(pl.ss-pl.ff >= 0) l = pl.ff;
      if(pr.ss-pr.ff >= 0) r = pr.ss+cnt(t->l)+1;
    }
    else {
      pair<int,int> pl = get_max_val_range(t->l, max_val);
      pair<int,int> pr = get_max_val_range(t->r, max_val);
      if(pl.ss-pl.ff >= 0) return pl;
      if(pr.ss-pr.ff >= 0) return {pr.ff+cnt(t->l)+1, pr.ss+cnt(t->l)+1};
    }
    return {l, r};
  }

  void clear (pnode & t) {
    if (!t)
      return;
    clear(t->l);
    clear(t->r);
    delete t;
    t = nullptr;
  }

 public:
  treap (std::mt19937_64 * rng = nullptr) {
    is_sorted_ = true;
    stop_ = false;
    root_ = nullptr;
    if (rng) {
      rng_owner_ = false;
      rng_ = rng;
    }
    else {
      rng_owner_ = true;
      rng_ = new std::mt19937_64;
      rng_->seed(std::chrono::steady_clock::now().time_since_epoch().count());
    }
  }

  ~treap () {
    if (rng_owner_)
      delete rng_;
    clear(root_);
  }

  int size () { return cnt(root_); }

  bool empty () { return (cnt(root_) == 0); }

  bool is_sorted () { return is_sorted_; }

  void srand (std::mt19937_64::result_type seed) {
    // optional
    rng_->seed(seed);
  }

  bool insert (T x) {
    if (!is_sorted_)
      return false;
    bool eq = false;
    pnode t = new node(x, next_priority());
    stop_ = false;
    insert_at(root_, t, eq);
    while (stop_) {
      stop_ = false;
      eq = false;
      insert_at(root_, t, eq);
    }
    return !eq;
  }

  void insert_at (int pos, T x) {
    if (pos > size())
      return;
    pnode t = new node(x, next_priority());
    stop_ = false;
    insert(root_, t, pos);
    while (stop_) {
      stop_ = false;
      insert(root_, t, pos);
    }
    if (pos > 0 && is_sorted_) {
      if (!(get(root_, pos - 1) < get(root_, pos)))
        is_sorted_ = false;
    }
    if (pos < size() - 1 && is_sorted_) {
      if (!(get(root_, pos) < get(root_, pos + 1)))
        is_sorted_ = false;
    }
  }

  bool erase (T x) {
    if (!is_sorted_)
      return false;
    bool found = false;
    erase_at(root_, x, found);
    return found;
  }

  void erase_at (int pos) {
    if (pos >= size())
      return;
    erase(root_, pos);
  }

  void clear () {
    clear(root_);
  }

  int get_index (T key) {
    if (!is_sorted_)
      return size();
    pnode t = root_;
    int index = 0;
    while (t && t->key != key) {
      if (t->key > key)
        t = t->l;
      else {
        index += cnt(t->l) + 1;
        t = t->r;
      }
    }
    if (!t)
      return size();
    index += cnt(t->l);
    return index;
  }

  T operator[] (int index) {
    return get(root_, index);
  }

  std::pair <T, int> lower_bound (T x) {
    if (!is_sorted_)
      return {T(), size()};
    return lower_bound(root_, x, 0);
  }

  std::pair <T, int> upper_bound (T x) {
    if (!is_sorted_)
      return {T(), size()};
    return upper_bound(root_, x, 0);
  }

  void shift (int left, int right, T x) {
    left = std::max(left, 0);
    right = std::min(right, size() - 1);
    shift(root_, left, right, x);
    if (left > 0 && is_sorted_) {
      if (!(get(root_, left - 1) < get(root_, left)))
        is_sorted_ = false;
    }
    if (right < size() - 1 && is_sorted_) {
      if (!(get(root_, right) < get(root_, right + 1)))
        is_sorted_ = false;
    }
  }

  void reverse (int left, int right) {
    left = std::max(left, 0);
    right = std::min(right, size() - 1);
    reverse(root_, left, right);
    if (left != right)
      is_sorted_ = false;
  }

  void move (int left, int right, int shift) {
    move(root_, left, right, shift);
  }

  T get_sum (int left, int right) {
    return get_sum(root_, left, right);
  }

  pair<int,int> get_max_val_range() {
  	push(root_);
  	int max_val = root_->fmax.val;
  	return get_max_val_range(root_, max_val);
  }
};  // class treap

#endif  // _TREAP_H

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int N;
	cin >> N;
	vector<int> A(N);
	for(int i = 0; i < N; i++) cin >> A[i];
	A.insert(begin(A), 0);
	A.push_back(0);
	N += 2;
	cat ans = 0;
	itree I(N);
	for(int i = 0; i < N; i++) I.set(i, A[i]);
	vector<int> seq_init;
	treap<elem> T_seq;
	for(int i = 0; i < N; i++) {
		I.clear_saved();
		int mx_l = I.get_max(0, i);
		I.clear_saved();
		int mx_r = I.get_max(i+1, N);
		if(mx_l <= A[i] || mx_r <= A[i]) {
			seq_init.push_back(i);
			T_seq.insert({.val = A[i], .pos = i});
		}
	}
	for(auto pos : seq_init) I.set(pos, -1);
	while(true) {
		// int sz = T_seq.size();
		// cout << sz;
		// for(int i = 0; i < sz; i++) cout << " " << T_seq[i].val;
		// cout << endl;
		auto [l,r] = T_seq.get_max_val_range();
		int max_val = T_seq[l].val;
		if(max_val == 0) break;
		auto [val_l, pos_l] = T_seq[l-1];
		auto [val_r, pos_r] = T_seq[r+1];
		I.clear_saved();
		int val_max_add = I.get_max(pos_l, pos_r);
		if(val_l <= val_r) {
			int id_max_add = I.get_ge_l(pos_l, pos_r, val_l);
			int m = (val_max_add >= val_l) ? T_seq.lower_bound({.val = 0, .pos = id_max_add}).ss-1 : r;
			ans += m-l+1;
			T_seq.shift(l, m, {.val = val_l-max_val, .pos = 0});
			int border_l = T_seq[m].pos, border_r = T_seq[m+1].pos;
			while(true) {
				I.clear_saved();
				if(I.get_max(border_l, border_r) < val_l) break;
				int id_add = I.get_ge_l(border_l, border_r, val_l);
				T_seq.insert({.val = A[id_add], .pos = id_add});
				m++;
				I.set(id_add, -1);
				val_l = A[id_add], border_l = id_add;
			}
		}
		else {
			int id_max_add = I.get_ge_r(pos_l, pos_r, val_r);
			int m = (val_max_add >= val_r) ? T_seq.lower_bound({.val = 0, .pos = id_max_add}).ss : l;
			ans += r-m+1;
			T_seq.shift(m, r, {.val = val_r-max_val, .pos = 0});
			int border_l = T_seq[m-1].pos, border_r = T_seq[m].pos;
			while(true) {
				I.clear_saved();
				if(I.get_max(border_l, border_r) < val_r) break;
				int id_add = I.get_ge_r(border_l, border_r, val_r);
				T_seq.insert({.val = A[id_add], .pos = id_add});
				I.set(id_add, -1);
				val_r = A[id_add], border_r = id_add;
			}
		}
	}
	cout << ans << "\n";
}

// look at my code
// my code is amazing