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

long long mod =1000000007;

struct fin {
	vector<long long> T;
	fin(int N) {T.resize(N+tisic,0);}

	int lastone(int x) {return x&(x^(x-1));}

	void put(int pos, long long val) {
		for(int i =pos+1; i < (int)T.size(); i +=lastone(i)) {
			T[i] +=val;
			if(T[i] >= mod) T[i] -=mod;}
		}

	long long get(int pos) {
		long long ret =0;
		for(int i =pos+1; i > 0; i -=lastone(i)) {
			ret +=T[i];
			if(ret >= mod) ret -=mod;}
		return ret;}
	};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N,K;
	long long L;
	scanf(" %d %lld %d",&N,&L,&K);
	vector<int> A(N);
	map<int,int> M;
	for(int i =0; i < N; i++) {
		scanf(" %d",&A[i]);
		M[A[i]]++;}

	int m =0;
	ALL_THE(M,it) it->ss =m++;
	for(int i =0; i < N; i++) A[i] =M[A[i]];

	fin F(m);
	F.put(0,1);
	long long ans =0;
	for(long long k =0; k < min(K*1LL,L/N); k++) {
		vector<long long> V(N);
		for(int i =0; i < N; i++) {
			V[i] =F.get(A[i]);
			ans =(ans+(L/N-k)%mod*V[i])%mod;
			if(ans < 0) ans +=mod;}
		for(int i =0; i < (int)F.T.size(); i++) F.T[i] =0;
		for(int i =0; i < N; i++) F.put(A[i],V[i]);}

	if(L%N != 0) {
		fin F2(m);
		for(int i =0; i < L%N; i++) {
			F2.put(m-A[i],1);
			ans++;}
		if(ans >= mod) ans -=mod;
		for(long long k =L/N-1; k >= max(0LL,L/N-K+1); k--) {
			vector<long long> V(N);
			for(int i =0; i < N; i++) {
				V[i] =F2.get(m-A[i]);
				ans +=V[i];
				if(ans >= mod) ans -=mod;}
			for(int i =0; i < (int)F2.T.size(); i++) F2.T[i] =0;
			for(int i =0; i < N; i++) F2.put(m-A[i],V[i]);}
		}

	printf("%lld\n",ans);
	return 0;}

// look at my code
// my code is amazing