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
#define OVER9000 1234567890
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

cat gcd(cat a, cat b) {
	if(a > b) swap(a, b);
	while(a) {
		cat c = b%a;
		b = a;
		a = c;
	}
	return b;
}

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

template <typename T>
class minfin {
	vector<T> node_val;
	T init_val_;

	int lastone(int x) { return x & (x ^ (x-1)); }

public:
	minfin(int N, T init_val) {
		init_val_ = init_val;
		node_val.resize(N+10, init_val);
	}

	void put(int pos, T val) {
		for(int i = pos+1; i < (int)node_val.size(); i += lastone(i))
			node_val[i] = min(node_val[i], val);
	}

	T get(int pos) {
		T ret = init_val_;
		for(int i = pos+1; i > 0; i -= lastone(i))
			ret = min(ret, node_val[i]);
		return ret;
	}
};

struct diag_group {
	int diag, id, sz, cur_dif;
};

struct itree_diag {
	int b;
	vector<int> min_dif, upd_dif, sz;

	itree_diag(int N) {
		b = 1;
		while(b < N) b *= 2;
		min_dif.resize(2*b, 0);
		upd_dif.resize(2*b, 0);
		sz.resize(2*b, 0);
	}

	void upd(int cur) {
		if(upd_dif[cur] == 0) return;
		min_dif[cur] += upd_dif[cur];
		if(cur >= b) {
			upd_dif[cur] = 0;
			return;
		}
		upd_dif[2*cur] += upd_dif[cur];
		upd_dif[2*cur+1] += upd_dif[cur];
		upd_dif[cur] = 0;
	}

	void dif_add(int I_l, int I_r, int val, int cur = 1, int l = 0, int r = 0) {
		if(r == 0) r = b;
		I_l = max(I_l, l);
		I_r = min(I_r, r);
		if(I_l >= I_r) {
			upd(cur);
			return;
		}
		if(I_l == l && I_r == r) {
			upd_dif[cur] += val;
			upd(cur);
			return;
		}
		upd(cur);
		int mid = (l+r)/2;
		dif_add(I_l, I_r, val, 2*cur, l, mid);
		dif_add(I_l, I_r, val, 2*cur+1, mid, r);
		if(sz[2*cur] <= 0) min_dif[cur] = min_dif[2*cur+1];
		else if(sz[2*cur+1] <= 0) min_dif[cur] = min_dif[2*cur];
		else min_dif[cur] = min(min_dif[2*cur], min_dif[2*cur+1]);
	}

	void sz_add(int pos, int val, int cur = 1, int l = 0, int r = 0) {
		if(r == 0) r = b;
		upd(cur);
		sz[cur] += val;
		if(l+1 == r) return;
		int mid = (l+r)/2;
		if(pos < mid) {
			sz_add(pos, val, 2*cur, l, mid);
			upd(2*cur+1);
		}
		else {
			sz_add(pos, val, 2*cur+1, mid, r);
			upd(2*cur);
		}
		if(sz[2*cur] <= 0) min_dif[cur] = min_dif[2*cur+1];
		else if(sz[2*cur+1] <= 0) min_dif[cur] = min_dif[2*cur];
		else min_dif[cur] = min(min_dif[2*cur], min_dif[2*cur+1]);
	}

	int sz_get(int pos, int cur = 1, int l = 0, int r = 0) {
		if(r == 0) r = b;
		if(l+1 == r) return sz[cur];
		int mid = (l+r)/2;
		if(pos < mid) return sz_get(pos, 2*cur, l, mid);
		else return sz_get(pos, 2*cur+1, mid, r);
	}

	pair<int,int> min_dif_get(int cur = 1, int l = 0, int r = 0) {
		if(r == 0) r = b;
		upd(cur);
		if(l+1 == r) return {min_dif[cur], l};
		int mid = (l+r)/2;
		upd(2*cur);
		if(min_dif[cur] == min_dif[2*cur] && sz[2*cur] > 0) return min_dif_get(2*cur, l, mid);
		upd(2*cur+1);
		return min_dif_get(2*cur+1, mid, r);
	}
};

struct itree_pts {
	int b;
	vector<int> min_gz, upd_gz;

	itree_pts(int N, auto & init) {
		b = 1;
		while(b < N) b *= 2;
		init.resize(b, OVER9000);
		min_gz.resize(2*b);
		upd_gz.resize(2*b, 0);
		build(1, 0, b, init);
	}

	void build(int cur, int l, int r, auto & init) {
		if(l+1 == r) {
			min_gz[cur] = init[l];
			return;
		}
		int mid = (l+r)/2;
		build(2*cur, l, mid, init);
		build(2*cur+1, mid, r, init);
		if(min_gz[2*cur] <= 0) min_gz[cur] = min_gz[2*cur+1];
		else if(min_gz[2*cur+1] <= 0) min_gz[cur] = min_gz[2*cur];
		else min_gz[cur] = min(min_gz[2*cur], min_gz[2*cur+1]);
	}

