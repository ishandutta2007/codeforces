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
 
void solve(int N, const cat * __restrict V2, const cat * __restrict V3, cat * __restrict out) {
	if(N%2 != 0) {
		solve(N-1, V2, V3, out);
		for(int i = 0; i < N-1; i++)
			out[i+N-1] = (out[i+N-1] + V2[N-1] * V3[i]) % MOD;
		return;
	}
	if(N == 0) return;
	solve(N/2, V2, V3, out);
	solve(N/2, V2+N/2, V3+N/2, out+N);
	static cat A[1<<20], B[1<<20];
	int n = 1;
	while(n < N) n *= 2;
	for(int i = 0; i < N/2; i++) A[i] = V2[i+N/2];
	for(int i = 0; i < N/2; i++) B[i] = V3[i];
	for(int i = N/2; i < n; i++) A[i] = B[i] = 0;
	NTT<false>(A, n);
	NTT<false>(B, n);
	for(int i = 0; i < n; i++) A[i] = A[i] * B[i] % MOD;
	NTT<true>(A, n);
	for(int i = 0; i < N; i++) {
		out[i+N/2] += A[i];
		if(out[i] >= MOD) out[i] -= MOD;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int N, M;
	cin >> N >> M;
	vector<cat> A(N);
	for(int i = 0; i < N; i++) cin >> A[i];
	vector<char> B(N, 0);
	for(int i = 0; i < M; i++) {
		int pos;
		cin >> pos;
		B[pos-1] = 1;
	}
	vector<cat> pw2(N+1, 1);
	for(int i = 1; i <= N; i++) pw2[i] = pw2[i-1] * 2 % MOD;
	cat ans = 0;
	for(int k = 0; k < 2; k++) {
		vector<cat> V1(2*N, 0), V2(2*N, 0), V3(2*N, 1);
		for(int i = 0; i < N; i++) V1[2*i] = A[i] * i % MOD;
		for(int i = N-1, cnt = 0; i >= 0; i--) {
			V2[i+N] = B[i] * pw2[cnt] % MOD;
			cnt += B[i];
		}
		if(k == 0) for(int i = 0, cnt = 0; i < N; i++) {
			V3[i+N] = pw2[cnt];
			cnt += B[i];
		}
		if(k == 1) for(int i = 0, cnt = 0; i < N; i++) {
			cnt += B[i];
			V3[i+N] = pw2[cnt];
		}
		{
			vector<cat> VC(4*N, 0);
			solve(2*N, V2.data(), V3.data(), &(VC[0]));
			for(int i = 2*N; i < 4*N; i++) ans = (ans - V1[i-2*N] * VC[i]) % MOD;
		}
		for(int i = 0; i < N; i++) V1[2*i] = A[i];
		for(int i = N-1, cnt = 0; i >= 0; i--) {
			V2[i+N] = B[i] * i * pw2[cnt] % MOD;
			cnt += B[i];
		}
		{
			vector<cat> VC(4*N, 0);
			solve(2*N, V2.data(), V3.data(), &(VC[0]));
			for(int i = 2*N; i < 4*N; i++) ans = (ans + V1[i-2*N] * VC[i]) % MOD;
		}
		reverse(begin(A), end(A));
		reverse(begin(B), end(B));
	}
	ans = ans * pw(pw2[M]-1, MOD-2, MOD) % MOD;
	if(ans < 0) ans += MOD;
	cout << ans << "\n";
}

// look at my code
// my code is amazing