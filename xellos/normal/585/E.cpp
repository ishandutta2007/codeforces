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

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int mx =10000000;
	vector<int> minD(mx+tisic,0);
	for(int i =2; i <= mx; i++) if(minD[i] == 0) 
		for(int j =1; j <= mx/i; j++) minD[i*j] =i;

	int N;
	scanf(" %d",&N);
	vector<int> A(N);
	for(int i =0; i < N; i++) scanf(" %d",&A[i]);

	vector<int> poc(mx+tisic,0);
	for(int i =0; i < N; i++) poc[A[i]]++;
	vector<int> pocD(mx+tisic,0);
	for(int i =1; i <= mx; i++)
		for(int j =1; j <= mx/i; j++) pocD[i] +=poc[i*j];

	long long mod =1000000007;
	vector<int> pw2(N+tisic,1);
	for(int i =0; i < N; i++) {
		pw2[i+1] =2*pw2[i];
		if(pw2[i+1] >= mod) pw2[i+1] -=mod;}

	vector<int> pocGCD(mx+tisic,0);
	for(int i =mx; i >= 1; i--) {
		pocGCD[i] =pw2[pocD[i]]-1;
		for(int j =2; j <= mx/i; j++) {
			pocGCD[i] -=pocGCD[i*j];
			if(pocGCD[i] < 0) pocGCD[i] +=mod;}
		}

	vector<int> prod(1<<10,1), sgn(1<<10,1), prD;
	for(int i =0; i < (1<<10); i++) {
		int x =0;
		for(int j =0; j < 10; j++) x +=(i>>j)&1;
		if(x%2 != 0) sgn[i] =-1;}
	long long ans =0;
	for(int i =2; i <= mx; i++) if(pocGCD[i] > 0) {
		int x =i;
		while(x > 1) {
			int p =minD[x];
			while(x%p == 0) x /=p;
			prD.push_back(p);}
		int copr =N;
		int b =0;
		for(int j =0; j < (1<<prD.size()); j++) {
			while((1<<b) <= j) b++;
			for(int k =b; k < (int)prD.size(); k++) prod[j|(1<<k)] =prod[j]*prD[k];
			if(j > 0) copr +=sgn[j]*pocD[prod[j]];}
		prD.clear();
		ans =(ans+1LL*copr*pocGCD[i])%mod;}

	if(ans < 0) ans +=mod;
	printf("%lld\n",ans);
	return 0;}

// look at my code
// my code is amazing