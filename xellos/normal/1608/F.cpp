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

constexpr cat MOD = 998244353;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int N,K;
	cin >> N >> K;
	vector<int> B(N);
	for(int i = 0; i < N; i++) cin >> B[i];
	for(int i = 1; i < N; i++) if(B[i]+K < B[i-1]-K) {
		cout << "0\n";
		return 0;
	}
	vector<cat> fac(N+1, 1), fac_inv(N+1, 1);
	for(int i = 1; i <= N; i++) fac[i] = fac[i-1] * i % MOD;
	for(int i = 1; i <= N; i++) fac_inv[i] = fac_inv[i-1] * pw(i, MOD-2, MOD) % MOD;
	vector< vector<int> > dp(2*K+1, vector<int>(2, 0));
	if(abs(B[0]-1) <= K) dp[1-(B[0]-K)][0] = 1;
	if(abs(B[0]) <= K) dp[0-(B[0]-K)][1] = 1;
	for(int i = 1; i < N; i++) {
		vector< vector<int> > dp_nw(2*K+1, vector<int>(i+2, 0));
		// increase MEX
		static int tmp[110][2210];
		memset(tmp, 0, sizeof(tmp));
		for(int j = 0; j <= 2*K; j++) for(int k = 0; k <= i; k++)
			tmp[j][k+j] = dp[j][k] * fac[k] % MOD;
		for(int j = 0; j <= 2*K; j++) for(int k = 0; k <= 2*K+i; k++) {
			tmp[j+1][k] += tmp[j][k];
			if(tmp[j+1][k] >= MOD) tmp[j+1][k] -= MOD;
		}
		static int tmpd[2210];
		for(int j = i+1; j <= 2*K+i; j++) tmpd[j] = tmp[j-i-1][j];
		for(int j_nw = 0; j_nw <= 2*K; j_nw++) {
			int val_nw = B[i]+j_nw-K;
			if(val_nw < 0 || val_nw > N+1) continue;
			int d = (B[i]+j_nw)-B[i-1]-1; // >= -2K-1
			if(d < 0) continue;
			for(int k = 0; k <= min(i,i-d+2*K); k++) {
				dp_nw[j_nw][k] += tmp[min(2*K,d)][k+d];
				if(dp_nw[j_nw][k] >= MOD) dp_nw[j_nw][k] -= MOD;
			}
			for(int k = max(0,i-d+1); k <= min(i,i-d+2*K); k++) {
				dp_nw[j_nw][k] -= tmpd[k+d];
				if(dp_nw[j_nw][k] < 0) dp_nw[j_nw][k] += MOD;
			}
			for(int k = 0; k <= i; k++) dp_nw[j_nw][k] = dp_nw[j_nw][k] * fac_inv[k] % MOD;
		}
		// keep MEX
		for(int j = 0; j <= 2*K; j++) {
			int val = B[i-1]+j-K;
			if(abs(B[i]-val) > K) continue;
			int j_nw = val-(B[i]-K);
			dp_nw[j_nw][0] = (dp_nw[j_nw][0] + 1LL * dp[j][0] * val) % MOD;
			for(int k = 1; k <= i; k++)
				dp_nw[j_nw][k] = (dp_nw[j_nw][k] + dp[j][k-1] + 1LL * dp[j][k] * (val+k)) % MOD;
			dp_nw[j_nw][i+1] = dp[j][i];
		}
		dp = dp_nw;
	}
	cat ans = 0;
	for(int i = 0; i <= 2*K; i++) {
		int val = B[N-1]+i-K;
		ans = (ans + dp[i][0]) % MOD;
		if(val < 0 || val >= N) continue;
		for(int j = 1; j <= N-val; j++)
			ans = (ans + dp[i][j] * fac[N-val] % MOD * fac_inv[N-val-j]) % MOD;
	}
	cout << ans << "\n";
}

// look at my code
// my code is amazing