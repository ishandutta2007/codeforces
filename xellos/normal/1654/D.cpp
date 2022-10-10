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

cat MOD = 998244353;

struct edge {
	int v;
	cat x,y;
};

void DFS(int v, int prev, auto & G, auto & e_cur, auto & cur, auto & ans, auto & pr, auto & inv) {
	for(auto p : G[v]) if(p.v != prev) {
		cat a = p.y;
		while(a > 1) {
			cat b = pr[a];
			e_cur[b]++;
			a /= b;
		}
		a = p.x;
		while(a > 1) {
			cat b = pr[a];
			e_cur[b]--;
			if(e_cur[b] < 0) {
				ans = ans * b % MOD;
				cur = cur * b % MOD;
				e_cur[b]++;
			}
			a /= b;
		}
		cur = cur * p.y % MOD * inv[p.x] % MOD;
		ans = (ans + cur) % MOD;
		DFS(p.v, v, G, e_cur, cur, ans, pr, inv);
		a = p.y;
		while(a > 1) {
			cat b = pr[a];
			e_cur[b]--;
			a /= b;
		}
		a = p.x;
		while(a > 1) {
			cat b = pr[a];
			e_cur[b]++;
			a /= b;
		}
		cur = cur * p.x % MOD * inv[p.y] % MOD;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int T;
	cin >> T;
	int MX = 200000;
	vector<int> pr(MX+1, 0);
	for(int i = 2; i <= MX; i++) if(pr[i] == 0)
		for(int j = i; j <= MX; j += i) pr[j] = i;
	vector<cat> inv(MX+1, 1);
	for(int i = 1; i <= MX; i++) inv[i] = pw(i, MOD-2, MOD);
	while(T--) {
		int N;
		cin >> N;
		vector< vector<edge> > G(N);
		for(int i = 0; i < N-1; i++) {
			int u,v,x,y;
			cin >> u >> v >> x >> y;
			u--, v--;
			G[u].push_back({.v = v, .x = x, .y = y});
			G[v].push_back({.v = u, .x = y, .y = x});
		}
		vector<cat> e_cur(N+1, 0);
		cat ans = 1, cur = 1;
		DFS(0, 0, G, e_cur, cur, ans, pr, inv);
		cout << ans << "\n";
	}
}

// look at my code
// my code is amazing