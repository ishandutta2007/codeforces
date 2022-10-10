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

struct ds {
	int N;
	multiset<int> I;
	fin<int> F;

	ds(int N_) : N(N_), F(N_, 0) {}

	void addI(int pos) {
		I.insert(pos);
	}

	void remI(int pos) {
		I.erase(I.find(pos));
	}

	void add(int pos) {
		F.put(pos, 1);
	}

	void rem(int pos) {
		F.put(pos, -1);
	}

	int get() {
		int l = 0;
		if(!I.empty()) l = *rbegin(I)+1;
		return F.get(N) - F.get(l-1);
	}
};

int ans, val_cur;
vector< vector<int> > GA, GB;
vector<int> path_id, path_pos, par;
vector< vector<int> > paths;
vector<ds> I;

void DFS(int v, auto & sz) {
	int max_path_son = -1;
	for(auto s : GB[v]) {
		DFS(s, sz);
		sz[v] += sz[s];
		if(max_path_son == -1) max_path_son = s;
		if(sz[s] > sz[max_path_son]) max_path_son = s;
	}
	if(max_path_son == -1) {
		path_id[v] = paths.size();
		paths.push_back({});
	}
	else path_id[v] = path_id[max_path_son];
	paths[path_id[v]].push_back(v);
}

void DFS_solve(int v) {
	if(v) {
		int cur = par[v];
		while(true) {
			int id = path_id[cur];
			val_cur -= I[id].get();
			I[id].addI(path_pos[cur]);
			val_cur += I[id].get();
			cur = paths[id][0];
			if(cur == 0) break;
			cur = par[cur];
		}
	}
	val_cur -= I[path_id[v]].get();
	I[path_id[v]].add(path_pos[v]);
	val_cur += I[path_id[v]].get();
	ans = max(ans, val_cur);
	for(auto s : GA[v]) DFS_solve(s);
	if(v) {
		int cur = par[v];
		while(true) {
			int id = path_id[cur];
			val_cur -= I[id].get();
			I[id].remI(path_pos[cur]);
			val_cur += I[id].get();
			cur = paths[id][0];
			if(cur == 0) break;
			cur = par[cur];
		}
	}
	val_cur -= I[path_id[v]].get();
	I[path_id[v]].rem(path_pos[v]);
	val_cur += I[path_id[v]].get();
	ans = max(ans, val_cur);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int T;
	cin >> T;
	while(T--) {
		int N;
		cin >> N;
		vector<int> parA(N,0), parB(N,0);
		GA.clear();
		GA.resize(N);
		GB.clear();
		GB.resize(N);
		for(int i = 0; i < N-1; i++) {
			cin >> parA[i+1];
			GA[--parA[i+1]].push_back(i+1);
		}
		for(int i = 0; i < N-1; i++) {
			cin >> parB[i+1];
			GB[--parB[i+1]].push_back(i+1);
		}
		par = parB;
		paths.clear();
		path_id.resize(N);
		vector<int> sz(N, 1);
		DFS(0, sz);
		path_pos.resize(N);
		I.clear();
		for(int i = 0; i < (int)paths.size(); i++) {
			reverse(begin(paths[i]), end(paths[i]));
			for(int j = 0; j < (int)paths[i].size(); j++) path_pos[paths[i][j]] = j;
			I.push_back(ds(paths[i].size()));
		}
		ans = 1;
		val_cur = 0;
		DFS_solve(0);
		cout << ans << "\n";
	}
}

// look at my code
// my code is amazing