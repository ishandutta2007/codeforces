// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
#include <time.h>
#include <random>
#include <chrono>
#define dibs reserve
#define OVER9000 1234567890
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-8
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) (((x) < 0)?-(x):(x))
#define uint unsigned int
#define dbl long double
#define pi 3.14159265358979323846
using namespace std;
// mylittledoge

using cat = long long;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

template <typename T> 
class treap {
 private:
  struct item;
  using pitem = struct item *;
  
  std::mt19937_64 * rng_;
  bool rng_owner_;
  bool is_sorted_;
  bool stop_; // for priority regeneration
  pitem root_;

  using priority_t = std::mt19937_64::result_type;

  priority_t next_priority() {
    priority_t priority = (*rng_)();
    return priority;
  }

  void regenerate_priorities_recursive(std::vector<int> & new_priors, pitem & t, int l, int r) {
    if (!t) return;
    t->priority = new_priors[r-1];
    regenerate_priorities_recursive(new_priors, t->l, l, l+cnt(t->l));
    regenerate_priorities_recursive(new_priors, t->r, l+cnt(t->l), r-1);
  }

  void regenerate_priorities() {
    int sz = size();
    std::vector<int> new_priors(sz);
    for (int i = 0; i < sz; i++) new_priors[i] = next_priority();
    std::sort(new_priors.begin(), new_priors.end());
    for (int i = 0; i < sz; i++) new_priors[i] += i;
    regenerate_priorities_recursive(new_priors, root_, 0, sz);
  }

  struct item {
    priority_t priority;
    int cnt, rev;
    T key, add, fsum;
    pitem l, r;

    item(T x, priority_t p) {
      add = 0 * x;
      key = fsum = x;
      cnt = 1;
      rev = 0;
      l = r = nullptr; 
      priority = p;
    }
  };

  int cnt(pitem it) {
    return it ? it->cnt : 0;
  }

  void upd_cnt(pitem it) {
    if (it)
      it->cnt = cnt(it->l) + cnt(it->r) + 1;
  }

  void upd_sum(pitem it) {
    if (it) {
      it->fsum = it->key;
      if (it->l) it->fsum += it->l->fsum;
      if (it->r) it->fsum += it->r->fsum;
    }
  }

  void update(pitem t, T add, int rev) {
    if (!t) return;
    t->add = t->add + add;
    t->rev = t->rev ^ rev;
    t->key = t->key + add;
    t->fsum = t->fsum + cnt(t) * add;
  }

  void push(pitem t) {
    if (!t || (t->add == 0 * T() && t->rev == 0)) return;
    update(t->l, t->add, t->rev);
    update(t->r, t->add, t->rev);
    if (t->rev) swap(t->l, t->r);
    t->add = 0 * T();
    t->rev = 0;
  }

