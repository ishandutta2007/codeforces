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

vector<ntt_t> convolution(const vector<ntt_t> & A, const vector<ntt_t> & B) {
	int sz = (int)A.size() + (int)B.size() - 1, n = 2;
	while(n < sz) n *= 2;
 
	constexpr int MAX_N = 1<<20;
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

pair< vector<ntt_t>, vector<ntt_t> > divmod(const vector<ntt_t> & A, const vector<ntt_t> & B) {
	int dA = (int)A.size()-1, dB = (int)B.size()-1;
	if(dA < dB) return {{}, A};
	vector<ntt_t> Ar(dA-dB+1);
	for(int i = 0; i <= dA-dB; i++) Ar[i] = A[dA-i];
	vector<ntt_t> Br(dB+1);
	for(int i = 0; i <= dB; i++) Br[i] = B[dB-i];
	int n = 1, e = 0;
	while(n-1 < dA-dB) n *= 2, e++;
	vector<ntt_t> C = invert(Br, e);
	C.resize(dA-dB+1);
	vector<ntt_t> Qr = convolution(C, Ar);
	vector<ntt_t> Q(dA-dB+1);
	for(int i = 0; i <= dA-dB; i++) Q[i] = Qr[dA-dB-i];
	vector<ntt_t> BQ = convolution(B, Q);
	vector<ntt_t> R(dB, 0);
	for(int i = 0; i < dB; i++) {
		R[i] = A[i] - BQ[i];
		if(R[i] < 0) R[i] += MOD;
	}
	while(!R.empty() && R.back() == 0) R.pop_back();
	return {Q, R};
}

class Multipoint {
	vector< vector<ntt_t> > B[18];

public:
	int e;

	Multipoint(const vector<ntt_t> & X) {
		int pw2 = 1;
		e = 0;
		while(pw2 < (int)X.size()) pw2 *= 2, e++;
		for(int k = 0; k <= e; k++) B[k].resize(pw2>>k, {1});
		for(int i = 0; i < (int)X.size(); i++) B[0][i] = {MOD-X[i]%MOD, 1};
		for(int k = 1; k <= e; k++) for(int i = 0; i < (pw2>>k); i++)
			B[k][i] = convolution(B[k-1][2*i], B[k-1][2*i+1]);
	}

	void multipoint_eval(const vector<ntt_t> & A, ntt_t * ans, int k, int i = 0) {
		if(k == 0) {
			ans[0] = 0;
			if((int)B[0][i].size() > 1)
				for(int j = (int)A.size()-1; j >= 0; j--)
					ans[0] = (ans[0] * (MOD-B[0][i][0]) + A[j]) % MOD;
			return;
		}
		auto Al = divmod(A, B[k-1][2*i]).second, Ar = divmod(A, B[k-1][2*i+1]).second;
		multipoint_eval(Al, ans, k-1, 2*i);
		multipoint_eval(Ar, ans+(1<<(k-1)), k-1, 2*i+1);
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	// ans = sum_l,r sum_t[l:r] #(t[]>0) * sum_i F[t[i]] where F[0]=0
	int N, K;
	cat P;
	cin >> N >> K >> P;
	vector<cat> A(N);
	for(int i = 0; i < N; i++) cin >> A[i];
	vector<cat> inv(N);
	for(int i = 0; i < N; i++) inv[i] = pw(A[i]+1, MOD-2, MOD);
	vector<cat> fac(K+1, 1), fac_inv(K+1, 1);
	for(int i = 1; i <= K; i++) fac[i] = fac[i-1] * i % MOD;
	fac_inv[K] = pw(fac[K], MOD-2, MOD);
	for(int i = K; i >= 1; i--) fac_inv[i-1] = fac_inv[i] * i % MOD;

	vector<cat> S(N+1, 0), PR(N+1, 1), PR_inv(N+1, 1);
	for(int i = 0; i < N; i++) {
		S[i+1] = (S[i] + A[i] * inv[i]) % MOD;
		PR[i+1] = PR[i] * (A[i]+1) % MOD;
		PR_inv[i+1] = PR_inv[i] * inv[i] % MOD;
	}
	cat s[4] = {0, 0, 0, 0};
	vector<cat> coef1(N+1, 0), coef2(N+1, 0);
	for(int i = 1; i <= N; i++) {
		s[0] = (s[0] + PR_inv[i-1]) % MOD;
		s[3] = (s[3] + S[i-1] * PR_inv[i-1]) % MOD;
		coef2[i] = (coef2[i] + PR[i] * s[0]) % MOD;
		coef1[i] = (coef1[i] - PR[i] * s[3]) % MOD;
		coef1[i] = (coef1[i] + S[i] * PR[i] % MOD * s[0]) % MOD;
	}
	for(int i = N-1; i >= 0; i--) {
		s[1] = (s[1] + PR[i+1]) % MOD;
		s[2] = (s[2] + S[i+1] * PR[i+1]) % MOD;
		coef2[i] = (coef2[i] - s[1] * PR_inv[i]) % MOD;
		coef1[i] = (coef1[i] - s[2] * PR_inv[i]) % MOD;
		coef1[i] = (coef1[i] + s[1] * S[i] % MOD * PR_inv[i]) % MOD;
	}
	for(int i = N-1; i >= 0; i--) coef1[i] = (coef1[i] + coef1[i+1]) % MOD;
	for(int i = N-1; i >= 0; i--) coef2[i] = (coef2[i] + coef2[i+1]) % MOD;
	for(int i = 0; i < N; i++) coef1[i] = coef1[i+1] * inv[i] % MOD;
	for(int i = 0; i < N; i++) coef2[i] = coef2[i+1] * pw(inv[i], 2, MOD) % MOD;
	for(int i = 0; i < N; i++) coef1[i] = (coef1[i] + coef2[i]) % MOD;
	// ans = sum_i coef1[i] * sum_1<=j<=A[i] F[j] = sum_i coef1[i] * f[A[i]](x=1)
	// f[n](x) = sum_1<=j<=n F[j] * x**j

	vector<cat> D(1<<17, 0);
	D[0] = MOD-1;
	for(int i = 1; i < (1<<17); i++) D[i] = MOD - D[i-1] * pw(i, MOD-2, MOD) % MOD;
	D[0] = (D[0] + P) % MOD;
	vector<cat> B = invert(D, 17);
	vector<cat> BF(K+1, 0);
	for(int i = 0; i <= K; i++) BF[K-i] = B[i] * fac_inv[K-i] % MOD;
	Multipoint mp_solver(A);
	vector<cat> mp_val(1<<mp_solver.e);
	mp_solver.multipoint_eval(BF, &(mp_val[0]), mp_solver.e);
	cat ans = 0;
	for(int i = 0; i < N; i++)
		ans = (ans - (P * B[K] - pw(P, A[i]+1, MOD) * mp_val[i]) % MOD * coef1[i]) % MOD;
	if(ans < 0) ans += MOD;
	ans = ans * fac[K] % MOD;
	cout << ans << "\n";
}

// look at my code
// my code is amazing