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

struct edge {
	int val, u, v;
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int N,K, MX = 1000000;
	cin >> N >> K;
	vector<int> A(1<<N);
	for(int i = 0; i < (1<<N); i++) cin >> A[i];
	vector<int> use_b(1<<N, 0), id(1<<N, -1), V(2*K);
	int ans = 0;
	vector<edge> E;
	E.dibs((1<<(N-1))*N);
	for(int i = 0; i < (1<<N); i++)
		for(int j = 0; j < N; j++) if((i>>j)&1)
			E.push_back(edge{.val = A[i]+A[i^(1<<j)], .u = i, .v = i^(1<<j)});
	vector<int> n_val(2*MX+1, 0);
	for(int i = 0; i < (int)E.size(); i++) n_val[E[i].val]++;
	vector<int> cur_pos(2*MX+2, 0);
	for(int i = 1; i <= 2*MX+1; i++) cur_pos[i] = cur_pos[i-1] + n_val[i-1];
	int min_good_val = 0;
	while(cur_pos[min_good_val] < (N<<(N-1))-2*N*K) min_good_val++;
	vector<edge> Es((1<<(N-1))*N);
	for(int i = 0; i < (1<<(N-1))*N; i++) if(E[i].val >= min_good_val) Es[cur_pos[E[i].val]++] = E[i];
	E = Es;
	for(int k = 0; k < K; k++) {
		vector<int> max_add(2*k, -MX), prev(2*k, -1);
		vector< pair<int, int> > q;
		for(int i = 0; i < 2*k; i++) {
			int v = V[i], u = V[i] ^ use_b[V[i]];
			for(int j = 0; j < N; j++) if(!use_b[v^(1<<j)] && max_add[id[u]] < A[v^(1<<j)])
				max_add[id[u]] = A[v^(1<<j)], prev[id[u]] = v^(1<<j);
			if(max_add[id[u]] >= 0) q.push_back({max_add[id[u]], u});
		}
		sort(begin(q), end(q));
		while(!q.empty()) {
			int v = q.back().ss;
			if(q.back().ff != max_add[id[v]]) {
				q.pop_back();
				continue;
			}
			q.pop_back();
			for(int j = 0; j < N; j++) if(use_b[v^(1<<j)]) {
				int u = v ^ (1<<j) ^ use_b[v^(1<<j)];
				if(max_add[id[u]] < max_add[id[v]]) {
					max_add[id[u]] = max_add[id[v]], prev[id[u]] = v;
					q.push_back({max_add[id[u]], u});
				}
			}
		}
		int max_add_tot = 0, path_end, path_prev;
		for(int i = 0; i < 2*k; i++) {
			int v = V[i];
			for(int j = 0; j < N; j++) if(!use_b[v^(1<<j)] && max_add_tot < max_add[id[v]] + A[v^(1<<j)]) {
				max_add_tot = max_add[id[v]] + A[v^(1<<j)];
				path_prev = v;
				path_end = v^(1<<j);
			}
		}
		while(!E.empty() && (use_b[E.back().u] || use_b[E.back().v])) E.pop_back();
		if(!E.empty() && max_add_tot < E.back().val) {
			max_add_tot = E.back().val;
			path_prev = E.back().u;
			path_end = E.back().v;
		}
		if(max_add_tot == 0) break;
		ans += A[path_end];
		id[path_end] = 2*k;
		V[2*k] = path_end;
		while(use_b[path_prev]) {
			int u = path_prev ^ use_b[path_prev];
			use_b[path_end] = use_b[path_prev] = path_prev^path_end;
			path_prev = prev[id[path_prev]];
			path_end = u;
		}
		ans += A[path_prev];
		id[path_prev] = 2*k+1;
		V[2*k+1] = path_prev;
		use_b[path_end] = use_b[path_prev] = path_prev^path_end;
	}
	cout << ans << "\n";
}

// look at my code
// my code is amazing