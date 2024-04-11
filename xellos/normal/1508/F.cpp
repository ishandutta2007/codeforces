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

struct query {
	short l, r;
	int id;
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int N, Q;
	cin >> N >> Q;
	vector<short> A(N), pos(N), L(Q), R(Q);
	// for(int i = 0; i < N; i++) {
	// 	A[i] = i+1;
	// 	swap(A[i], A[rand()%(i+1)]);
	// }
	for(int i = 0; i < N; i++) {
		cin >> A[i];
		A[i]--;
		pos[A[i]] = i;
	}
	for(int i = 0; i < Q; i++) {
		// R[i] = rand()%N+1;
		// L[i] = rand()%R[i]+1;
		cin >> L[i] >> R[i];
		L[i]--, R[i]--;
	}
	vector<cat> ans(Q+1, 0);
	vector<query> q_by_l, q_by_r;
	{
		vector< vector<query> > tmp(N);
		for(int i = 0; i < Q; i++) tmp[L[i]].push_back({.l = L[i], .r = R[i], .id = i});
		for(int i = 0; i < N; i++) for(auto q : tmp[i]) q_by_l.push_back(q);
	}
	{
		vector< vector<query> > tmp(N);
		for(int i = 0; i < Q; i++) tmp[R[i]].push_back({.l = L[i], .r = R[i], .id = i});
		for(int i = N-1; i >= 0; i--) for(auto q : tmp[i]) q_by_r.push_back(q);
	}
	vector<int> fin_by_l(N), fin_by_r(N);
	for(int i = 0; i < N; i++) {
		fin_by_l[i] = i ? fin_by_l[i-1] : 0;
		while(fin_by_l[i] < Q && q_by_l[fin_by_l[i]].l <= i) fin_by_l[i]++;
	}
	for(int i = N-1; i >= 0; i--) {
		fin_by_r[i] = (i < N-1) ? fin_by_r[i+1] : 0;
		while(fin_by_r[i] < Q && q_by_r[fin_by_r[i]].r >= i) fin_by_r[i]++;
	}
	vector< set<int> > set_l_id(N);
	vector<int> min_l_id(N, Q), min_r_id(N, Q);
	for(int i = 0; i < N; i++) set_l_id[i].insert(Q);
	int pl0 = 0, pr0 = Q-1;
	for(int i = 0; i < N; i++) {
		while(pl0 < Q && q_by_l[pl0].l == i) {
			min_r_id[q_by_l[pl0].r] = min(min_r_id[q_by_l[pl0].r], q_by_l[pl0].id);
			set_l_id[i].insert(q_by_l[pl0].id);
			min_l_id[i] = *begin(set_l_id[i]);
			pl0++;
		}
		while(pr0 >= 0 && q_by_r[pr0].r == i-1) {
			set_l_id[q_by_r[pr0].l].erase(q_by_r[pr0].id);
			min_l_id[q_by_r[pr0].l] = *begin(set_l_id[q_by_r[pr0].l]);
			pr0--;
		}
		int l = -1, r = N, st_l = Q, st_r = Q, min_lr_id = Q;
		const query * pr = &(q_by_r[0]);
		const query * pl = &(q_by_l[0]);
		for(int j = A[i]-1; j >= 0; j--) {
			if(pos[j] > i && r > pos[j]) {
				int fin = st_r;
				while(r > pos[j]) {
					r--;
					st_r = min(st_r, min_r_id[r]);
				}
				const query * const pr_f = &(q_by_r[0]) + fin_by_r[r];
				while(pr != pr_f) {
					if(pr->l <= l && pr->id < min_lr_id) min_lr_id = pr->id;
					pr++;
				}
				fin = min(fin, min_lr_id);
				ans[st_r]++, ans[fin]--;
			}
			if(pos[j] < i && l < pos[j]) {
				int fin = st_l;
				while(l < pos[j]) {
					l++;
					st_l = min(st_l, min_l_id[l]);
				}
				const query * const pl_f = &(q_by_l[0]) + fin_by_l[l];
				while(pl != pl_f) {
					if(pl->r >= r && pl->id < min_lr_id) min_lr_id = pl->id;
					pl++;
				}
				fin = min(fin, min_lr_id);
				ans[st_l]++, ans[fin]--;
			}
		}
	}
	for(int i = 0; i < Q; i++) ans[i+1] += ans[i];
	for(int i = 0; i < Q; i++) cout << ans[i] << "\n";
}

// look at my code
// my code is amazing