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
#define soclose 1e-5
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

int main() {
	unsigned long long mod =777777777;
	unsigned long long mod2 =15*mod*mod;
	vector< vector<unsigned long long> > C(500,vector<unsigned long long>(500,0));
	for(int i =0; i < 500; i++) {
		C[i][0] =1;
		for(int j =1; j <= i; j++) {
			C[i][j] =C[i-1][j]+C[i-1][j-1];
			if(C[i][j] >= mod) C[i][j] -=mod;}
		}

	int K,N;
	scanf(" %d %d",&N,&K);

	vector< vector<unsigned long long> > pos(N+1,vector<unsigned long long>(N-K+1,0));
	pos[N][N-K] =1;
	for(int i =N-1; i >= 0; i--) for(int j =0; j <= N-K; j++) if(pos[i+1][j]) {
		pos[i][j] =1;
		if(j >= i+1) pos[i][j-i-1] =1;}

	vector< vector< vector<unsigned long long> > > poc(N+1,vector< vector<unsigned long long> >(N+1,vector<unsigned long long>(N-K+1,0)));
	poc[0][0][0] =1;
	for(int i =1; i <= N; i++) for(int j =0; j <= N; j++) for(int k =max(0,j-K); k <= min(min(j,i*(i+1)/2),N-K); k++) if(pos[i][k]) {
		for(int l =k; l <= j; l++) {
			poc[i][j][k] +=poc[i-1][l][k]*C[N-l][N-j];
			if(poc[i][j][k]&9223372036854775808) poc[i][j][k] -=mod2;}
		if(j >= i) poc[i][j][k] +=mod*mod-poc[i-1][j-i][k]*C[N-j+i][i];
		if(k >= i) poc[i][j][k] +=poc[i-1][j-i][k-i]*C[N-j+i][i];
		poc[i][j][k] %=mod;
		}

	if(poc[N][N][N-K] < 0) poc[N][N][N-K] +=mod;
	printf("%I64d\n",poc[N][N][N-K]);
	return 0;}

// look at my code
// my code is amazing