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
#define OVER9000 1234567890123LL
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

void DFS(int R, auto & G, auto & I) {
	I[R].ss = I[R].ff+1;
	for(auto s : G[R]) {
		I[s].ff = I[R].ss;
		DFS(s, G, I);
		I[R].ss = I[s].ss;
	}
}

struct itree {
	int b;
	vector< pair<int, int> > max_val_pos;

	itree(int N) {
		b = 1;
		while(b < N) b *= 2;
		max_val_pos.resize(2*b, {0, 0});
	}

	pair<int, int> merge(pair<int, int> L, pair<int, int> R) {
		if(L.ff > R.ff) return L;
		else return R;
	}

	void set_val(int pos, int val, int cur = 1, int l = 0, int r = 0) {
		if(cur == 1) r = b;
		if(pos == l && r == l+1) {
			max_val_pos[cur] = {val, l};
			return;
		}
		if(pos < (l+r)/2) set_val(pos, val, 2*cur, l, (l+r)/2);
		else set_val(pos, val, 2*cur+1, (l+r)/2, r);
		max_val_pos[cur] = merge(max_val_pos[2*cur], max_val_pos[2*cur+1]);
	}

	pair<int, int> get_max(int I_l, int I_r, int cur = 1, int l = 0, int r = 0) {
		if(cur == 1) r = b;
		I_l = max(I_l, l);
		I_r = min(I_r, r);
		if(I_l >= r || l >= I_r) return {0, 0};
		if(I_l == l && I_r == r) return max_val_pos[cur];
		auto ret_l = get_max(I_l, I_r, 2*cur, l, (l+r)/2);
		auto ret_r = get_max(I_l, I_r, 2*cur+1, (l+r)/2, r);
		return merge(ret_l, ret_r);
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(10);
	int N, M, Q;
	cin >> N >> M >> Q;
	vector<int> P(N);
	for(int i = 0; i < N; i++) cin >> P[i];
	vector< pair<int, int> > E(M);
	for(int i = 0; i < M; i++) {
		cin >> E[i].ff >> E[i].ss;
		E[i].ff--, E[i].ss--;
	}
	vector< pair<int, int> > queries(Q);
	vector<char> is_rm(M, 0);
	for(int i = 0; i < Q; i++) {
		cin >> queries[i].ff >> queries[i].ss;
		queries[i].ss--;
		if(queries[i].ff == 2) is_rm[queries[i].ss] = 1;
	}
	vector<int> in_comp(N);
	vector< vector<int> > comp(N);
	for(int i = 0; i < N; i++) in_comp[i] = i, comp[i] = {i};
	vector< vector<int> > G(N);
	for(int i = 0; i < M; i++) if(!is_rm[i]) {
		int e = i;
		int u = in_comp[E[e].ff], v = in_comp[E[e].ss];
		if(u == v) continue;
		if(comp[u].size() < comp[v].size()) swap(u, v);
		G[u].push_back(v);
		for(auto w : comp[v]) {
			in_comp[w] = u;
			comp[u].push_back(w);
		}
	}
	vector< pair<int, int> > IQ(Q);
	for(int i = Q-1; i >= 0; i--) {
		if(queries[i].ff == 2) {
			int e = queries[i].ss;
			int u = in_comp[E[e].ff], v = in_comp[E[e].ss];
			if(u == v) continue;
			if(comp[u].size() < comp[v].size()) swap(u, v);
			G[u].push_back(v);
			for(auto w : comp[v]) {
				in_comp[w] = u;
				comp[u].push_back(w);
			}
		}
		else {
			int c = in_comp[queries[i].ss];
			IQ[i] = {c, comp[c].size()};
		}
	}
	vector< pair<int, int> > I(N, {-1, -1});
	for(int i = 0, cur = 0; i < N; i++) {
		int v = in_comp[i];
		if(I[v].ff != -1) continue;
		I[v].ff = cur;
		DFS(v, G, I);
		cur = I[v].ss;
	}
	vector<int> A(N);
	for(int i = 0; i < N; i++) A[I[i].ff] = P[i];
	itree IT(N);
	for(int i = 0; i < N; i++) IT.set_val(i, A[i]);
	for(int q = 0; q < Q; q++) if(queries[q].ff == 1) {
		int id = I[IQ[q].ff].ff;
		pair<int, int> p = IT.get_max(id, id+IQ[q].ss);
		if(p.ff) IT.set_val(p.ss, 0);
		cout << p.ff << "\n";
	}
}

// look at my code
// my code is amazing