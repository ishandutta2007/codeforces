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
#include <time.h>
// mylittlepony
using namespace std;

int main() {
	cin.sync_with_stdio(0);

	long long mod =1000000007;
	int maxS =1000+tisic, maxK =50;
	vector< vector<long long> > C(maxS,vector<long long>(maxK,0));
	for(int i =0; i < maxS; i++) {
		C[i][0] =1;
		for(int j =1; j <= min(maxK-1,i); j++) C[i][j] =(C[i-1][j-1]+C[i-1][j])%mod;}

	vector< vector<long long> > P(maxK,vector<long long>(maxS,0));
	vector< vector<long long> > P0(maxS,vector<long long>(maxS,0)); // sucet i, max. cislo <= j
	// ako dosiahnut sucet i pomocou j scitancov
	for(int i =0; i < maxS; i++) P0[i][i] =1;
	for(int j =0; j < maxS; j++) for(int k =1; k < maxS; k++)
		P0[j][k] =(P0[j][k]+P0[j][k-1])%mod;
	for(int j =0; j < maxS; j++) P[1][j] =P0[j][maxS-1];
	for(int i =2; i < maxK; i++) {
		vector< vector<long long> > Pn(maxS,vector<long long>(maxS,0));
		for(int j =0; j < maxS; j++) for(int k =1; k <= j; k++)
			Pn[j][k] =(Pn[j][k]+P0[j-k][k-1])%mod;
		P0 =Pn;
		for(int j =0; j < maxS; j++) for(int k =1; k < maxS; k++)
			P0[j][k] =(P0[j][k]+P0[j][k-1])%mod;
		for(int j =0; j < maxS; j++) P[i][j] =P0[j][maxS-1];}

	vector<long long> fac(maxK+1,1);
	for(int i =1; i <= maxK; i++) fac[i] =(i*fac[i-1])%mod;

	int T; cin >> T;
	for(int t =0; t < T; t++) {
		int N,K;
		cin >> N >> K;
		if(K >= maxK) {cout << "0\n"; continue;}
		long long ans =0;
		for(int s =0; s < N; s++) ans =(ans+P[K][s]*C[N-s][K])%mod;
		cout << (ans*fac[K])%mod << "\n";}
	return 0;}

// look at my code
// my code is amazing