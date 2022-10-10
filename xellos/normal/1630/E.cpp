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
		for(int i = pos+1; i < (int)node_val.size(); i += lastone(i)) {
			node_val[i] += val;
		}
	}

	T get(int pos) {
		T ret = 0;
		for(int i = pos+1; i > 0; i -= lastone(i)) {
			ret += node_val[i];
		}
		return ret;
	}
};

constexpr cat MOD = 998244353;
constexpr cat MX = 1000000;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	vector<cat> fac(MX+1, 1), fac_inv(MX+1, 1), inv(MX+1, 1);
	for(int i = 1; i <= MX; i++) fac[i] = fac[i-1] * i % MOD;
	fac_inv[MX] = pw(fac[MX], MOD-2, MOD);
	for(int i = MX-1; i >= 1; i--) fac_inv[i] = fac_inv[i+1] * (i+1) % MOD;
	for(int i = 1; i <= MX; i++) inv[i] = fac[i-1] * fac_inv[i] % MOD;
	int T;
	cin >> T;
	while(T--) {
		int N;
		cin >> N;
		vector<int> A(N, 0);
		for(int i = 0; i < N; i++) {
			int a;
			cin >> a;
			A[a-1]++;
		}
		vector<int> B;
		for(int i = 0; i < N; i++) if(A[i]) B.push_back(A[i]);
		int n_col = B.size();
		if(n_col == 1) {
			cout << "1\n";
			continue;
		}
		vector<cat> cnt_p(N+1, 0), sum_p(N+1, 0);
		cat d = 1LL * N * N;
		for(int i = 0; i < n_col; i++) d -= 1LL * B[i] * B[i];
		d %= MOD;
		int g = N;
		for(int i = 0; i < n_col; i++) g = gcd(g, B[i]);
		for(int i = 1; i <= g; i++) if(N%i == 0 && g%i == 0) {
			cnt_p[N/i] = fac[N/i];
			for(int j = 0; j < n_col; j++) cnt_p[N/i] = cnt_p[N/i] * fac_inv[B[j]/i] % MOD;
			sum_p[N/i] = cnt_p[N/i] * d % MOD * inv[i] % MOD * inv[N/i-1] % MOD;
		}
		for(int i = 1; i <= N; i++) if(cnt_p[i]) {
			for(int j = 2*i; j <= N; j += i) if(N%j == 0) cnt_p[j] = (cnt_p[j] + MOD - cnt_p[i]) % MOD;
			for(int j = 2*i; j <= N; j += i) if(N%j == 0) sum_p[j] = (sum_p[j] + MOD - sum_p[i]) % MOD;
		}
		cat cnt = 0, sum = 0;
		for(int i = 1; i <= N; i++) {
			cnt = (cnt + cnt_p[i] * inv[i]) % MOD;
			sum = (sum + sum_p[i] * inv[i]) % MOD;
		}
		cout << sum * pw(cnt, MOD-2, MOD) % MOD << "\n";
	}
}

// look at my code
// my code is amazing