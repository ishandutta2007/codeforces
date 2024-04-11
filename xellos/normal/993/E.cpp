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
#define abs(x) (((x) < 0)?-(x):(x))
#define uint unsigned int
#define dbl long double
#define pi 3.14159265358979323846
using namespace std;
// mylittledoge

using cat = long long;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

typedef unsigned long long ll;

ll MOD; // prime, MOD-1 divisible by a large power of 2

ll pw(ll a, ll e) {
	if(e <= 0) return 1;
	ll x =pw(a,e/2);
	x =(x*x)%MOD;
	if(e%2 != 0) x =(x*a)%MOD;
	return x;}

ll proot; // primitive MOD-1th root of unity %MOD
vector< vector<ll> > OM;

vector<ll> DFT(vector<ll> &A, int N, int d, int x, int dir) {
	vector<ll> ret(N,0);

	if(N == 1) {
		ret[0] =A[x];
		return ret;}
	if(N == 2) {
		ret[0] =(A[x]+A[x+d]);
		if(ret[0] >= MOD) ret[0] -= MOD;
		ret[1] =(A[x]+MOD-A[x+d]);
		if(ret[1] >= MOD) ret[1] -= MOD;
		return ret;}

	int dep =0, n =N;
	while(n > 1) {n /=2; dep++;}

	vector<ll> DFT0[2];
	DFT0[0] =DFT(A,N/2,d*2,x,dir);
	DFT0[1] =DFT(A,N/2,d*2,x+d,dir);
	for(int i =0; i < N/2; i++) {
		ll com =OM[dep][(i == 0) ? 0 : (dir == 1 ? i : (N-i))];
		ret[i] =(DFT0[0][i]+com*DFT0[1][i])%MOD;
		ret[i+N/2] =(DFT0[0][i]+(MOD-com)*DFT0[1][i])%MOD;}
	return ret;}

int SN =1<<19; // arbitrary power of 2 such that N <= SN

vector<ll> convolution(vector<ll> A, vector<ll> B) {

	int Smin =1;
	while(Smin < (int)A.size()*2) Smin *=2;

	// init na omegy
	if(OM.empty()) {
		OM.resize(20);
		for(int i =0; i < 20; i++) {
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
	int N, X;
	cin >> N >> X;
	vector<ll> A;
	ll cur = 1;
	for(int i = 0; i < N; i++) {
		int a;
		cin >> a;
		if(a < X) {
			A.push_back(cur);
			cur = 1;
		}
		else cur++;
	}
	A.push_back(cur);
	vector<ll> ans(N+1, 0);
	int n = (int)A.size()-1;
	vector<ll> B = A;
	reverse(begin(B), end(B));
	MOD = 4076863489LL;
	ll MOD0 = MOD;
	proot = 7;
	OM.clear();
	vector<ll> C1 = convolution(A, B);
	MOD = 998244353;
	proot = 3;
	OM.clear();
	vector<ll> C2 = convolution(A, B);
	for(int k = 1; k <= n; k++) {
		ans[k] = C1[n-k];
		while(ans[k] % MOD != C2[n-k] % MOD) ans[k] += MOD0;
	}
	for(int i = 0; i <= n; i++) ans[0] += A[i]*(A[i]-1)/2;
	for(int i = 0; i <= N; i++) cout << ans[i] << ((i == N) ? "\n" : " ");
	return 0;}

// look at my code
// my code is amazing