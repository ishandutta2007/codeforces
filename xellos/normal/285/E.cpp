// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <tr1/unordered_map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
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
#define dbl double
using namespace std;
using namespace std::tr1;
// mylittledoge

long long pw(long long a, long long e, long long mod) {
	if(e <= 0) return 1;
	long long x =pw(a,e/2,mod);
	x =(x*x)%mod;
	if(e%2 != 0) x =(x*a)%mod;
	return x;}

int main() {
	int N,K;
	scanf(" %d %d",&N,&K);
	vector< vector<long long> > P0[4];
	for(int i =0; i < 4; i++) P0[i].resize(N+1,vector<long long>(N+1,0));
	P0[0][0][0] =1;
	long long mod =1000000007;
	for(int i =0; i < N; i++) for(int j =0; j <= N; j++) for(int k =0; k < 4; k++) {
		// nedam i+1,i-1
		P0[k/2][i+1][j] +=P0[k][i][j];
		if(P0[k/2][i+1][j] >= mod) P0[k/2][i+1][j] -=mod;
		if(j == N) continue;
		// dam i-1
		if(i > 0) {
			if(k%2 != 1) P0[k/2][i+1][j+1] +=P0[k][i][j];
			if(P0[k/2][i+1][j+1] >= mod) P0[k/2][i+1][j+1] -=mod;}
		// dam i+1
		if(i < N-1) {
			P0[k/2+2][i+1][j+1] +=P0[k][i][j];
			if(P0[k/2+2][i+1][j+1] >= mod) P0[k/2+2][i+1][j+1] -=mod;}
		}

	vector<long long> fac(N+1,1);
	for(int i =1; i <= N; i++) fac[i] =(i*fac[i-1])%mod;

	vector< vector<long long> > C(N+1,vector<long long>(N+1,0));
	for(int i =0; i <= N; i++) {
		C[i][0] =1;
		for(int j =1; j <= i; j++) {
			C[i][j] =C[i-1][j-1]+C[i-1][j];
			if(C[i][j] >= mod) C[i][j] -=mod;}
		}

	vector<long long> plusK(N+1,0);
	for(int i =0; i < 4; i++) for(int j =0; j <= N; j++) 
		plusK[j] =(plusK[j]+fac[N-j]*P0[i][N][j])%mod;

	vector<long long> ans(N+1,0);
	for(int j =N; j >= 0; j--) {
		ans[j] =plusK[j];
		for(int i =j+1; i <= N; i++) ans[j] =(ans[j]-ans[i]*C[i][j])%mod;}

	if(ans[K] < 0) ans[K] +=mod;
	printf("%I64d\n",ans[K]);
	return 0;}

// look at my code
// my code is amazing