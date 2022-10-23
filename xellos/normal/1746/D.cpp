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

void solve(int v, int par, auto & G, auto & W, auto & K, auto & ans) {
	int S = G[v].size();
	if(S == 0) {
		ans[v].ff = K[v].ff * W[v];
		ans[v].ss = K[v].ss * W[v];
		return;
	}
	for(auto s : G[v]) if(s != par) {
		K[s].ff = K[v].ff / S;
		K[s].ss = (K[v].ss+S-1) / S;
		solve(s, v, G, W, K, ans);
	}
	for(int j = 0; j < 2; j++) {
		cat k = (j == 0) ? K[v].ff : K[v].ss;
		cat cnt_lo = k / S, cnt_hi = (k+S-1) / S;
		static vector<cat> son_dif;
		son_dif.clear();
		cat a = 0;
		for(auto s : G[v]) {
			cat son_lo, son_hi;
			if(cnt_lo == K[s].ff) son_lo = ans[s].ff;
			if(cnt_lo == K[s].ss) son_lo = ans[s].ss;
			if(cnt_hi == K[s].ff) son_hi = ans[s].ff;
			if(cnt_hi == K[s].ss) son_hi = ans[s].ss;
			a += son_lo;
			son_dif.push_back(son_hi-son_lo);
		}
		sort(begin(son_dif), end(son_dif));
		a += std::accumulate(rbegin(son_dif), rbegin(son_dif) + k%S, 0);
		if(j == 0) ans[v].ff = a + k * W[v];
		else ans[v].ss = a + k * W[v];
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
		int N;
		cin >> N;
		vector< pair<cat,cat> > K(N, {-1, -1});
		cin >> K[0].ff;
		K[0].ss = K[0].ff;
		vector<int> par(N, 0);
		vector< vector<int> > G(N);
		for(int i = 1; i < N; i++) {
			cin >> par[i];
			G[--par[i]].push_back(i);
		}
		vector<cat> W(N);
		for(int i = 0; i < N; i++) cin >> W[i];
		vector< pair<cat, cat> > ans(N, {0, 0});
		solve(0, 0, G, W, K, ans);
		cout << ans[0].ff << "\n";
	}
}

// look at my code
// my code is amazing