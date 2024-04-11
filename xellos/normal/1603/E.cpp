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
#define soclose 1e-11
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
	int N;
	cat MOD;
	cin >> N >> MOD;
	cat mod2 = 4*MOD*MOD;
	vector<cat> f(N+1, 1);
	for(int i = 1; i <= N; i++) f[i] = f[i-1] * pw(i, MOD-2, MOD) % MOD;
	int inf = (N+1)*(N+1)+1;
	cat ans = 0;
	for(int mi = 1; mi <= N+1; mi++) {
		vector< vector<int> > min_sum(N+2-mi, vector<int>(N+1, inf));
		for(int i = 1; i <= N; i++) if(i <= mi) min_sum[0][i] = i*mi;
		for(int k = mi+1; k <= N+1; k++) {
			for(int i = 0; i <= N; i++) if(min_sum[k-1-mi][i] != inf)
				for(int j = 0; j <= N-i; j++) min_sum[k-mi][i+j] = min(min_sum[k-mi][i+j], min_sum[k-1-mi][i]+j*k);
			for(int i = 0; i <= N; i++) if(min_sum[k-mi][i] > k*mi || min_sum[k-mi][i]+(k+1)*(N-i) > mi*(N+1)) min_sum[k-mi][i] = inf;
		}
		if(min_sum[N+1-mi][N] == inf) continue;
		vector< vector<cat> > dp(N+1);
		for(int i = 0; i <= N; i++) if(min_sum[0][i] != inf) dp[i].resize(1, f[i]);
		for(int k = mi+1; k <= N+1; k++) {
			vector< vector<cat> > dp_nw(N+1);
			for(int i = 0; i <= N; i++) {
				int m = min_sum[k-1-mi][i];
				if(m == inf) continue;
				for(auto & v : dp[i]) v %= MOD;
				for(int j = 0; j <= N-i; j++) {
					int m_nw = min_sum[k-mi][i+j];
					int d = m + k*j - m_nw;
					int a_mi = max(0, m_nw-m-k*j);
					int a_mx = min((int)dp[i].size()-1,min((mi-j)*k-m,mi*(N+1)+j-(k+1)*(N-i)-m));
					if(a_mi > a_mx) continue;
					if((int)dp_nw[i+j].size() <= a_mx+d) dp_nw[i+j].resize(a_mx+d+1, 0);
					for(int a = a_mi; a <= a_mx; a++) {
						dp_nw[i+j][a+d] += dp[i][a] * f[j];
						if(dp_nw[i+j][a+d] >= mod2) dp_nw[i+j][a+d] -= mod2;
					}
				}
			}
			dp = dp_nw;
		}
		for(auto v : dp[N]) ans = (ans + v) % MOD;
	}
	for(int i = 1; i <= N; i++) ans = ans * i % MOD;
	cout << ans << "\n";
}

// look at my code
// my code is amazing