  void merge(pitem & t, pitem l, pitem r) {
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

  void split(pitem t, pitem & l, pitem & r, int index) { // split at position
    if (!t)
      return void( l = r = 0 );
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

  void split_at(pitem t, pitem & l, pitem & r, T & key, bool & eq) { // split by key
    if (!t)
      return void( l = r = 0 );
    push(t);
    if (key == t->key) {
      eq = true;
      return;
    }
    if (key < t->key) {
      split_at(t->l, l, t->l, key, eq);
      if (!eq) r = t;
    }
    else {
      split_at(t->r, t->r, r, key, eq);
      if (!eq) l = t;
    }
    if (!eq) upd_cnt(t);
    upd_sum(t);
  }

  void insert(pitem & t, pitem it, int index) { // insert at position
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
      insert(t->r, it, index - cnt(t->l) - 1 );
    if (stop_) return;
    upd_cnt(t);
    upd_sum(t);
  }

  void insert_at(pitem & t, pitem it, bool & eq) { // insert by key
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
      if (!eq) t = it;
    }
    else if (it->key < t->key)
      insert_at(t->l, it, eq);
    else
      insert_at(t->r, it, eq);
    if (stop_) return;
    if (!eq) upd_cnt(t);
    upd_sum(t);
  }

  void erase(pitem & t, int index) {
    push(t);
    if (cnt(t->l) == index) {
      pitem l = t->l, r = t->r;
      delete t;
      t = nullptr;
      merge(t, l, r);
    }
    else if (index < cnt(t->l))
      erase(t->l, index);
    else
      erase(t->r, index - cnt(t->l) - 1 );
    upd_cnt(t);
    upd_sum(t);
  }

  void erase_at(pitem & t, T key, bool & found) {
    push(t);
    if (key == t->key) {
      pitem l = t->l, r = t->r;
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

  T get(pitem t, int index) {
    push(t);
    if (index < cnt(t->l))
      return get(t->l, index);
    else if (index > cnt(t->l))
      return get(t->r, index - cnt(t->l) - 1);
    return t->key;
  }

  int find(pitem t, T key) {
    push(t);
    if (!t || key == t->key)
      return cnt(t->l);
    if (key < t->key)
      return get(t->l, key);
    else 
      return get(t->r, key) + 1 + cnt(t->l);
  }

  std::pair<T, int> lower_bound(pitem t, T key, int index) {
    push(t);
    if (!t)
      return {T(), size()};
    if (key == t->key) 
      return {key, index + cnt(t->l)};
    if (key < t->key) {
      std::pair<T, int> ret = lower_bound(t->l, key, index);
      if (ret.second == size()) ret = {t->key, index + cnt(t->l)};
      return ret;
    }
    return lower_bound(t->r, key, index + 1 + cnt(t->l));
  }

  std::pair<T, int> upper_bound(pitem t, T key, int index) {
    push(t);
    if (!t)
      return {T(), size()};
    if (key < t->key) {
      std::pair <T, int> ret = upper_bound(t->l, key, index);
      if (ret.second == size()) ret = {t->key, index + cnt(t->l)};
      return ret;
    }
    return upper_bound(t->r, key, index + 1 + cnt(t->l));
  }

  void shift(pitem &t, int l, int r, T add) {
    pitem l1, r1;
    split(t, l1, r1, r + 1);
    pitem l2, r2;
    split(l1, l2, r2, l);
    update(r2, add, 0);
    pitem t2;
    merge(t2, l2, r2);
    merge(t, t2, r1);
  }

  void reverse(pitem &t, int l, int r) {
    pitem l1, r1;
    split(t, l1, r1, r + 1);
    pitem l2, r2;
    split(l1, l2, r2, l);
    update(r2, 0 * T(), 1);
    pitem t2;
    merge(t2, l2, r2);
    merge(t, t2, r1);
  }

  void move(pitem &t, int left, int right, int shift) {
    // [l, r) becomes [l+shift, r+shift)
    if(shift == 0) return;
    int l = left + std::min(0, shift);
    int r = right + std::max(0, shift);
    int m = (shift > 0) ? right : left;
    pitem prefix, tmp;
    split(root_, prefix, tmp, l);
    pitem suffix, middle;
    split(tmp, middle, suffix, r-l);
    pitem mid_prefix, mid_suffix;
    split(middle, mid_prefix, mid_suffix, m-l);
    merge(middle, mid_suffix, mid_prefix);
    merge(tmp, middle, suffix);
    merge(root_, prefix, tmp);
  }

  T get_sum(pitem &t, int l, int r) {
    pitem l1, r1;
    split(t, l1, r1, r + 1);
    pitem l2, r2;
    split(l1, l2, r2, l);
    T ret = r2->fsum;
    pitem t2;
    merge(t2, l2, r2);
    merge(t, t2, r1);
    return ret;
  }

  void clear(pitem &t) {
    if (!t)
      return;
    clear(t->l);
    clear(t->r);
    delete t;
    t = nullptr;
  }

 public:
  treap(std::mt19937_64 * rng = nullptr) {
    is_sorted_ = true;
    stop_ = false;
    root_ = nullptr;
    if (rng) {
      rng_owner_ = false;
      rng = rng_;
    }
    else {
      rng_owner_ = true;
      rng_ = new std::mt19937_64;
      rng_->seed(std::chrono::steady_clock::now().time_since_epoch().count());
    }
  }

  ~treap() {
    if (rng_owner_)
      delete rng_;
    clear(root_);
  }

  int size() {return cnt(root_);}
  bool empty() {return (cnt(root_) == 0);}
  bool is_sorted() {return is_sorted_;}

  void srand(std::mt19937_64::result_type seed) {
    // optional
    rng_->seed(seed);
  }

  bool insert(T x) {
    if (!is_sorted_) return false;
    bool eq = false;
    pitem it = new item(x, next_priority());
    stop_ = false;
    insert_at(root_, it, eq);
    while (stop_) {
      stop_ = false;
      eq = false;
      insert_at(root_, it, eq);
    }
    return !eq;
  }

  void insert_at(int pos, T x) {
    if (pos > size()) return;
    pitem it = new item(x, next_priority());
    stop_ = false;
    insert(root_, it, pos);
    while (stop_) {
      stop_ = false;
      insert(root_, it, pos);
    }
    if (pos > 0 && is_sorted_) {
      if (get(root_, pos-1) >= get(root_, pos)) is_sorted_ = false;
    }
    if (pos < size()-1 && is_sorted_) {
      if (get(root_, pos) >= get(root_, pos+1)) is_sorted_ = false;
    }
  }

  bool erase(T x) {
    if (!is_sorted_) return false;
    bool found = false;
    erase_at(root_, x, found);
    return found;
  }

  void erase_at(int pos) {
    if (pos >= size()) return;
    erase(root_, pos);
  }

  void clear() {
    clear(root_);
  }

  int get_index(T key) {
    if (!is_sorted_) return size();
    pitem t = root_;
    int index = 0;
    while (t && t->key != key) {
      if (t->key > key)
        t = t->l;
      else {
        index += cnt(t->l) + 1;
        t = t->r;
      }
    }
    if (!t) return size();
    index += cnt(t->l);
    return index;
  }

  T operator[](int index) {
    return get(root_, index);
  }

  std::pair<T, int> lower_bound(T x) {
    if (!is_sorted_) return {T(), size()};
    return lower_bound(root_, x, 0);
  }

  std::pair<T, int> upper_bound(T x) {
    if (!is_sorted_) return {T(), size()};
    return upper_bound(root_, x, 0);
  }

  void shift(int left, int right, T x) {
    left = std::max(left, 0);
    right = std::min(right, size()-1);
    if(left > right) return;
    shift(root_, left, right, x);
    if (left > 0 && is_sorted_) {
      if (get(root_, left-1) >= get(root_, left)) is_sorted_ = false;
    }
    if (right < size()-1 && is_sorted_) {
      if (get(root_, right) >= get(root_, right+1)) is_sorted_ = false;
    }
  }

  void reverse(int left, int right) {
    left = std::max(left, 0);
    right = std::min(right, size()-1);
    reverse(root_, left, right);
    if (left != right) is_sorted_ = false;
  }

  void move(int left, int right, int shift) {
  	move(root_, left, right, shift);
  }

  T get_sum(int left, int right) {
    return get_sum(root_, left, right);
  }
}; // class treap


int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int T;
	cin >> T;
	treap<int> Tr[26];
	while(T--) {
		string S;
		cin >> S;
		int N = S.length();
		for(int k = 0; k < 26; k++) Tr[k].clear();
		for(int i = 0; i < N-1; i++) if(S[i] == S[i+1]) Tr[S[i]-'a'].insert(i);
		vector< pair<int, int> > ans;
		while(true) {
			int adj_nonz = 0, adj_max = -1, adj_max_id = -1;
			for(int k = 0; k < 26; k++) {
				if(!Tr[k].empty()) adj_nonz++;
				if(Tr[k].size() > adj_max) {
					adj_max = Tr[k].size();
					adj_max_id = k;
				}
			}
			if(adj_nonz == 0) break;
			if(adj_nonz == 1) {
				for(int i = Tr[adj_max_id].size()-1; i >= 0; i--) {
					int pos = Tr[adj_max_id][i];
					ans.push_back({pos, pos});
					N--;
				}
				break;
			}
			int other_id = -1, other_next = N+1, other_prev = -1;
			int l = Tr[adj_max_id][0];
			for(int k = 0; k < 26; k++) if(k != adj_max_id) {
				if(Tr[k].empty()) continue;
				auto [other_pos, id] = Tr[k].lower_bound(l);
				if(id != Tr[k].size()) {
					if(other_pos < other_next) {
						other_id = k;
						other_next = other_pos;
					}
					continue;
				}
				other_pos = Tr[k][id-1];
				if(other_prev < other_pos && other_next == N+1) {
					other_id = k;
					other_prev = other_pos;
				}
			}
			int r = other_next;
			if(other_next == N+1) {
				swap(l, r);
				l = other_prev;
				r = Tr[adj_max_id].lower_bound(l).first;
				swap(other_id, adj_max_id);
			}
			else {
				auto [max_pos, id] = Tr[adj_max_id].lower_bound(r);
				l = Tr[adj_max_id][id-1];
			}
			ans.push_back({l+1, r});
			N -= (r-l);
			Tr[adj_max_id].erase(l);
			Tr[other_id].erase(r);
			for(int k = 0; k < 26; k++) {
				auto [pos, id] = Tr[k].lower_bound(l);
				Tr[k].shift(id, Tr[k].size(), -(r-l));
			}
		}
		ans.push_back({0, N-1});
		cout << ans.size() << "\n";
		for(auto [a, b] : ans) cout << a+1 << " " << b+1 << "\n";
	}
	return 0;
}

// look at my code
// my code is amazing