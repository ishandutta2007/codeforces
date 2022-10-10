#include <bits/stdc++.h>
// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
#include <time.h>
#define dibs reserve
#define OVER9000 1234567890
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-8
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
#define dbl long double
#define pi 3.14159265358979323846
using namespace std;
// mylittledoge

typedef long long cat;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

cat pw(cat a, cat e, cat mod) {
	if(e <= 0) return 1;
	cat x = pw(a, e/2, mod);
	x = (x*x)%mod;
	if(e&1) x = (x*a)%mod;
	return x;
}

typedef unsigned long long ll;

ll MOD =998244353LL; // prime, MOD-1 divisible by a large power of 2

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

int SN =1<<20; // arbitrary power of 2 such that N <= SN

vector<ll> convolution(vector<ll> A, vector<ll> B) {
//	if(A.size() != B.size() || (int)A.size() > SN) cout << "Citaj komenty pred copypastovanim, ty chudak!" << endl;
//	if(A.size() < 10) cout << "Fourierka na menej ako 10 cisel? Blbost si si vybral. ~-(_)-~" << endl;

	int Smin =1;
	while(Smin < (int)A.size()*2) Smin *=2;

	// init na omegy
	if(OM.empty()) {
		OM.resize(21);
		for(int i =0; i < 21; i++) {
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
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cat M, mod = 998244353;
	cin >> N >> M;
	N++;
	vector<ll> P0(N), fac(N, 1), inv(N, 1);
	for(int i = 0; i < N; i++) {
		cin >> P0[i];
		if(i < N-1) {
			fac[i+1] = (i+1) * fac[i] % mod;
			inv[i+1] = pw(fac[i+1], mod-2, mod);
		}
		P0[i] = P0[i] * fac[i] % mod;
	}
	reverse(begin(P0), end(P0));
	vector<ll> R0 = convolution(P0, inv);
	R0.resize(N);
	reverse(begin(R0), end(R0));
	for(int i = 0; i < N; i++) R0[i] = R0[i] * pw(i+1, mod-1-M%(mod-1), mod) % mod;
	reverse(begin(R0), end(R0));
	for(int i = 0; i < N; i++) if(i&1) inv[i] = (mod-inv[i]) % mod;
	vector<ll> P = convolution(R0, inv);
	for(int i = 0; i < N; i++) if(i&1) inv[i] = (mod-inv[i]) % mod;
	P.resize(N);
	reverse(begin(P), end(P));
	for(int i = 0; i < N; i++) P[i] = P[i] * inv[i] % mod;
	for(int i = 0; i < N; i++) cout << P[i] << ((i == N-1)?"\n":" ");
	return 0;}

// look at my code
// my code is amazing