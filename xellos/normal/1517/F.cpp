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

cat mod = 998244353;

void DFS(int v, int prev, auto & G, auto & dep, auto & cnt_ok, auto & cnt_miss, int D) {
	vector< pair<int, int> > v_by_dep;
	for(auto s : G[v]) if(s != prev) {
		DFS(s, v, G, dep, cnt_ok, cnt_miss, D);
		v_by_dep.push_back({dep[s], s});
	}
	cnt_ok[v][0] = cnt_miss[v][0] = 1;
	sort(begin(v_by_dep), end(v_by_dep));
	for(auto [d, s] : v_by_dep) {
		vector<cat> sum_ok_son = cnt_ok[s];
		for(int i = dep[s]; i > 0; i--) {
			sum_ok_son[i-1] += sum_ok_son[i];
			if(sum_ok_son[i-1] >= mod) sum_ok_son[i-1] -= mod;
		}
		vector<cat> sum_miss_son = cnt_miss[s];
		for(int i = 1; i <= dep[s]; i++) {
			sum_miss_son[i] += sum_miss_son[i-1];
			if(sum_miss_son[i] >= mod) sum_miss_son[i] -= mod;
		}
		vector<cat> sum_ok = cnt_ok[v];
		for(int i = dep[v]; i > 0; i--) {
			sum_ok[i-1] += sum_ok[i];
			if(sum_ok[i-1] >= mod) sum_ok[i-1] -= mod;
		}
		vector<cat> sum_miss = cnt_miss[v];
		for(int i = 1; i <= dep[v]; i++) {
			sum_miss[i] += sum_miss[i-1];
			if(sum_miss[i] >= mod) sum_miss[i] -= mod;
		}
		cat dep_nw = max(dep[v], 1+dep[s]);
		vector<cat> cnt_ok_nw(dep_nw+1, 0);
		vector<cat> cnt_miss_nw(dep_nw+1, 0);
		for(int dv = 0; dv <= dep[v]; dv++) {
			cat a = (dv <= dep[s] ? sum_ok_son[dv] : 0) + (D-dv-1 >= 0 ? sum_miss_son[min(D-dv-1, dep[s])] : 0);
			cnt_ok_nw[dv] = (cnt_ok_nw[dv] + a * cnt_ok[v][dv]) % mod;
			cat b = (dv-1 >= 0 ? sum_miss_son[min(dv-1, dep[s])] : 0) + (D-dv <= dep[s] ? sum_ok_son[max(D-dv, 0)] : 0);
			cnt_miss_nw[dv] = (cnt_miss_nw[dv] + b * cnt_miss[v][dv]) % mod;
		}
		for(int ds = 0; ds <= dep[s]; ds++) {
			cat a = (ds+1 <= dep[v] ? sum_ok[ds+1] : 0) + (D-ds-1 >= 0 ? sum_miss[min(D-ds-1, dep[v])] : 0);
			cnt_ok_nw[ds+1] = (cnt_ok_nw[ds+1] + a * cnt_ok[s][ds]) % mod;
			cat b = sum_miss[min(ds, dep[v])] + (D-ds <= dep[v] ? sum_ok[max(D-ds, 0)] : 0);
			cnt_miss_nw[ds+1] = (cnt_miss_nw[ds+1] + b * cnt_miss[s][ds]) % mod;
		}
		dep[v] = dep_nw;
		cnt_ok[v] = cnt_ok_nw;
		cnt_miss[v] = cnt_miss_nw;
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
	cat ans = pw(2, N, mod) * N - 1;
	for(int k = 1; k <= N; k++) {
		vector< vector<cat> > cnt_ok(N, vector<cat>(1, 0));
		vector< vector<cat> > cnt_miss(N, vector<cat>(1, 0));
		vector<int> dep(N, 0);
		DFS(0, 0, G, dep, cnt_ok, cnt_miss, k);
		for(auto c : cnt_ok[0]) ans -= c;
	}
	cat inv2 = (mod+1)/2;
	ans = ans % mod * pw(inv2, N, mod) % mod;
	if(ans < 0) ans += mod;
	cout << ans << "\n";
}

// look at my code
// my code is amazing