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

cat pw(cat a, cat e, cat mod) {
	if(e <= 0) return 1;
	cat x = pw(a, e/2, mod);
	x = x * x % mod;
	return (e&1) ? x * a % mod : x;
}

struct query {
	int u, v, l, r, res, id;
	// check if there's a different bit in B[u][l..r] and B[v][l..r] (if res=1) or equal bit (if res=0)
};

void DFS_init(int R, auto & G, auto & par, auto & dep, auto & v_seq) {
	v_seq.push_back(R);
	for(auto v : G[R]) if(par[v] == -1) {
		par[v] = R;
		dep[v] = dep[R]+1;
		DFS_init(v, G, par, dep, v_seq);
	}
}

constexpr cat mod0 = 1000000007;
constexpr cat mod1 = 1000000009;
constexpr cat p = 999983;
vector<cat> pw0, pw1;
vector<cat> pw_inv0, pw_inv1;

struct info {
	int id, l, r;
	cat out;
};

struct fin {
	vector< pair<cat, cat> > node_val;

	int lastone(int x) { return x & (x ^ (x-1)); }

public:
	fin() {}
	fin(int N) {
		node_val.resize(N+10, {0, 0});
	}

	void put(int pos, int val) {
		cat val0 = val * pw0[pos];
		if(val0 < 0) val0 += mod0;
		cat val1 = val * pw1[pos];
		if(val1 < 0) val1 += mod1;
		for(int i = pos+1; i < (int)node_val.size(); i += lastone(i)) {
			node_val[i].ff += val0;
			if(node_val[i].ff >= mod0) node_val[i].ff -= mod0;
			node_val[i].ss += val1;
			if(node_val[i].ss >= mod1) node_val[i].ss -= mod1;
		}
	}

	pair<cat, cat> get(int pos) {
		pair<cat, cat> ret = {0, 0};
		for(int i = pos+1; i > 0; i -= lastone(i)) {
			ret.ff += node_val[i].ff;
			ret.ss += node_val[i].ss;
		}
		ret.ff %= mod0;
		ret.ss %= mod1;
		return ret;
	}
};

vector<char> val_cur;
fin I;

void DFS(int R, int par, auto & G, auto & A, auto & occ) {
	if(val_cur[A[R]]) I.put(A[R], -1);
	else I.put(A[R], 1);
	val_cur[A[R]] ^= 1;
	for(auto & f : occ[R]) {
		pair<cat, cat> out_r = I.get(f.r);
		pair<cat, cat> out_l = I.get(f.l-1);
		pair<cat, cat> out = {(out_r.ff-out_l.ff) * pw_inv0[f.l] % mod0, (out_r.ss-out_l.ss) * pw_inv1[f.l] % mod1};
		if(out.ff < 0) out.ff += mod0;
		if(out.ss < 0) out.ss += mod1;
		f.out = out.ff * mod1 + out.ss;
	}
	for(auto v : G[R]) if(v != par) {
		DFS(v, R, G, A, occ);
	}
	if(val_cur[A[R]]) I.put(A[R], -1);
	else I.put(A[R], 1);
	val_cur[A[R]] ^= 1;
}

