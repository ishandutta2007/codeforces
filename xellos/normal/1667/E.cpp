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

using ntt_t = long long;
constexpr ntt_t MOD = 998244353LL; // prime, MOD-1 divisible by a large power of 2

ntt_t proot = 3; // primitive MOD-1th root of unity %MOD
vector<ntt_t> W[30];

template <bool rev>
inline __attribute__((always_inline)) void NTT(ntt_t * __restrict A, int N) {
	// N is a power of 2
	for(int i = 0, j = 0; i < N; ++i) {
		if(i < j) swap(A[i], A[j]);
		for(int k = N>>1; (j^=k) < k; k >>= 1) {}
	}
	for(int len = 1, d = 1; len != N; len *= 2, d++) {
		if(W[d].empty()) {
			W[d].resize(1<<d, 1);
			ntt_t root = pw(proot, (MOD-1)/(1<<d), MOD);
			for(int j = 1; j < (1<<d); j++) W[d][j] = W[d][j-1] * root % MOD;
		}
		for(int j = 0; j < N; j += 2*len) {
			ntt_t * __restrict ptr_l = A + j;
			ntt_t * __restrict ptr_r = A + j + len;
			const ntt_t * __restrict ptr_w = W[d].data();
			for(int k = 0; k < len; k++, ptr_l++, ptr_r++, ptr_w++) {
				ntt_t u = *ptr_l, v = *ptr_r * (*ptr_w) % MOD;
				*ptr_l = u + v;
				if(*ptr_l >= MOD) *ptr_l -= MOD;
				*ptr_r = u + (MOD - v);
				if(*ptr_r >= MOD) *ptr_r -= MOD;
			}
		}
	}
	if(rev) {
		reverse(A+1, A+N);
		ntt_t inv_N = pw(N, MOD-2, MOD);
		for(int i = 0; i < N; ++i) A[i] = A[i] * inv_N % MOD;
	}
}
 
vector<ntt_t> convolution(vector<ntt_t> & A, vector<ntt_t> & B) {
	int sz = (int)A.size() + (int)B.size() - 1, n = 2;
	while(n < sz) n *= 2;
 
	constexpr int MAX_N = 1<<21;
	static ntt_t tmp_A[MAX_N];
	memcpy(tmp_A, A.data(), sizeof(ntt_t) * A.size());
	memset(tmp_A+A.size(), 0, sizeof(ntt_t) * (n - A.size()));
	static ntt_t tmp_B[MAX_N];
	memcpy(tmp_B, B.data(), sizeof(ntt_t) * B.size());
	memset(tmp_B+B.size(), 0, sizeof(ntt_t) * (n - B.size()));

	NTT<false>(tmp_A, n);
	NTT<false>(tmp_B, n);

	for(int i = 0; i < n; i++) tmp_A[i] = tmp_A[i] * tmp_B[i] % MOD;

	NTT<true>(tmp_A, n);
	
	vector<ntt_t> ret(sz);
	memcpy(const_cast<ntt_t *>(ret.data()), tmp_A, sizeof(ntt_t) * sz);
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int N;
	cin >> N;
	vector<ntt_t> fac(N+1, 1);
	for(int i = 1; i <= N; i++) fac[i] = fac[i-1] * i % MOD;
	vector<ntt_t> fac_inv(N+1, 1);
	fac_inv[N] = pw(fac[N], MOD-2, MOD);
	for(int i = N; i > 0; i--) fac_inv[i-1] = fac_inv[i] * i % MOD;
	vector<ntt_t> inv(N+1, 1);
	for(int i = 1; i <= N; i++) inv[i] = fac_inv[i] * fac[i-1] % MOD;
	int n = (N-1)/2;
	vector<ntt_t> A(n, 0);
	for(int i = 0, s = 0; i < n; i++) {
		A[i] = (1+MOD-s) * fac[n-i-1] % MOD;
		s += inv[n+i+1];
		if(s >= MOD) s -= MOD;
	}
	fac_inv.resize(n);
	vector<ntt_t> B = convolution(A, fac_inv);
	vector<cat> ans(N+1, 0);
	ans[0] = fac[N-1];
	for(int i = 1; i <= n; i++) {
		ans[i] = B[n-i] * i % MOD * fac[2*n-i] % MOD;
		ans[0] += MOD-ans[i];
		if(ans[0] >= MOD) ans[0] -= MOD;
	}
	for(int i = 0; i < N; i++) cout << ans[i] << ((i == N-1) ? "\n" : " ");
}

// look at my code
// my code is amazing