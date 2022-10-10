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

void DFS_init(int v, auto & G, auto & W, auto & R, auto & dp, auto & V, auto & sz, auto & path_id, auto & paths) {
	int l = v+1;
	sz[v] = 1;
	int id = paths.size(), sz_max = -1;
	for(auto s : G[v]) {
		while(l <= s) V[l++] = v;
		l = R[s];
		DFS_init(s, G, W, R, dp, V, sz, path_id, paths);
		dp[v] += dp[s];
		sz[v] += sz[s];
		if(sz[s] > sz_max) sz_max = sz[s], id = path_id[s];
	}
	while(l < R[v]) V[l++] = v;
	dp[v] = max(dp[v], -W[v]);
	if(id == (int)paths.size()) paths.push_back({v});
	else paths[id].push_back(v);
	path_id[v] = id;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int N, Q;
	cin >> N >> Q;
	vector<int> P(N+1), pos(N+1);
	P[N] = pos[N] = N;
	for(int i = 0; i < N; i++) {
		cin >> P[i];
		pos[--P[i]] = i;
	}
	vector<int> R(N+1, N), par(N+1, N);
	{
		stack<int> S;
		S.push(N);
		for(int i = N-1; i >= 0; i--) {
			while(P[S.top()] < P[i]) S.pop();
			R[i] = S.top();
			S.push(i);
		}
	}
	{
		stack<int> S;
		for(int i = 0; i < N; i++) {
			while(!S.empty() && P[S.top()] < P[i]) S.pop();
			par[i] = S.empty() ? N : S.top();
			S.push(i);
		}
	}
	vector< vector<int> > G(N+1);
	for(int i = 0; i < N; i++) G[par[i]].push_back(i);
	vector<cat> AS(N+1, 0);
	for(int i = 0; i < N; i++) {
		cin >> AS[i+1];
		AS[i+1] += AS[i];
	}
	vector<cat> W(N+1, 0);
	for(int i = 0; i < N; i++) {
		cin >> W[i];
		W[i] -= AS[R[i]]-AS[i];
	}
	vector<cat> dp(N+1, 0);
	vector<int> V(N, N), sz(N+1), path_id(N+1), path_dep(N+1);
	vector< vector<int> > paths;
	DFS_init(N, G, W, R, dp, V, sz, path_id, paths);
	vector<cat> Wv(N+1, 0);
	for(int i = 0; i < N; i++) {
		Wv[i] = dp[i];
		for(auto s : G[i]) Wv[i] -= dp[s];
	}
	vector< multiset<int> > S(paths.size());
	S[path_id[N]].insert(0);
	S[path_id[N]].insert(0);
	vector< vector<cat> > Sv(paths.size());
	for(int i = 0; i < (int)paths.size(); i++) {
		reverse(begin(paths[i]), end(paths[i]));
		Sv[i].resize((int)paths[i].size()+1, 0);
		for(int j = 0; j < (int)paths[i].size(); j++) {
			path_dep[paths[i][j]] = j;
			Sv[i][j+1] = Sv[i][j]+Wv[paths[i][j]];
		}
	}
	cat ans = AS[N];
	for(auto s : G[N]) ans -= dp[s];
	vector<char> used(N+1, 0);
	used[N] = 1;
	for(int q = 0; q < Q; q++) {
		int x;
		cin >> x;
		x--;
		int v = V[x];
		if(used[x]) {
			int cur = v;
			while(true) {
				int p = path_id[cur];
				if((int)S[p].size() <= 1) ans -= Sv[p][path_dep[cur]+1];
				else {
					auto it = --(--end(S[p]));
					if(path_dep[cur] >= *it) ans -= Sv[p][path_dep[cur]+1]-Sv[p][(*it)+1];
				}
				S[p].erase(S[p].find(path_dep[cur]));
				if(p == path_id[N]) break;
				cur = par[paths[p][0]];
			}
			used[x] = 0;
		}
		else {
			int cur = v;
			while(true) {
				int p = path_id[cur];
				if((int)S[p].empty()) ans += Sv[p][path_dep[cur]+1];
				else {
					auto it = --end(S[p]);
					if(path_dep[cur] >= *it) ans += Sv[p][path_dep[cur]+1]-Sv[p][(*it)+1];
				}
				S[p].insert(path_dep[cur]);
				if(p == path_id[N]) break;
				cur = par[paths[p][0]];
			}
			used[x] = 1;
		}
		cout << ans << "\n";
	}
}

// look at my code
// my code is amazing