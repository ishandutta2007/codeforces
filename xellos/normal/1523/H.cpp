#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
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
#define OVER9000 1234567890LL
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

constexpr int K = 31, E = 15;

struct Info {
	short r[K+1];
};

void inplace_max(Info & out, Info & in) {
	for(int k = 0; k <= K; k++) out.r[k] = max(out.r[k], in.r[k]);
}

template <typename T>
class fin {
	T init_val;
	vector<T> node_val;

	int lastone(int x) { return x & (x ^ (x-1)); }

public:
	fin() {}

	fin(int N, T init_val_) : init_val{init_val_} {
		node_val.resize(N+10, init_val_);
	}

	void put(int pos, T val) {
		for(int i = pos+1; i < (int)node_val.size(); i += lastone(i))
			inplace_max(node_val[i], val);
	}

	T get(int pos) {
		T ret = init_val;
		for(int i = pos+1; i > 0; i -= lastone(i))
			inplace_max(ret, node_val[i]);
		return ret;
	}
};

struct Query {
	int l, r, k, id;
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int N, Q;
	cin >> N >> Q;
	vector<int> A(N);
	for(int i = 0; i < N; i++) cin >> A[i];
	vector<int> ans(Q);
	vector< vector<Query> > q_by_l(N);
	for(int q = 0; q < Q; q++) {
		int l, r, k;
		cin >> l >> r >> k;
		l--, r--;
		q_by_l[l].push_back({.l = l, .r = r, .k = k, .id = q});
	}
	fin<Info> R[E];
	Info init;
	for(int k = 0; k <= K; k++) init.r[k] = 0;
	for(int i = 0; i < E; i++) R[i] = fin(N, init);
	for(int l = N-1; l >= 0; l--) {
		Info cur_info;
		for(int k = 0; k <= K; k++) {
			cur_info.r[k] = min(N-1, l+A[l]+k);
		}
		R[0].put(l, cur_info);
		for(int i = 1; i < E; i++) {
			Info nxt_info = init;
			for(int k1 = 0; k1 <= K; k1++) {
				Info tmp = R[i-1].get(cur_info.r[k1]);
				for(int k2 = 0; k2 <= K-k1; k2++)
					nxt_info.r[k1+k2] = max(nxt_info.r[k1+k2], tmp.r[k2]);
			}
			R[i].put(l, nxt_info);
			cur_info = nxt_info;
		}
		for(auto q : q_by_l[l]) {
			if(q.l == q.r) {
				ans[q.id] = 0;
				continue;
			}
			int ans_lt = 0, ans_ge = N+1;
			Info R_lt;
			for(int k = 0; k <= K; k++) R_lt.r[k] = l;
			while(ans_ge-ans_lt > 1) {
				int steps = 1, steps_e = 0;
				for(int i = 0; i < E; i++)
					if(max(1<<i, ans_ge-ans_lt-(1<<i)) <= max(steps, ans_ge-ans_lt-steps))
						steps = 1<<i, steps_e = i;
				Info R_cur;
				for(int k = 0; k <= K; k++) R_cur.r[k] = l;
				for(int k1 = 0; k1 <= K; k1++) {
					Info tmp = R[steps_e].get(R_lt.r[k1]);
					for(int k2 = 0; k2 <= K-k1; k2++)
						R_cur.r[k1+k2] = max(R_cur.r[k1+k2], tmp.r[k2]);
				}
				if(R_cur.r[q.k] >= q.r) ans_ge = ans_lt+steps;
				else {
					ans_lt = ans_lt+steps;
					R_lt = R_cur;
				}
			}
			ans[q.id] = ans_ge;
		}
	}
	for(int q = 0; q < Q; q++) cout << ans[q] << "\n";
}

// look at my code
// my code is amazing