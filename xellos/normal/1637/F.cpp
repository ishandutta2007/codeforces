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

void solve(int cur, int prev, auto & G, auto & H, auto & dp) {
	for(auto s : G[cur]) if(s != prev) {
		solve(s, cur, G, H, dp);
		H[cur] = max(H[cur], H[s]);
	}
	// dp[cur].ss: sucet dp.ff vsetkych synov okrem jedneho
	cat sum = 0;
	for(auto s : G[cur]) if(s != prev) sum += dp[s].ff;
	dp[cur].ss = sum;
	for(auto s : G[cur]) if(s != prev) dp[cur].ss = min(dp[cur].ss, sum-dp[s].ff+dp[s].ss);
	// dp[cur].ff ak pod nim nemam H[cur]
	dp[cur].ff = dp[cur].ss+H[cur];
	// bool has_bot = false;
	// for(auto s : G[cur]) if(s != prev && H[cur] == H[s]) has_bot = true;
	// if(has_bot)
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int N;
	cin >> N;
	vector<cat> H(N);
	for(int i = 0; i < N; i++) cin >> H[i];
	vector< vector<int> > G(N);
	for(int i = 0; i < N-1; i++) {
		int u,v;
		cin >> u >> v;
		G[--u].push_back(--v);
		G[v].push_back(u);
	}
	int root = 0;
	for(int i = 1; i < N; i++) if(H[i] > H[root]) root = i;
	vector< pair<cat,cat> > dp(N, {OVER9000, OVER9000});
	solve(root, root, G, H, dp);
	cat ans = OVER9000;
	if((int)G[root].size() == 1)
		ans = 2*H[root] + dp[G[root][0]].ss;
	else {
		// pre dvoch synov ss, pre zvysok ff
		cat mxh[2] = {0, 0};
		ans = 2*H[root];
		for(auto s : G[root]) {
			ans += dp[s].ff;
			if(H[s] >= mxh[0]) {
				mxh[1] = mxh[0];
				mxh[0] = H[s];
			}
			else if(H[s] >= mxh[1]) mxh[1] = H[s];
		}
		ans -= mxh[0]+mxh[1];
	}
	cout << ans << "\n";
}

// look at my code
// my code is amazing