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

int DFS_SG_down(int v, int prev, auto & G, auto & par) {
	int sg = 0;
	for(auto & p : G[v]) if(p.ff != prev) {
		par[p.ff] = v;
		p.ss = DFS_SG_down(p.ff, v, G, par);
		sg ^= p.ss;
	}
	return sg+1;
}

void DFS_SG_up(int v, int prev, auto & G, int sg_par = 0) {
	for(auto & p : G[v]) if(p.ff == prev) {
		p.ss = sg_par+1;
		break;
	}
	int sg_cur = 0;
	for(auto & p : G[v]) sg_cur ^= p.ss;
	for(auto & p : G[v]) if(p.ff != prev)
		DFS_SG_up(p.ff, v, G, sg_cur^p.ss);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int N;
	cin >> N;
	vector< vector< pair<int,int> > > G(N);
	for(int i = 0; i < N-1; i++) {
		int u,v;
		cin >> u >> v;
		G[--u].push_back({--v,0});
		G[v].push_back({u,0});
	}
	vector<int> par(N, 0);
	DFS_SG_down(0, 0, G, par);
	DFS_SG_up(0, 0, G);
	vector<char> in_cyc(N, 0);
	in_cyc[0] = 1;
	int n_cyc = 0;
	vector<int> sg_out(N);
	int X = 0;
	for(auto p : G[0]) {
		sg_out[p.ff] = p.ss;
		X ^= p.ss;
	}
	cout << (X ? 1 : 2);
	for(int i = 1; i < N; i++) {
		static vector<int> path;
		int cur = i;
		while(!in_cyc[cur]) {
			path.push_back(cur);
			cur = par[cur];
		}
		while(!path.empty()) {
			cur = path.back();
			path.pop_back();
			X ^= sg_out[cur];
			in_cyc[cur] = 1;
			for(auto p : G[cur]) if(!in_cyc[p.ff]) {
				sg_out[p.ff] = p.ss;
				X ^= p.ss;
			}
			n_cyc++;
		}
		cout << ((X^(n_cyc&1)) ? 1 : 2);
	}
	cout << '\n';
}

// look at my code
// my code is amazing