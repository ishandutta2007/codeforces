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

typedef unsigned long long ull;

int main() {
	int N,M;
	scanf(" %d %d",&N,&M);
	ull mod =1000000007;

	vector< vector<int> > C(2*N+M+tisic,vector<int>(2*N+tisic,0));
	for(int i =0; i <= 2*N+M; i++) {
		C[i][0] =1;
		for(int j =1; j <= min(2*N,i); j++) {
			C[i][j] =C[i-1][j-1]+C[i-1][j];
			if(C[i][j] >= mod) C[i][j] -=mod;}
		}

	vector< vector<int> > poc2(N+1,vector<int>(M+1,0));
	for(int j =1; j <= M; j++) poc2[0][j] =1;
	for(int i =1; i <= N; i++) for(int j =1; j <= M; j++) 
		poc2[i][j] =C[2*i+j-1][2*i];

	vector< vector<int> > poc2s =poc2;
	for(int i =1; i <= N; i++) for(int j =0; j <= M; j++) {
		poc2s[i][j] +=poc2s[i-1][j];
		if(poc2s[i][j] >= mod) poc2s[i][j] -=mod;}

	vector< vector<int> > poc2ss =poc2s;
	for(int i =0; i <= N; i++) for(int j =1; j <= M; j++) {
		poc2ss[i][j] +=poc2ss[i][j-1];
		if(poc2ss[i][j] >= mod) poc2ss[i][j] -=mod;}

	vector< vector<ull> > poc3(N+1,vector<ull>(M+1,0));
	for(int i =0; i <= N; i++) {
		for(int j =0; j <= M; j++) poc3[i][j] =(1ULL*j*poc2s[i][j])%mod;
		for(int j =1; j <= M; j++) poc3[i][j] =(poc3[i][j]+poc3[i][j-1])%mod;}

	vector< vector<ull> > poc3s(N+1,vector<ull>(M+1,0));
	for(int i =0; i <= N; i++) for(int j =1; j <= M; j++)
		poc3s[i][j] =(1ULL*(j+1)*poc2ss[i][j-1]+mod-poc3[i][j-1])%mod;

	ull ans =0;
	for(int i =1; i <= M; i++) for(int j =0; j < N; j++) {
		ull akt =1+((j == N-1)?0:poc3s[N-2-j][i]);
		akt =(poc2s[j][i]*akt)%mod;
		ans +=((M-i)*akt)%mod;}
	ans %=mod;
	printf("%I64u\n",ans);
	return 0;}

// look at my code
// my code is amazing