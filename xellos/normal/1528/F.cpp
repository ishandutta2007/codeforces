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

typedef unsigned long long ll;

constexpr ll MOD =998244353LL; // prime, MOD-1 divisible by a large power of 2

ll pw(ll a, ll e) {
	if(e <= 0) return 1;
	ll x =pw(a,e/2);
	x =(x*x)%MOD;
	if(e%2 != 0) x =(x*a)%MOD;
	return x;}

ll proot =3; // primitive MOD-1th root of unity %MOD
vector< vector<ll> > OM;

vector<ll> DFT(vector<ll> &A, int N, int d, int x, int dir) {
	vector<ll> ret(N,0);

	if(N == 1) {
		ret[0] =A[x];
		return ret;}
	if(N == 2) {
		ret[0] =(A[x]+A[x+d])%MOD;
		ret[1] =(A[x]+MOD-A[x+d])%MOD;
		return ret;}

	int dep =0, n =N;
	while(n > 1) {n /=2; dep++;}

	vector<ll> DFT0[2];
	DFT0[0] =DFT(A,N/2,d*2,x,dir);
	DFT0[1] =DFT(A,N/2,d*2,x+d,dir);
	for(int i =0; i < N/2; i++) {
		ll com =OM[dep][(N+(1LL*dir*i)%N)%N];
		ret[i] =(DFT0[0][i]+com*DFT0[1][i])%MOD;
		ret[i+N/2] =(DFT0[0][i]+(MOD-com)*DFT0[1][i])%MOD;}
	return ret;}

int SN =1<<17; // arbitrary power of 2 such that N <= SN

vector<ll> convolution(vector<ll> A, vector<ll> B) {
	int Smin =1;
	while(Smin < (int)A.size()*2) Smin *=2;

	// init na omegy
	if(OM.empty()) {
		OM.resize(19);
		for(int i =0; i < 19; i++) {
			ll root =pw(proot,(MOD-1)/(1<<i)); // prim. root modulo N=2**i
			OM[i].resize(1<<i,1);
			for(int j =1; j < (1<<i); j++) OM[i][j] =(OM[i][j-1]*root)%MOD;
			reverse(begin(OM[i])+1,end(OM[i]));} // see NOTE
		}

	A.resize(Smin,0); B.resize(Smin,0);
	vector<ll> FA =DFT(A,A.size(),1,0,1);
	vector<ll> FB =DFT(B,B.size(),1,0,1);

	vector<ll> Fret(FA.size(),0);
	for(uint i =0; i < FA.size(); i++) Fret[i] =(FA[i]*FB[i])%MOD;

	vector<ll> ret =DFT(Fret,Fret.size(),1,0,-1);
	for(uint i =0; i < ret.size(); i++) ret[i] =(ret[i]*pw(ret.size(),MOD-2))%MOD; // normalise
	ret.resize(A.size()*2-1);

	return ret;}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	cat N;
	int K;
	cin >> N >> K;
	vector<cat> fac(K+2, 1);
	for(int i = 1; i <= K+1; i++) fac[i] = fac[i-1] * i % MOD;
	vector<cat> fac_inv(K+2, 1);
	fac_inv[K+1] = pw(fac[K+1], MOD-2, MOD);
	for(int i = K; i >= 1; i--) fac_inv[i] = fac_inv[i+1] * (i+1) % MOD;
	cat ans = 0;
	vector<ll> AK(K+2, 0), AK1(K+2, 0), BK(K+2, 0);
	for(int i = 0; i <= K+1; i++) BK[i] = fac_inv[i] * (i%2 ? MOD-1 : 1) % MOD;
	for(int i = 0; i <= K+1; i++) {
		AK[i] = fac_inv[i] * pw(i, K, MOD) % MOD;
		AK1[i] = AK[i] * i % MOD;
	}
	vector<ll> PK = convolution(AK, BK), PK1 = convolution(AK1, BK);
	cat coef = pw(N+1, N, MOD), iN = pw(N+1, MOD-2, MOD);
	for(int i = 0; i <= K+1; i++) {
		cat a = (N+1 + (N-i) * N % MOD * iN) % MOD;
		ans = (ans + (PK[i] * a + PK1[i]) % MOD * coef) % MOD;
		coef = coef * (N-i) % MOD * iN % MOD;
	}
	ans = ans * pw(2*N+1, MOD-2, MOD) % MOD;
	cout << ans << "\n";
}

// look at my code
// my code is amazing