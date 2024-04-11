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

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int N, K;
	cin >> N >> K;
	vector< vector< pair<int, cat> > > I(N+2); // [ss, ss+2^ff)
	for(int i = 1; i <= N; i++) {
		cat L, R;
		cin >> L >> R;
		R++;
		for(int k = 0; k <= K; k++) {
			if((L>>k)&1 && L+(1LL<<k) <= R) {
				I[i].push_back({k, L});
				L += 1LL<<k;
			}
			if((R>>k)&1 && R-(1LL<<k) >= L) {
				I[i].push_back({k, R-(1LL<<k)});
				R -= 1LL<<k;
			}
		}
		sort(begin(I[i]), end(I[i]));
	}
	I[0].resize(1);
	I[N+1].resize(1);
	vector<int> sz(N+2, 1);
	for(int i = 1; i <= N; i++) sz[i] = I[i].size();
	vector<cat> C(K+1, 0);
	for(int i = 0; i < K; i++) cin >> C[i];
	vector<cat> dp[52][102];
	for(int l = 0; l <= N; l++) for(int p = 0; p < sz[l]; p++) {
		int sz2 = 0;
		for(int r = l+1; r <= N+1; r++) sz2 += sz[r];
		dp[l][p].resize(sz2, OVER9000);
		for(int i = 0; i < sz[l+1]; i++) dp[l][p][i] = 0;
	}
	for(int b = K; b >= 0; b--) {
		for(int i = 1; i <= N; i++)
			while(!I[i].empty() && I[i].back().ff > b) I[i].pop_back();
		for(int l = 0; l <= N; l++) for(int p = 0; p < (int)I[l].size(); p++) {
			int id_nw = 0, id = 0;
			for(int r = l+1; r <= N+1; r++) {
				int sz_nw = I[r].size();
				for(int s = 0; s < sz_nw; s++) dp[l][p][id_nw+s] = dp[l][p][id+s];
				id += sz[r];
				id_nw += sz_nw;
			}
		}
		for(int i = 1; i <= N; i++) sz[i] = I[i].size();
		for(int l = 1; l < N; l++) for(int p = 0; p < sz[l]; p++) {
			int id = 0;
			for(int r = l+1; r <= N; r++) for(int s = 0; s < sz[r]; s++)
				dp[l][p][id++] += (((I[l][p].ss^I[r][s].ss)>>b)&1) * C[b];
		}
		for(int l = N; l >= 0; l--) for(int p = 0; p < sz[l]; p++) {
			int sh = 0, sz2 = 0;
			for(int i = l+1; i <= N+1; i++) sz2 += sz[i];
			for(int m = l+1; m <= N; m++) {
				sh += sz[m];
				sz2 -= sz[m];
				for(int c = sz[m]-1; c >= 0; c--) {
					if(I[m][c].ff != b) break;
					cat ca = dp[l][p][sh-sz[m]+c];
					for(int i = 0; i < sz2; i++) dp[l][p][i+sh] = min(dp[l][p][i+sh], ca+dp[m][c][i]);
				}
			}
		}
	}
	int id = 0;
	for(int i = 1; i <= N; i++) id += sz[i];
	cout << dp[0][0][id] << "\n";
}

// look at my code
// my code is amazing