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

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

typedef long long ll;

ll mod =1000000007, mod2 =5*mod*mod;
vector<ll> fac(100000,1),inv(100000,1),pw2(100000,1);

ll pw(ll a, ll e) {
	if(e == 0) return 1;
	ll x =pw(a,e/2);
	x =(x*x)%mod;
	if(e%2 != 0) x =(x*a)%mod;
	return x;}

vector<ll> multiply(vector<ll> &A, vector<ll> &B, int z, int k) {
	int N =k-z;
	ll sumA =0, sumB =0;
	for(int i =z; i < k; i++) sumA +=A[i];
	for(int i =z; i < k; i++) sumB +=B[i];
	if(sumA == 0 || sumB == 0) return vector<ll>(2*N-1,0);
	vector<ll> ret(2*N-1,0);
	if(N <= 100) {
		vector<ll> ret0(2*N-1,0);
		for(int j =0; j < N; j++) if(B[j+z] != 0) for(int i =0; i < N; i++) {
			ret0[i+j] +=1LL*A[i+z]*B[j+z];
			if(ret0[i+j] >= mod2) ret0[i+j] -=mod2;}
		for(int i =0; i < 2*N-1; i++) {
			ret[i] =ret0[i]%mod;
			if(ret[i] < 0) ret[i] +=mod;}
		return ret;}

	vector<ll> A2(N-N/2),B2(N-N/2);
	for(int i =N/2; i < N; i++) A2[i-N/2] =A[i+z], B2[i-N/2] =B[i+z];
	vector<ll> ret1 =multiply(A,B,z,z+N/2), ret2 =multiply(A,B,z+N/2,k);
	for(int i =0; i < N/2; i++) {
		A2[i] +=A[i+z];
		if(A2[i] >= mod) A2[i] -=mod;
		B2[i] +=B[i+z];
		if(B2[i] >= mod) B2[i] -=mod;}
	
	vector<ll> ret3 =multiply(A2,B2,0,A2.size());
	for(int i =0; i < 2*(N/2)-1; i++) {
		ret3[i] -=ret1[i];
		if(ret3[i] < 0) ret3[i] +=mod;}
	for(int i =0; i < 2*(N-N/2)-1; i++) {
		ret3[i] -=ret2[i];
		if(ret3[i] < 0) ret3[i] +=mod;}

	for(int i =0; i < 2*(N/2)-1; i++) ret[i] =ret1[i];
	for(int i =2*(N/2); i < 2*N-1; i++) {
		ret[i] +=ret2[i-2*(N/2)];
		if(ret[i] >= mod) ret[i] -=mod;}
	for(int i =N/2; i < 2*N-N/2-1; i++) {
		ret[i] +=ret3[i-N/2];
		if(ret[i] >= mod) ret[i] -=mod;}
	return ret;}

vector<ll> solve(int N, int K) {
	vector<ll> ret(K+1,0);
	if(N == 0) {
		ret[0] =1;
		return ret;}
	if(N%2 != 0) {
		vector<ll> v =solve(N-1,K);
		vector<ll> A(K+1,0),B(K+1,0);
		for(int i =0; i <= K; i++) {
			A[i] =((pw2[i]*v[i])%mod*inv[i])%mod;
			if(A[i] < 0) A[i] +=mod;
			B[i] =inv[i];
			if(B[i] < 0) B[i] +=mod;}
		ret =multiply(A,B,0,K+1);
		ret.resize(K+1,0);
		for(int i =0; i <= K; i++) {
			ret[i] =((ret[i]-A[i]*B[0])%mod*fac[i])%mod;
			if(ret[i] < 0) ret[i] +=mod;}
		return ret;}
	vector<ll> v =solve(N/2,K);
	vector<ll> A(K+1,0),B(K+1,0);
	ll p =1;
	for(int i =0; i <= K; i++) {
		A[i] =((v[i]*inv[i])%mod*p)%mod;
		B[i] =(v[i]*inv[i])%mod;
		if(A[i] < 0) A[i] +=mod;
		if(B[i] < 0) B[i] +=mod;
		p =(pw2[N/2]*p)%mod;}
	ret =multiply(A,B,0,K+1);
	ret.resize(K+1,0);
	for(int i =0; i <= K; i++) {
		ret[i] =((ret[i]-A[i]*B[0])%mod*fac[i])%mod;
		if(ret[i] < 0) ret[i] +=mod;}
	return ret;}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	ll N;
	int K;
	cin >> N >> K;
	if(N > K) {cout << "0\n"; return 0;}
	for(int i =1; i <= K; i++) {
		fac[i] =(i*fac[i-1])%mod;
		inv[i] =pw(fac[i],mod-2);
		pw2[i] =(2*pw2[i-1])%mod;}
	vector<ll> v =solve(N,K);
	long long ans =0;
	for(int i =N; i <= K; i++) ans =(ans+(v[i]*inv[i])%mod*inv[K-i])%mod;
	ans =(ans*fac[K])%mod;
	if(ans < 0) ans +=mod;
	cout << ans << "\n";
	return 0;}

// look at my code
// my code is amazing