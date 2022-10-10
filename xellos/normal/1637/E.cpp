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
using dbl = double;
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
		map<int,int> cnt, id;
		int V = 0;
		for(int i = 0; i < N; i++) {
			int a;
			cin >> a;
			if(id.find(a) == end(id)) {
				id[a] = V++;
				cnt[a] = 1;
			}
			else cnt[a]++;
		}
		vector< vector<int> > G(V);
		for(int i = 0; i < M; i++) {
			int u,v;
			cin >> u >> v;
			u = id[u], v = id[v];
			G[u].push_back(v);
			G[v].push_back(u);
		}
		for(int i = 0; i < V; i++) sort(begin(G[i]), end(G[i]));
		vector<int> W(V), A(V);
		for(auto p : id) A[p.ss] = p.ff, W[p.ss] = cnt[p.ff];
		vector<int> large;
		int K = min(N+1, 1000);
		for(int i = 0; i < V; i++) if(W[i] >= K) large.push_back(i);
		vector< vector< pair<int,int> > > small(K);
		for(int i = 0; i < V; i++) if(W[i] < K) small[W[i]].push_back({A[i], i});
		for(int i = 0; i < K; i++) sort(begin(small[i]), end(small[i]));
		cat ans = 0;
		vector<char> bad(300010, 0);
		for(auto v : large) {
			for(auto u : G[v]) bad[u] = 1;
			for(auto u : large) if(!bad[u] && u != v) ans = max(ans, 1LL*(W[u]+W[v])*(A[u]+A[v]));
			for(auto u : G[v]) bad[u] = 0;
		}
		for(int v = 0; v < V; v++) {
			for(auto u : G[v]) bad[u] = 1;
			for(int i = 1; i < K; i++) if(i != W[v]) {
				auto it = rbegin(small[i]);
				while(it != rend(small[i]) && bad[it->ss]) it++;
				if(it == rend(small[i])) continue;
				ans = max(ans, 1LL*(W[it->ss]+W[v])*(it->ff+A[v]));
			}
			for(auto u : G[v]) bad[u] = 0;
		}
		for(int i = 1; i < K; i++) for(int j = 0; j < (int)small[i].size(); j++) {
			for(auto u : G[small[i][j].ss]) bad[u] = 1;
			for(int k = (int)small[i].size()-1; k > j; k--) {
				if(bad[small[i][k].ss]) continue;
				ans = max(ans, 2LL*i*(small[i][k].ff+small[i][j].ff));
				break;
			}
			for(auto u : G[small[i][j].ss]) bad[u] = 0;
		}
		cout << ans << "\n";
	}
}

// look at my code
// my code is amazing