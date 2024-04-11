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

void DFS(int v, int prev, auto & G, auto & I, auto & dep) {
	I[v].ss = I[v].ff+1;
	for(auto s : G[v]) if(s != prev) {
		dep[s] = dep[v]+1;
		I[s].ff = I[v].ss;
		DFS(s, v, G, I, dep);
		I[v].ss = I[s].ss;
	}
}

struct itree {
	vector<int> maxv, addv;
	int b;

	itree(int N) {
		b = 1;
		while(b < N) b *= 2;
		maxv.resize(2*b, 0);
		addv.resize(2*b, 0);
	}

	void upd(int cur, int l, int r) {
		if(addv[cur] == 0) return;
		maxv[cur] += addv[cur];
		if(l+1 != r) {
			addv[2*cur] += addv[cur];
			addv[2*cur+1] += addv[cur];
		}
		addv[cur] = 0;
	}

	void add(int I_l, int I_r, int v, int cur = 1, int l = 0, int r = 0) {
		if(cur == 1) r = b;
		I_l = max(I_l, l);
		I_r = min(I_r, r);
		if(I_l == l && I_r == r) {
			addv[cur] += v;
			upd(cur, l, r);
			return;
		}
		upd(cur, l, r);
		if(I_l >= I_r) return;
		add(I_l, I_r, v, 2*cur, l, (l+r)/2);
		add(I_l, I_r, v, 2*cur+1, (l+r)/2, r);
		maxv[cur] = max(maxv[2*cur], maxv[2*cur+1]);
	}

	int get_max(int I_l, int I_r, int cur = 1, int l = 0, int r = 0) {
		if(cur == 1) r = b;
		upd(cur, l, r);
		I_l = max(I_l, l);
		I_r = min(I_r, r);
		if(I_l >= I_r) return 0;
		if(I_l == l && I_r == r) return maxv[cur];
		return max(get_max(I_l, I_r, 2*cur, l, (l+r)/2), get_max(I_l, I_r, 2*cur+1, (l+r)/2, r));
	}

	pair<int,int> get_maxp(int cur = 1, int l = 0, int r = 0) {
		if(cur == 1) r = b;
		if(l+1 == r) return {get_max(l, r, cur, l, r), l};
		int m = (l+r)/2;
		if(get_max(l, r, 2*cur, l, m) >= get_max(l, r, 2*cur+1, m, r))
			return get_maxp(2*cur, l, m);
		else
			return get_maxp(2*cur+1, m, r);
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int N,K;
	cin >> N >> K;
	vector< vector<int> > G(N);
	for(int i = 0; i < N-1; i++) {
		int u,v;
		cin >> u >> v;
		G[--u].push_back(--v);
		G[v].push_back(u);
	}
	vector< pair<int,int> > I(N, {0,0});
	vector<int> dep(N, 1);
	DFS(0, 0, G, I, dep);
	vector<int> id(N);
	for(int i = 0; i < N; i++) id[I[i].ff] = i;
	itree T(N);
	for(int i = 0; i < N; i++) T.add(i, i+1, dep[id[i]]);
	vector<int> A(K+1, 0);
	vector<char> used(N, 0);
	for(int k = 1; k <= K; k++) {
		auto p = T.get_maxp();
		A[k] = A[k-1]+p.ff;
		if(p.ff <= 0) continue;
		int cur = id[p.ss];
		while(!used[cur]) {
			int d = T.get_max(I[cur].ff, I[cur].ff+1);
			T.add(I[cur].ff, I[cur].ff+1, -d);
			for(auto s : G[cur]) if(dep[s] > dep[cur] && !used[s])
				T.add(I[s].ff, I[s].ss, -d);
			used[cur] = 1;
			for(auto s : G[cur]) if(dep[s] < dep[cur]) {
				cur = s;
				break;
			}
		}
	}
	cat ans = -1LL*N*N;
	for(int r = 0; r <= K; r++) if(r <= A[r]) {
		int w0 = A[r]-r;
		int w = N-A[r];
		cat cur = 1LL*N*N;
		if(w <= r) {
			cur = min(cur, 1LL*(w0)*(r-w));
		}
		else {
			cur = 0;
			int h = (w0+w-r)/2;
			if(2*(w-r) <= w0+w-r) cur = min(cur, -1LL*w0*(w-r));
			else for(int b = h; b <= min(h+1,w-r); b++) cur = min(cur, -1LL*(w0+w-r-b)*b);
		}
		ans = max(ans, cur);
	}
	cout << ans << "\n";
}

// look at my code
// my code is amazing