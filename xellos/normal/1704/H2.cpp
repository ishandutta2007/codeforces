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

using ntt_t = long long;
ntt_t MOD; // prime, MOD-1 divisible by a large power of 2

ntt_t proot; // primitive MOD-1th root of unity %MOD
vector<ntt_t> W[19];

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

vector<ntt_t> convolution(const vector<ntt_t> & A, const vector<ntt_t> & B) {
	int sz = (int)A.size() + (int)B.size() - 1, n = 2;
	if(sz <= (1<<7)) {
		vector<ntt_t> ret(sz, 0);
		ntt_t mod2 = MOD * MOD * 4;
		for(int i = 0; i < (int)A.size(); i++) for(int j = 0; j < (int)B.size(); j++) {
			ret[i+j] += A[i] * B[j];
			if(ret[i+j] >= mod2) ret[i+j] -= mod2;
		}
		for(int i = 0; i < sz; i++) ret[i] %= MOD;
		return ret;
	}
	while(n < sz) n *= 2;
 
	constexpr int MAX_N = 1<<18;
	static ntt_t tmp_A[MAX_N];
	memcpy(tmp_A, A.data(), sizeof(ntt_t) * A.size());
	memset(tmp_A+A.size(), 0, sizeof(ntt_t) * (n - A.size()));
	for(int i = 0; i < n; i++) if(tmp_A[i] < 0) tmp_A[i] += MOD;
	static ntt_t tmp_B[MAX_N];
	memcpy(tmp_B, B.data(), sizeof(ntt_t) * B.size());
	memset(tmp_B+B.size(), 0, sizeof(ntt_t) * (n - B.size()));
	for(int i = 0; i < n; i++) if(tmp_B[i] < 0) tmp_B[i] += MOD;

	NTT<false>(tmp_A, n);
	NTT<false>(tmp_B, n);

	for(int i = 0; i < n; i++) tmp_A[i] = tmp_A[i] * tmp_B[i] % MOD;

	NTT<true>(tmp_A, n);
	
	vector<ntt_t> ret(sz, 0);
	memcpy(const_cast<ntt_t *>(ret.data()), tmp_A, sizeof(ntt_t) * sz);
	return ret;
}

vector<ntt_t> invert(const vector<ntt_t> & A, int e) {
	// exactly 2**e terms, non-singular
	int sz = A.size();
	if(e == 0) return (A[0] == 1) ? vector<ntt_t>{1} : vector<ntt_t>{pw(A[0], MOD-2, MOD)};
	vector<ntt_t> B = invert(A, e-1);
	vector<ntt_t> AB;
	if(sz < (1<<e)) AB = convolution(A, B);
	else {
		vector<ntt_t> Ar(begin(A), begin(A)+(1<<e));
		AB = convolution(Ar, B);
	}
	vector<ntt_t> C(1<<(e-1), 0);
	for(int i = (1<<(e-1)); i < min(1<<e, (int)AB.size()); i++)
		C[i-(1<<(e-1))] = MOD-AB[i];
	vector<ntt_t> B_hi = convolution(C, B);
	B_hi.resize(1<<(e-1));
	B.insert(end(B), begin(B_hi), end(B_hi));
	return B;
}

vector<ntt_t> fac{1}, fac_inv{1}, inv;

pair< vector<ntt_t>, vector<ntt_t> > exp_with_inv(const vector<ntt_t> & A, int e) {
	// exactly 2**e terms of exp(A), exp(-A) with A[0] = 0, A != 0
	if(e == 0) return {vector<ntt_t>{1}, vector<ntt_t>{1}};
	if((int)fac.size() < (1<<e)) {
		int sz_old = fac.size();
		fac.resize(1<<e);
		for(int i = sz_old; i < (1<<e); i++) fac[i] = fac[i-1] * i % MOD;
		fac_inv.resize(1<<e);
		fac_inv[(1<<e)-1] = pw(fac[(1<<e)-1], MOD-2, MOD);
		for(int i = (1<<e)-1; i > sz_old; i--) fac_inv[i-1] = fac_inv[i] * i % MOD;
		inv.resize(1<<e);
		for(int i = sz_old; i < (1<<e); i++) inv[i] = fac_inv[i] * fac[i-1] % MOD;
	}
	int sz = A.size();
	auto [B, B_inv] = exp_with_inv(A, e-1);
	{
		vector<ntt_t> dA(min(sz,1<<(e-1)), 0);
		for(int i = 1; i < min(sz, 1<<(e-1)); i++) dA[i-1] = i * A[i] % MOD;
		auto C = convolution(dA, B);
		vector<ntt_t> C_hi(begin(C)+(1<<(e-1))-1, end(C));
		C = convolution(C_hi, B_inv);
		vector<ntt_t> lB_hi(1<<(e-1), 0);
		for(int i = (1<<(e-1)); i < (1<<e); i++) lB_hi[i-(1<<(e-1))] = ((i>=sz?0:A[i]) + C[i-(1<<(e-1))] * inv[i]) % MOD;
		vector<ntt_t> B_hi = convolution(lB_hi, B);
		B_hi.resize(1<<(e-1));
		B.insert(end(B), begin(B_hi), end(B_hi));
	}
	{
		auto C = convolution(B, B_inv);
		C[0] = 0;
		vector<ntt_t> C_hi(begin(C)+(1<<(e-1)), end(C));
		for(auto & val : C_hi) val = (val != 0) ? MOD - val : 0;
		auto B_inv_hi = convolution(C_hi, B_inv);
		B_inv_hi.resize(1<<(e-1));
		B_inv.insert(end(B_inv), begin(B_inv_hi), end(B_inv_hi));
	}
	return {B, B_inv};
}