	void upd(int cur) {
		if(upd_gz[cur] == 0) return;
		min_gz[cur] += upd_gz[cur];
		if(cur >= b) {
			upd_gz[cur] = 0;
			return;
		}
		upd_gz[2*cur] += upd_gz[cur];
		upd_gz[2*cur+1] += upd_gz[cur];
		upd_gz[cur] = 0;
	}

	int get_min_gz(int I_l, int I_r, int cur = 1, int l = 0, int r = 0) {
		if(r == 0) r = b;
		I_l = max(I_l, l);
		I_r = min(I_r, r);
		upd(cur);
		if(I_l >= I_r) return 0;
		if(I_l == l && I_r == r) return min_gz[cur];
		int mid = (l+r)/2;
		int min_l = get_min_gz(I_l, I_r, 2*cur, l, mid);
		int min_r = get_min_gz(I_l, I_r, 2*cur+1, mid, r);
		if(min_l <= 0) return min_r;
		if(min_r <= 0) return min_l;
		return min(min_l, min_r);
	}

	void add_find_zero(int I_l, int I_r, int val, vector<int> & ids_zero, int cur = 1, int l = 0, int r = 0) {
		if(r == 0) r = b;
		I_l = max(I_l, l);
		I_r = min(I_r, r);
		upd(cur);
		if(I_l >= I_r || min_gz[cur] <= 0) return;
		if(I_l == l && I_r == r && min_gz[cur]+val > 0) {
			upd_gz[cur] += val;
			upd(cur);
			return;
		}
		if(l+1 == r) {
			min_gz[cur] += val;
			if(min_gz[cur] == 0) ids_zero.push_back(l);
			return;
		}
		int mid = (l+r)/2;
		add_find_zero(I_l, I_r, val, ids_zero, 2*cur, l, mid);
		add_find_zero(I_l, I_r, val, ids_zero, 2*cur+1, mid, r);
		if(min_gz[2*cur] <= 0) min_gz[cur] = min_gz[2*cur+1];
		else if(min_gz[2*cur+1] <= 0) min_gz[cur] = min_gz[2*cur];
		else min_gz[cur] = min(min_gz[2*cur], min_gz[2*cur+1]);
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int N, M;
	cin >> N;
	M = 2000000000;
	vector<int> Ax(N, 0), Ay(N, 0);
	for(int i = 0; i < N; i++) cin >> Ax[i] >> Ay[i];
	vector< pair<int,int> > As(N);
	for(int i = 0; i < N; i++) As[i] = {Ax[i]+Ay[i], i};
	sort(begin(As), end(As));
	As.push_back({M, N});

	vector<int> diags;
	for(int i = 0; i <= N; i++) if(i == 0 || As[i].ff != As[i-1].ff) {
		diags.push_back(As[i].ff);
		int j = i;
		while(j <= N && diags.back() == As[j].ff) {
			As[j].ff = (int)diags.size()-1;
			j++;
		}
		i = j-1;
	}
	As.pop_back();

	itree_diag I_diag(diags.size());
	int last_diag = 0;
	for(int i = 0; i < (int)diags.size(); i++) {
		I_diag.sz_add(i, diags[i]-last_diag);
		last_diag = diags[i];
	}

	for(int i = 0; i < N; i++) I_diag.dif_add(0,As[i].ff+1,-1);
	vector<int> Axs(N);
	for(int i = 0; i < N; i++) Axs[i] = Ax[As[i].ss];
	for(int i = 0; i < N; i++) if(Axs[i] == 0) I_diag.dif_add(0,As[i].ff+1,2);
	itree_pts I_pts(N, Axs);

	cat cost = 0;
	for(int i = 0; i < N; i++) cost += Ax[i];
	cat ans = cost;

	int used = 0;
	while(used < M) {
		auto [best_val, best_id] = I_diag.min_dif_get();
		int l = lower_bound(begin(As), end(As), make_pair(best_id, 0)) - begin(As);
		int use = I_pts.get_min_gz(l,N);
		if(use <= 0) use = OVER9000;
		use = min(I_diag.sz_get(best_id), use);
		vector<int> upd;
		I_pts.add_find_zero(l,N,-use,upd);
		for(auto id : upd) I_diag.dif_add(0, As[id].ff+1, 2);
		cost += 1LL * best_val * use;
		ans = min(ans, cost);
		I_diag.sz_add(best_id,-use);
		used += use;
	}
	cout << ans << "\n";
}

// look at my code
// my code is amazing