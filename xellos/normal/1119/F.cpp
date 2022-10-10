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
// #define abs(x) (((x) < 0)?-(x):(x))
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

#include <unistd.h>
#include <random>
#include <chrono>

template <typename T> 
class treap {
 private:
  struct item;
  using pitem = struct item *;
  
  static std::mt19937_64 rng;
  bool is_sorted_;
  bool stop_;
  pitem root_;

  using priority_t = std::mt19937_64::result_type;

  priority_t next_priority() {
    priority_t priority = rng();
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
    for (int i =0; i < sz; i++) new_priors[i] = next_priority();
    std::sort(new_priors.begin(), new_priors.end());
    for (int i =0; i < sz; i++) new_priors[i] += i;
    regenerate_priorities_recursive(new_priors, root_, 0, sz);
  }

  struct item {
    priority_t priority;
    T key, fsum;
    pitem l, r;
    int cnt;

    item(T x, priority_t p) {
      key = x, fsum = x>>20;
      cnt = 1;
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
      it->fsum = it->key>>20;
      if (it->l) it->fsum += it->l->fsum;
      if (it->r) it->fsum += it->r->fsum;
    }
  }

  void update(pitem t, T add, int /*rev*/) {
    if (!t) return;
    t->key = t->key + add;
    t->fsum = t->fsum + cnt(t) * add;
  }

  void push(pitem t) {
    return;
    update(t->l, 0, 0);
    update(t->r, 0, 0);
    if (0) swap(t->l, t->r);
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
      eq =true;
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
      eq =true; 
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
	  delete t;
      merge(t, t->l, t->r);
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
      delete t;
      merge(t, t->l, t->r);
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
      std::pair<T, int> ret = upper_bound(t->l, key, index);
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

 public:
  treap() : is_sorted_(true), stop_(false), root_(nullptr) {}

  int size() {return cnt(root_);}
  bool empty() {return (cnt(root_) == 0);}
  bool is_sorted() {return is_sorted_;}

  void srand(std::mt19937_64::result_type seed) {
    // optional
    rng.seed(seed);
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

struct edge {
	int u, v;
	cat cost;
};

void DFS(int R, int par, auto & G_cur, auto & free_e, auto & vis, auto & vis_list, auto & dp, int D) {
	vis[R] = 1;
	vis_list.push_back(R);
	dp[R] = {-1, -1};
	int rm = free_e[R].size() - D;
	cat s0 = 0;
	vector<cat> rm_cand;
	for(auto & p : G_cur[R]) if(par != p.ff) {
		DFS(p.ff, R, G_cur, free_e, vis, vis_list, dp, D);
		rm++;
		s0 += dp[p.ff].ss;
		rm_cand.push_back(p.ss + dp[p.ff].ff - dp[p.ff].ss);
	}
	sort(begin(rm_cand), end(rm_cand));
	cat s = 0;
	for(int i = 0; i <= (int)rm_cand.size(); i++) {
		if(rm-i-1 < free_e[R].size()) {
			cat cur_cost = s0 + s + ((rm <= i) ? 0 : free_e[R].get_sum(0, rm-i-1));
			dp[R].ff = (dp[R].ff == -1) ? cur_cost : min(dp[R].ff, cur_cost);
		}
		if(rm-i < free_e[R].size()) {
			cat cur_cost = s0 + s + ((rm < i) ? 0 : free_e[R].get_sum(0, rm-i));
			dp[R].ss = (dp[R].ss == -1) ? cur_cost : min(dp[R].ss, cur_cost);
		}
		if(i < (int)rm_cand.size()) s += rm_cand[i];
	}
}

template <typename T>
std::mt19937_64 treap<T>::rng = std::mt19937_64(std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cin >> N;
	vector< pair<int, int> > D(N);
	for(int i = 0; i < N; i++) D[i] = {0, i};
	vector<edge> E(N-1);
	vector< vector<int> > G(N);
	for(int i = 0; i < N-1; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		E[i] = {--u, --v, w};
		G[u].push_back(i);
		G[v].push_back(i);
		D[u].ff++, D[v].ff++;
	}
	sort(begin(D), end(D));
	vector< vector< pair<int, cat> > > G_cur(N);
	vector< treap<cat> > free_e(N);
	for(int i = 0; i < N-1; i++) {
		free_e[E[i].u].insert((E[i].cost<<20)+i);
		free_e[E[i].v].insert((E[i].cost<<20)+i);
	}
	vector<int> roots, vis_list, vis(N, 0);
	vector< pair<cat, cat> > dp(N);
	vector<cat> ans(N, 0);
	int a = N-1;
	for(int d = N-1; d > 0; d--) {
		while(a >= 0 && d < D[a].first) {
			int v = D[a].second;
			for(auto id : G[D[a].second]) {
				int u = E[id].u+E[id].v-v;
				if((int)G[u].size() <= d) continue;
				free_e[v].erase((E[id].cost<<20)+id);
				G_cur[v].push_back({u, E[id].cost});
				if((int)G[u].size() > d+1) {
					free_e[u].erase((E[id].cost<<20)+id);
					G_cur[u].push_back({v, E[id].cost});
				}
			}
			roots.push_back(v);
			a--;
		}
		vector<int> roots_old = roots;
		roots.clear();
		for(auto r : roots_old) {
			if(vis[r]) continue;
			roots.push_back(r);
			DFS(r, r, G_cur, free_e, vis, vis_list, dp, d);
			ans[d] += dp[r].ff;
		}
		for(auto v : vis_list) vis[v] = false;
		vis_list.clear();
	}
	for(int i = 0; i < N-1; i++) ans[0] += E[i].cost;
	for(int i = 0; i < N; i++) cout << ans[i] << ((i == N-1) ? "\n" : " ");
	return 0;
}

// look at my code
// my code is amazing