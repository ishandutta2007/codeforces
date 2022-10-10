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

void DFS(int R, int par, auto & G, auto & dep, auto & I, auto & X) {
	I[R].ss = I[R].ff+1;
	for(auto e : G[R]) if(e.ff != par) {
		dep[e.ff] = dep[R]+1;
		X[e.ff] = X[R] ^ e.ss;
		I[e.ff].ff = I[R].ss;
		DFS(e.ff, R, G, dep, I, X);
		I[R].ss = I[e.ff].ss;
	}
}

class itree {
	vector<int> max_val[2];
	vector<int> need_flip;
	int b;

	void push(int cur) {
		if(!need_flip[cur]) return;
		swap(max_val[0][cur], max_val[1][cur]);
		if(cur >= b) {
			need_flip[cur] = 0;
			return;
		}
		need_flip[2*cur] ^= 1;
		need_flip[2*cur+1] ^= 1;
		need_flip[cur] = 0;
	}

	void init(int pos, int val, int X, int l, int r, int cur) {
		if(l == pos && r == pos+1) {
			max_val[X][cur] = val;
			return;
		}
		if(pos < (l+r)/2) init(pos, val, X, l, (l+r)/2, 2*cur);
		else init(pos, val, X, (l+r)/2, r, 2*cur+1);
		max_val[0][cur] = max(max_val[0][2*cur], max_val[0][2*cur+1]);
		max_val[1][cur] = max(max_val[1][2*cur], max_val[1][2*cur+1]);
	}

	void flip(int I_l, int I_r, int l, int r, int cur) {
		I_l = max(I_l, l);
		I_r = min(I_r, r);
		if(I_l >= r || l >= I_r) {
			push(cur);
			return;
		}
		if(I_l == l && I_r == r) {
			need_flip[cur] ^= 1;
			push(cur);
			return;
		}
		push(cur);
		flip(I_l, I_r, l, (l+r)/2, 2*cur);
		flip(I_l, I_r, (l+r)/2, r, 2*cur+1);
		max_val[0][cur] = max(max_val[0][2*cur], max_val[0][2*cur+1]);
		max_val[1][cur] = max(max_val[1][2*cur], max_val[1][2*cur+1]);
	}

public:
	itree(int N) {
		b = 1;
		while(b < N) b *= 2;
		max_val[0].resize(2*b, 0);
		max_val[1].resize(2*b, 0);
		need_flip.resize(2*b, 0);
	}

	void init(int pos, int val, int X) {
		init(pos, val, X, 0, b, 1);
	}

	void flip(int I_l, int I_r) {
		flip(I_l, I_r, 0, b, 1);
	}

	int get() {
		return max_val[0][1];
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(10);
	int N, Q;
	cin >> N;
	vector< vector< pair<int, int> > > G(N);
	vector< pair<int, int> > E(N-1);
	for(int i = 0; i < N-1; i++) {
		int u, v, t;
		cin >> u >> v >> t;
		G[--u].push_back({--v, t});
		G[v].push_back({u, t});
		E[i] = {u, v};
	}
	int r[2];
	{
		queue<int> q;
		q.push(0);
		vector<int> dep(N, -1);
		dep[0] = 0;
		while(!q.empty()) {
			for(auto e : G[q.front()]) if(dep[e.ff] == -1) {
				dep[e.ff] = dep[q.front()]+1;
				q.push(e.ff);
			}
			q.pop();
		}
		r[0] = 0;
		for(int i = 0; i < N; i++) if(dep[i] >= dep[r[0]]) r[0] = i;
	}
	{
		queue<int> q;
		q.push(r[0]);
		vector<int> dep(N, -1);
		dep[r[0]] = 0;
		while(!q.empty()) {
			for(auto e : G[q.front()]) if(dep[e.ff] == -1) {
				dep[e.ff] = dep[q.front()]+1;
				q.push(e.ff);
			}
			q.pop();
		}
		r[1] = 0;
		for(int i = 0; i < N; i++) if(dep[i] >= dep[r[1]]) r[1] = i;
	}
	vector<int> dep[2];
	vector<char> X[2];
	vector< pair<int, int> > I[2];
	itree Tr[2] = {itree(N), itree(N)};
	for(int k = 0; k < 2; k++) {
		dep[k].resize(N, 0);
		X[k].resize(N, 0);
		I[k].resize(N, {0, 0});
		DFS(r[k], r[k], G, dep[k], I[k], X[k]);
		for(int i = 0; i < N; i++) Tr[k].init(I[k][i].ff, dep[k][i], X[k][i]);
	}
	cin >> Q;
	for(int i = 0; i < Q; i++) {
		int id;
		cin >> id;
		id--;
		int ans = 0;
		for(int k = 0; k < 2; k++) {
			int v = E[id].ff;
			if(dep[k][E[id].ss] > dep[k][E[id].ff]) v = E[id].ss;
			Tr[k].flip(I[k][v].ff, I[k][v].ss);
			ans = max(ans, Tr[k].get());
		}
		cout << ans << "\n";
	}
}

// look at my code
// my code is amazing