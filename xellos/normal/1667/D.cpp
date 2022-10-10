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
class maxfin {
	T init_val;
	vector<T> node_val;

	int lastone(int x) { return x & (x ^ (x-1)); }

public:
	maxfin(int N, T init_val_) : init_val{init_val_} {
		node_val.resize(N+10, init_val_);
	}

	void put(int pos, T val) {
		for(int i = pos+1; i < (int)node_val.size(); i += lastone(i))
			node_val[i] = max(node_val[i], val);
	}

	T get(int pos) {
		T ret = init_val;
		for(int i = pos+1; i > 0; i -= lastone(i))
			ret = max(ret, node_val[i]);
		return ret;
	}
};

bool solve(int cur, int prev, auto & G, auto & ans, auto & s1, auto & s2) {
	for(auto v : G[cur]) if(v != prev) {
		if(!solve(v, cur, G, ans, s1, s2)) return false;
		if(s1[v].empty()) {
			for(int i = 0; i < (int)s2[v].size(); i++) ans.push_back({s2[v][i], s1[s2[v][i]][0]});
			s1[cur].push_back(v);
		}
		else s2[cur].push_back(v);
	}
	int D = G[cur].size();
	while(true) {
		if(D%2 != 0 && !s1[cur].empty()) {
			ans.push_back({cur, s1[cur].back()});
			s1[cur].pop_back();
			D--;
			continue;
		}
		if(D%2 == 0 && !s2[cur].empty()) {
			ans.push_back({cur, s2[cur].back()});
			ans.push_back({s2[cur].back(), s1[s2[cur].back()][0]});
			s2[cur].pop_back();
			D--;
			continue;
		}
		break;
	}
	if((int)s1[cur].size() >= 2 || (int)s2[cur].size() >= 2) return false;
	return true;
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
		vector< vector<int> > G(N);
		for(int i = 0; i < N-1; i++) {
			int u,v;
			cin >> u >> v;
			G[--u].push_back(--v);
			G[v].push_back(u);
		}
		vector< pair<int,int> > ans;
		vector< vector<int> > s1(N), s2(N);
		if(!solve(0, 0, G, ans, s1, s2)) {
			cout << "NO\n";
			continue;
		}
		if(!s2[0].empty()) {
			cout << "NO\n";
			continue;
		}
		if(!s1[0].empty()) ans.push_back({0, s1[0][0]});
		cout << "YES\n";
		for(int i = 0; i < N-1; i++) cout << ans[i].ff+1 << " " << ans[i].ss+1 << "\n";
	}
}

// look at my code
// my code is amazing