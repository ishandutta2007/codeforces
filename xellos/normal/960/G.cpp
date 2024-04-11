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
		ll com =OM[dep][(N+(1LL*dir*i)%N)&(N-1)];
		ret[i] =(DFT0[0][i]+com*DFT0[1][i])%MOD;
		ret[i+N/2] =(DFT0[0][i]+(MOD-com)*DFT0[1][i])%MOD;}
	return ret;}

int SN =1<<18; // arbitrary power of 2 such that N <= SN

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

vector<ll> stirl_poly(int L, int R, int K) {
	if(L+100 >= R) {
		vector<ll> ret(1, 1);
		for(int i = L; i < R; i++) {
			ret.push_back(0);
			for(int j = ret.size()-1; j >= 0; j--) {
				ret[j] *= i;
				if(j > 0) ret[j] += ret[j-1];
				ret[j] %= MOD;
			}
			if((int)ret.size() > K+1) ret.resize(K+1);
		}
		return ret;
	}
	int C = (L+R)/2;
	vector<ll> P = stirl_poly(L, C, K), Q = stirl_poly(C, R, K);
	int sz = max(P.size(), Q.size()), szsum = (int)P.size() + (int)Q.size() - 1;
	P.resize(sz, 0);
	Q.resize(sz, 0);
	vector<ll> ret = convolution(P, Q);
	ret.resize(szsum);
	if((int)ret.size() > K+1) ret.resize(K+1);
	return ret;
}

cat fac(int N) {
	cat ret = 1;
	for(int i = 1; i <= N; i++) ret = ret * i % MOD;
	return ret;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N, A, B;
	cin >> N >> A >> B;
	if(A == 0 || B == 0 || A+B-1 > N) {
		cout << "0\n";
		return 0;
	}
	A--, B--, N--;
	cat ans = stirl_poly(0, N, A+B)[A+B] * fac(A+B) % MOD * pw(fac(A) * fac(B) % MOD, MOD-2) % MOD;
	if(ans < 0) ans += MOD;
	cout << ans << "\n";
	return 0;}

// look at my code
// my code is amazing