vector<ntt_t> exp(const vector<ntt_t> & A, int e) {
	return exp_with_inv(A, e).ff;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int N;
	cat mod;
	cin >> N >> mod;

	MOD = mod;
	vector<int> primes{2};
	cat cur = (mod-1)>>18;
	for(int i = 2; i <= cur; i++) if(cur%i == 0) {
		primes.push_back(i);
		while(cur%i == 0) cur /= i;
	}
	for(int i = 1; ; i++) {
		bool is_proot = true;
		for(auto p : primes) if(pw(i, (mod-1)/p, mod) == 1) {
			is_proot = false;
			break;
		}
		if(!is_proot) continue;
		proot = i;
		break;
	}

	vector<ntt_t> F{0, 1};
	int e = 1;
	while((int)F.size()-1 < N+1) {
		e++;
		auto [E, E_inv] = exp_with_inv(F, e);

		auto A_bot = E_inv;
		for(int i = 0; i < (1<<(e-1)); i++) A_bot[i] = (A_bot[i] + mod - F[i]) % MOD;
		auto A_bot_inv = invert(A_bot, e);
		auto A_top = convolution(F, F);
		auto A = convolution(A_top, A_bot_inv);
		A.resize(1<<e, 0);

		auto [EA, EA_inv] = exp_with_inv(A, e);

		auto C = convolution(EA_inv, F);
		vector<ntt_t> F_hi_top(begin(C)+(1<<(e-1)), begin(C)+(1<<e));
		EA.resize(1<<(e-1), 0);
		F_hi_top = convolution(F_hi_top, EA);
		F_hi_top.resize(1<<(e-1), 0);
		for(auto & val : F_hi_top) val = (val != 0) ? MOD - val : 0;

		auto F_hi_bot = F;
		F_hi_bot[0] = (F_hi_bot[0] + 2) % MOD;
		F_hi_bot = convolution(E_inv, F_hi_bot);
		F_hi_bot.resize(1<<(e-1), 0);
		for(int i = 0; i < (1<<(e-1)); i++) F_hi_bot[i] = (F_hi_bot[i] + MOD - F[i]) % MOD;
		A_bot_inv.resize(1<<(e-1), 0);
		C = convolution(F, A_bot_inv);
		C.resize(1<<(e-1), 0);
		C = convolution(C, C);
		C.resize(1<<(e-1), 0);
		F_hi_bot = convolution(F_hi_bot, C);
		F_hi_bot.resize(1<<(e-1), 0);
		for(auto & val : F_hi_bot) val = (val != 0) ? MOD - val : 0;
		F_hi_bot[0] = (F_hi_bot[0] + 1) % MOD;

		auto F_hi_bot_inv = invert(F_hi_bot, e-1);
		auto F_hi = convolution(F_hi_top, F_hi_bot_inv);
		F_hi.resize(1<<(e-1), 0);
		F.insert(end(F), begin(F_hi), end(F_hi));
	}

	vector<ntt_t> Fd((1<<e)-1);
	for(int i = 1; i < (1<<e); i++) Fd[i-1] = F[i];
	auto Fd_inv = invert(Fd, e);

	for(int i = 1; i <= N; i++) cout << (MOD - Fd_inv[i]) * (i-1) % MOD * fac[i] % MOD << "\n";
}

// look at my code
// my code is amazing