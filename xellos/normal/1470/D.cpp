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

cat gcd(cat a, cat b) {
	if(a > b) swap(a, b);
	while(a) {
		cat c = b%a;
		b = a;
		a = c;
	}
	return b;
}

void push(int v, auto & G, auto & ans, auto & dist, set<int> * S) {
	ans.push_back(v);
	S[0].insert(v);
	S[dist[v]].erase(v);
	dist[v] = 0;
	static vector<int> push1;
	push1.clear();
	for(auto u : G[v]) if(dist[u] > 1) {
		push1.push_back(u);
		S[1].insert(u);
		S[dist[u]].erase(u);
		dist[u] = 1;
	}
	for(auto u : push1) for(auto w : G[u]) if(dist[w] == 3) {
		S[2].insert(w);
		S[3].erase(w);
		dist[w] = 2;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int T;
	cin >> T;
	while(T--) {
		int N, M;
		cin >> N >> M;
		vector< vector<int> > G(N);
		for(int i = 0; i < M; i++) {
			int u, v;
			cin >> u >> v;
			G[--u].push_back(--v);
			G[v].push_back(u);
		}
		vector<int> ans;
		vector<char> dist(N, 3);
		set<int> S[4];
		for(int i = 1; i < N; i++) S[3].insert(i);
		S[0].insert(0);
		dist[0] = 0;
		push(0, G, ans, dist, S);
		while(!S[2].empty()) push(*begin(S[2]), G, ans, dist, S);
		if(!S[3].empty()) cout << "NO\n";
		else {
			cout << "YES\n" << ans.size() << "\n";
			for(int i = 0; i < (int)ans.size(); i++)
				cout << ans[i]+1 << ((i == (int)ans.size()-1) ? "\n" : " ");
		}
	}
}

// look at my code
// my code is amazing