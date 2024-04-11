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

vector<long long> fac(300000,1),inv(300000,1);
long long ans =0, mod =1000000007;

long long getC(int N, int K) {
	if(K > N || K < 0 || N < 0) return 0;
	long long ret =(fac[N]*inv[K])%mod;
	ret =(ret*inv[N-K])%mod;
	if(ret < 0) ret +=mod;
	return ret;}

long long pw(long long a, long long e) {
	if(e <= 0) return 1;
	long long x =pw(a,e/2);
	x =(x*x)%mod;
	if(e%2 != 0) x =(x*a)%mod;
	if(x < 0) x +=mod;
	return x;}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int mx =1000000;
	vector<int> mind(mx+tisic,-1);
	vector< vector<int> > divs(mx+tisic,vector<int>(1,1));
	for(int i =1; i <= mx; i++) divs[i].dibs(100);
	for(int i =2; i <= mx; i++) {
		if(mind[i] == -1) for(int j =1; j <= mx/i; j++) mind[i*j] =i;
		for(int j =1; j <= mx/i; j++) divs[j*i].push_back(i);}
	for(int i =1; i < 300000; i++) {
		fac[i] =(i*fac[i-1])%mod;
		if(fac[i] < 0) fac[i] +=mod;
		inv[i] =pw(fac[i],mod-2);}

	int N,K,Q;
	scanf(" %d %d %d",&N,&K,&Q);
	vector<long long> cntd0(mx+tisic,0);
	vector<int> id(mx+tisic,0);
	for(int i =0; i < N; i++) {
		int a;
		scanf(" %d",&a);
		int D =divs[a].size();
		for(int i =0; i < D; i++) cntd0[divs[a][i]]++;
		}
	vector<long long> poc0(mx+tisic,0);
	for(int i =mx; i > 0; i--) {
		poc0[i] +=getC(cntd0[i],K);
		poc0[i] %=mod;
		if(poc0[i] < 0) poc0[i] +=mod;
		ans =(ans+i*poc0[i])%mod;
		int l =divs[i].size();
		for(int j =0; j < l-1; j++) poc0[divs[i][j]] -=poc0[i];
		}

	for(int i =0; i < Q; i++) {
		int a;
		scanf(" %d",&a);
		int D =divs[a].size();
		vector<long long> cntd(D,0),cntdk(D,0);
		for(int i =0; i < D; i++) {
			id[divs[a][i]] =i;
			cntd[i] =cntd0[divs[a][i]];
			cntdk[i] =getC(cntd[i],K-1);}
		vector<long long> poc(D,0);
		for(int i =D-1; i >= 0; i--) {
			poc[i] +=cntdk[i];
			poc[i] %=mod;
			if(poc[i] < 0) poc[i] +=mod;
			ans =(ans+divs[a][i]*poc[i])%mod;
			int x =divs[a][i], l =divs[x].size();
			for(int j =0; j < l-1; j++) poc[id[divs[x][j]]] -=poc[i];
			}
		for(int i =0; i < D; i++) cntd0[divs[a][i]]++;
		ans %=mod;
		if(ans < 0) ans +=mod;
		printf("%lld\n",ans);}
	return 0;}

// look at my code
// my code is amazing