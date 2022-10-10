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

constexpr cat MOD = 998244353;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	vector<cat> fac(100010, 1), fac_inv(100010, 1);
	for(int i = 1; i <= 100000; i++) fac[i] = fac[i-1] * i % MOD;
	fac_inv[100000] = pw(fac[100000], MOD-2, MOD);
	for(int i = 100000; i >= 1; i--) fac_inv[i-1] = fac_inv[i] * i % MOD;
	int T;
	cin >> T;
	while(T--) {
		int N;
		cin >> N;
		vector<cat> A(N), S(N+1, 0);
		for(int i = 0; i < N; i++) {
			cin >> A[i];
			S[i+1] = S[i]+A[i];
		}
		int n_eq = 0;
		cat ans = 1;
		for(int i = 1, j = N-1; i < N; i++) {
			if(2*S[i] == S[N]) {
				n_eq++;
				continue;
			}
			if(2*S[i] > S[N]) break;
			while(j > i && S[N]-S[j] < S[i]) j--;
			if(S[N]-S[j] != S[i]) continue;
			int nl = 0, nr = 0;
			while(S[i+nl] == S[i]) nl++;
			while(S[j-nr] == S[j]) nr++;
			cat cur = 0;
			for(int k = 0; k <= min(nl, nr); k++) cur += (fac[nl] * fac_inv[nl-k] % MOD * fac_inv[k] % MOD) * (fac[nr] * fac_inv[nr-k] % MOD * fac_inv[k] % MOD) % MOD;
			cur %= MOD;
			ans = ans * cur % MOD;
			i = i+nl-1;
		}
		ans = ans * pw(2, n_eq, MOD) % MOD;
		cout << ans << "\n";
	}
}

// look at my code
// my code is amazing