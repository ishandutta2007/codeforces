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

void DFS(int v, auto & G, auto & par, auto & sz, auto & dep) {
	for(auto s : G[v]) if(par[s] == -1) {
		par[s] = v;
		dep[s] = dep[v]+1;
		DFS(s, G, par, sz, dep);
		sz[v] += sz[s];
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int N;
	cin >> N;
	vector< vector<int> > G(N);
	for(int i = 0; i < N-1; i++) {
		int u, v;
		cin >> u >> v;
		G[--u].push_back(--v);
		G[v].push_back(u);
	}
	cat mod = 1000000007;
	cat inv2 = (mod+1)/2;
	vector< vector<cat> > P(N, vector<cat>(N, 0));
	for(int i = 1; i < N; i++) P[0][i] = 1;
	for(int i = 1; i < N; i++)
		for(int j = 1; j < N; j++)
			P[i][j] = (P[i-1][j] + P[i][j-1]) * inv2 % mod;
	vector< vector<cat> > B(N, vector<cat>(N, 0));
	cat ans = 0;
	for(int i = 0; i < N; i++) {
		vector<int> sz(N, 1), par(N, -1), dep(N, 0);
		par[i] = i;
		DFS(i, G, par, sz, dep);
		for(int j = 0; j < i; j++) {
			int cur = j, last = -1, a_s = N;
			static vector<int> A;
			A.clear();
			while(cur != i) {
				int a = 1;
				for(auto s : G[cur])
					if(dep[s] > dep[cur] && s != last) a += sz[s];
				a_s -= a;
				A.push_back(a);
				last = cur;
				cur = par[cur];
			}
			A.push_back(a_s);
			int D = A.size();
			for(int k = 0; k < D; k++) B[D-1-k][k] += A[k];
		}
	}
	for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) {
		B[i][j] %= mod;
		P[i][j] %= mod;
		ans = (ans + B[i][j] * P[i][j]) % mod;
	}
	ans = ans * pw(N, mod-2, mod) % mod;
	cout << ans << "\n";
}

// look at my code
// my code is amazing