vector<char> eval_qs(vector<query> & qs, auto & A, auto & G) {
	int S = qs.size(), N = G.size();
	static vector< vector<info> > occ(N);
	for(int i = 0; i < N; i++) occ[i].clear();
	for(int i = 0; i < S; i++) {
		info i0{2*i, qs[i].l, qs[i].r, 0};
		occ[qs[i].u].push_back(i0);
		info i1{2*i+1, qs[i].l, qs[i].r, 0};
		occ[qs[i].v].push_back(i1);
	}
	DFS(0, 0, G, A, occ);
	vector<cat> val(2*S);
	for(int i = 0; i < N; i++) for(auto & f : occ[i]) val[f.id] = f.out;
	vector<char> ret(S, 0);
	for(int i = 0; i < S; i++) ret[i] = (val[2*i] == val[2*i+1]) ^ qs[i].res;
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int N, Q;
	cin >> N >> Q;
	vector<int> A(N);
	for(int i = 0; i < N; i++) {
		cin >> A[i];
		A[i]--;
	}
	vector< vector<int> > G(N);
	for(int i = 0; i < N-1; i++) {
		int u, v;
		cin >> u >> v;
		G[--u].push_back(--v);
		G[v].push_back(u);
	}
	vector<int> par[20];
	par[0].resize(N, -1);
	par[0][0] = 0;
	vector<int> dep(N, 0), v_seq;
	DFS_init(0, G, par[0], dep, v_seq);
	for(int k = 1; k < 19; k++) {
		par[k].resize(N, -1);
		for(int i = 0; i < N; i++) par[k][i] = par[k-1][par[k-1][i]];
	}

	vector<int> v_id(N);
	for(int i = 0; i < N; i++) v_id[v_seq[i]] = i;
	vector<int> A_tmp(N);
	for(int i = 0; i < N; i++) A_tmp[v_id[i]] = A[i];
	vector< vector<int> > G_tmp(N);
	for(int i = 0; i < N; i++)
		for(auto v : G[i]) G_tmp[v_id[i]].push_back(v_id[v]);

	vector<query> qs;
	vector<int> ans(Q, -1);
	for(int i = 0; i < Q; i++) {
		int u, v, l, r;
		cin >> u >> v >> l >> r;
		u--, v--, l--, r--;
		int lu = u, lv = v;
		if(dep[lu] > dep[lv]) {
			int d = dep[lu]-dep[lv];
			for(int j = 0; j < 19; j++) if((d>>j)&1) lu = par[j][lu];
		}
		if(dep[lu] < dep[lv]) {
			int d = dep[lv]-dep[lu];
			for(int j = 0; j < 19; j++) if((d>>j)&1) lv = par[j][lv];
		}
		if(lu != lv) {
			for(int j = 18; j >= 0; j--) if(par[j][lu] != par[j][lv]) {
				lu = par[j][lu];
				lv = par[j][lv];
			}
			lu = par[0][lu];
		}
		if(l <= A[lu] && A[lu] <= r) {
			qs.push_back({v_id[u], v_id[v], l, A[lu]-1, 1, i});
			qs.push_back({v_id[u], v_id[v], A[lu], A[lu], 0, i});
			qs.push_back({v_id[u], v_id[v], A[lu]+1, r, 1, i});
		}
		else qs.push_back({v_id[u], v_id[v], l, r, 1, i});
	}

	A = A_tmp;
	G = G_tmp;

	val_cur.resize(N, 0);
	I = fin(N);
	pw0.resize(N+1, 1);
	for(int i = 1; i <= N; i++) pw0[i] = pw0[i-1] * p % mod0;
	pw1.resize(N+1, 1);
	for(int i = 1; i <= N; i++) pw1[i] = pw1[i-1] * p % mod1;
	cat p_inv0 = pw(p, mod0-2, mod0);
	pw_inv0.resize(N+1, 1);
	for(int i = 1; i <= N; i++) pw_inv0[i] = pw_inv0[i-1] * p_inv0 % mod0;
	cat p_inv1 = pw(p, mod1-2, mod1);
	pw_inv1.resize(N+1, 1);
	for(int i = 1; i <= N; i++) pw_inv1[i] = pw_inv1[i-1] * p_inv1 % mod1;

	vector<char> v = eval_qs(qs, A, G);
	int S = qs.size();
	vector<query> qs_nw;
	for(int i = 0; i < S; i++) if(v[i] && qs[i].l == qs[i].r) ans[qs[i].id] = qs[i].l;
	for(int i = 0; i < S; i++) if(v[i] && ans[qs[i].id] == -1) {
		if(!qs_nw.empty() && qs_nw.back().id == qs[i].id) continue;
		qs_nw.push_back(qs[i]);
	}
	qs = qs_nw;

	while(!qs.empty()) {
		S = qs.size();
		qs_nw.clear();
		for(int i = 0; i < S; i++) {
			int m = (qs[i].l + qs[i].r + 1) / 2;
			qs_nw.push_back({qs[i].u, qs[i].v, qs[i].l, m-1, qs[i].res, qs[i].id});
		}
		v = eval_qs(qs_nw, A, G);
		for(int i = 0; i < S; i++) {
			int m = (qs[i].l + qs[i].r + 1) / 2;
			if(v[i]) qs[i].r = m-1;
			else qs[i].l = m;
			if(qs[i].l == qs[i].r) ans[qs[i].id] = qs[i].l;
		}
		qs_nw.clear();
		for(int i = 0; i < S; i++) if(ans[qs[i].id] == -1) qs_nw.push_back(qs[i]);
		qs = qs_nw;
	}

	for(int i = 0; i < Q; i++) cout << ((ans[i] >= 0) ? ans[i]+1 : -1) << "\n";
}

// look at my code
// my code is amazing