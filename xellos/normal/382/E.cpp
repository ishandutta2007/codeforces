// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <iomanip>
#define dibs reserve
#define OVER9000 1234567890
#define patkan 9
#define tisic 47
#define soclose 1e-9
#define pi 3.1415926535898
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):(x))
#define uint unsigned int
// mylittledoge
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N,K;
	cin >> N >> K;
	long long mod =1000000007;
	vector< vector<long long> > A[2];
	for(int i =0; i < 2; i++) A[i].resize(N+1,vector<long long>(K+1,0));
	vector< vector<long long> > C(N+1,vector<long long>(N+1,0));
	for(int i =0; i <= N; i++) {
		C[i][0] =1;
		for(int j =1; j <= i; j++) {
			C[i][j] =(C[i-1][j]+C[i-1][j-1])%mod;
			if(C[i][j] < 0) C[i][j] +=mod;}
		}

	A[0][0][0] =1;
	for(int i =1; i <= N; i++) for(int j =0; j <= K; j++) for(int l =0; 2*l <= i-1; l++) {
		long long x =((l > 0)?((i-1)*(i-2)/((2*l == i-1)?2:1)*C[i-3][l-1]):max(1,i-1))%mod;
		if(x < 0) x +=mod;
		for(int k =0; k <= j; k++) {
			long long y =(A[0][l][k]*A[0][i-1-l][j-k])%mod;
			if(y < 0) y +=mod;
			A[1][i][j] +=(y*x)%mod;}
		A[1][i][j] %=mod;
		if(A[1][i][j] < 0) A[1][i][j] +=mod;
		for(int k =0; k < j; k++) {
			long long y =((A[0][l][k]+A[1][l][k])*A[1][i-1-l][j-1-k]+A[1][l][k]*A[0][i-1-l][j-1-k])%mod;
			if(y < 0) y +=mod;
			A[0][i][j] +=(y*x)%mod;}
		A[0][i][j] %=mod;
		if(A[0][i][j] < 0) A[0][i][j] +=mod;}

	cout << (A[0][N][K]+A[1][N][K])%mod << "\n";
	return 0;}

// look at my code
// my code is amazing