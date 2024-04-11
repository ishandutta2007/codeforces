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

void DFS(int v, int prev, auto & G, auto & min_lbl, auto & dep) {
	for(auto s : G[v]) if(s != prev) {
		dep[s] = dep[v]+1;
		DFS(s, v, G, min_lbl, dep);
		min_lbl[v] = min(min_lbl[v], min_lbl[s]);
	}
}

void build(int v, int prev, auto & G, auto & min_lbl, auto & orig_lbl, int & cur, auto & final_places) {
	orig_lbl[v] = cur++;
	vector< pair<int, int> > sons_ordered;
	for(auto s : G[v]) if(s != prev) sons_ordered.push_back({min_lbl[s], s});
	sort(begin(sons_ordered), end(sons_ordered));
	for(auto p : sons_ordered) build(p.ss, v, G, min_lbl, orig_lbl, cur, final_places);
	final_places.push_back(v);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int N;
	cin >> N;
	vector<int> lbl(N), pos(N);
	for(int i = 0; i < N; i++) {
		cin >> lbl[i];
		pos[--lbl[i]] = i;
	}
	vector< vector<int> > G(N);
	for(int i = 0; i < N-1; i++) {
		int u, v;
		cin >> u >> v;
		G[--u].push_back(--v);
		G[v].push_back(u);
	}
	vector<int> min_lbl = lbl;
	vector<int> dep(N, 0);
	DFS(0, 0, G, min_lbl, dep);
	vector<int> orig_lbl(N);
	int cur = 0;
	vector<int> final_places;
	build(0, 0, G, min_lbl, orig_lbl, cur, final_places);
	vector<int> sons(N);
	for(int i = 0; i < N; i++) sons[i] = (int)G[i].size() - (i != 0);
	vector<char> rm(N, 0);
	int r = N-1;
	while(r > 0 && sons[pos[r]] == 0 && orig_lbl[pos[r]] == r) {
		int par = -1;
		for(auto v : G[pos[r]]) if(dep[v] < dep[pos[r]]) par = v;
		if(par == -1) {
			cout << "NO\n";
			return 0;
		}
		rm[pos[r]] = 1;
		sons[par]--;
		r--;
	}
	cat days = 0;
	int l = 0;
	while(l < r && sons[pos[l]] == 0 && pos[l] == final_places[l]) {
		int par = -1;
		for(auto v : G[pos[l]]) if(dep[v] < dep[pos[l]]) par = v;
		if(par == -1) {
			cout << "NO\n";
			return 0;
		}
		days += dep[pos[l]];
		rm[pos[l]] = 1;
		sons[par]--;
		l++;
	}
	days += dep[pos[l]];
	bool is_path = true;
	for(int i = 0; i < N; i++) if(!rm[i] && sons[i] > 1) is_path = false;
	if(!is_path) {
		cout << "NO\n";
		return 0;
	}
	cur = pos[l];
	while(cur) {
		int par = -1;
		for(auto v : G[cur]) if(dep[v] < dep[cur]) par = v;
		if(par == -1) {
			cout << "NO\n";
			return 0;
		}
		swap(lbl[cur], lbl[par]);
		cur = par;
	}
	while(sons[cur]) {
		int son = -1;
		for(auto v : G[cur]) if(!rm[v] && dep[v] > dep[cur]) son = v;
		if(lbl[cur] > lbl[son]) {
			cout << "NO\n";
			return 0;
		}
		cur = son;
	}
	cout << "YES\n" << days << "\n";
	for(int i = 0; i < N; i++) cout << orig_lbl[i]+1 << ((i == N-1) ? "\n" : " ");
}

// look at my code
// my code is amazing