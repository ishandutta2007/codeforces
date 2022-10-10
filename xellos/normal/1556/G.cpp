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

struct query {
	int tp;
	cat a,b;
};

struct block { // [x,x+(1<<k))
	cat x;
	int k, id;
	char state;

	block(cat x_) : x{x_} {}
	block(cat x_, int k_, int id_, char state_) : x{x_}, k{k_}, id{id_}, state{state_} {}

	bool operator<(const block & b) const {
		return x < b.x;
	}
};

void add_v(int v, auto & G, auto & blocks, auto & comp, auto & in_comp) {
	blocks[v].state = 2;
	in_comp[v] = v;
	comp[v] = {v};
	for(auto u : G[v]) if(blocks[u].state == 2) {
		int cu = in_comp[u], cv = in_comp[v];
		if(cu == cv) continue;
		if(comp[cu].size() > comp[cv].size()) swap(cu, cv);
		for(auto w : comp[cu]) in_comp[w] = cv;
		comp[cv].insert(end(comp[cv]), begin(comp[cu]), end(comp[cu]));
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int N,Q;
	cin >> N >> Q;
	vector<query> qu(Q);
	vector<cat> X = {0,(1LL<<N)};
	for(int q = 0; q < Q; q++) {
		string s;
		cin >> s >> qu[q].a >> qu[q].b;
		qu[q].tp = (s == "ask");
		if(qu[q].tp == 0) {
			X.push_back(qu[q].a);
			X.push_back(qu[q].b+1);
		}
	}
	sort(begin(X), end(X));
	int L = X.size();
	vector<char> blocked(L, 0);
	blocked[L-1] = 1;
	for(int q = 0; q < Q; q++) if(qu[q].tp == 0) {
		auto it = upper_bound(begin(X), end(X), qu[q].a);
		blocked[it-begin(X)-1] = 1;
	}
	vector<block> blocks;
	int V = 0;
	for(int i = 0; i < L-1; i++) if(X[i+1] != X[i]) {
		cat l = X[i];
		while(l < X[i+1]) {
			int k = 0;
			while(((l>>k)&1) == 0 && X[i+1] >= l+(1LL<<(k+1))) k++;
			blocks.push_back({.x = l, .k = k, .id = V, .state = 1^blocked[i]});
			l += (1LL<<k);
			V++;
		}
	}
	vector< vector<int> > G(V);
	vector<int> extra_size(V, 0), cur_size(V);
	vector<int> prev(N,0), nxt(N,0); // last block <= x-(1<<i), <= x+(1<<i)
	for(int i = 0; i < V; i++) {
		G[i].dibs(N-blocks[i].k);
		for(int k = blocks[i].k; k < N; k++) {
			if((blocks[i].x>>k)&1) {
				cat y = blocks[i].x - (1LL<<k);
				while(prev[k] < V-1 && blocks[prev[k]+1].x <= y) prev[k]++;
				if(blocks[prev[k]].k < blocks[i].k) continue;
				G[i].push_back(blocks[prev[k]].id);
				extra_size[blocks[prev[k]].id]++;
			}
			else {
				cat y = blocks[i].x + (1LL<<k);
				while(nxt[k] < V-1 && blocks[nxt[k]+1].x <= y) nxt[k]++;
				if(blocks[nxt[k]].k <= blocks[i].k) continue;
				G[i].push_back(blocks[nxt[k]].id);
				extra_size[blocks[nxt[k]].id]++;
			}
		}
		cur_size[i] = G[i].size();
	}
	for(int i = 0; i < V; i++) if(extra_size[i]) G[i].dibs(cur_size[i]+extra_size[i]);
	for(int i = 0; i < V; i++)
		for(int j = 0; j < cur_size[i]; j++)
			G[G[i][j]].push_back(i);
	vector< vector<int> > comp(V);
	vector<int> in_comp(V, -1);
	for(int v = 0; v < V; v++) if(blocks[v].state == 1)
		add_v(v, G, blocks, comp, in_comp);
	vector<char> ans(Q, 2);
	for(int q = Q-1; q >= 0; q--) {
		if(qu[q].tp == 0) {
			auto it = lower_bound(begin(blocks), end(blocks), block{.x = qu[q].a});
			for(int v = it->id; v < V && blocks[v].x <= qu[q].b; v++)
				add_v(v, G, blocks, comp, in_comp);
		}
		else {
			auto it = --upper_bound(begin(blocks), end(blocks), block{.x = qu[q].a});
			auto jt = --upper_bound(begin(blocks), end(blocks), block{.x = qu[q].b});
			ans[q] = (in_comp[it->id] == in_comp[jt->id]);
		}
	}
	for(int q = 0; q < Q; q++) if(ans[q] != 2) cout << int(ans[q]) << "\n";
}

// look at my code
// my code is amazing