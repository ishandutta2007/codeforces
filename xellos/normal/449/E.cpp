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
#define OVER9000 1234567890123456780LL
#define patkan 9
#define tisic 47
#define soclose 1e-7
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

int gcd(int x, int y) {
	if(x > y) swap(x,y);
	while(x > 0) {
		int z =y%x;
		y =x;
		x =z;}
	return y;}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	long long mod =1000000007;

	vector<long long> S[8];
	for(int i =1; i < 8; i++) {
		S[i].resize(1000000+tisic,0);
		for(int j =1; j <= 1000000; j++) {
			long long a =1;
			for(int k =0; k < i; k++) {
				a =(a*j)%mod;
				if(a < 0) a +=mod;}
			S[i][j] =(S[i][j-1]+a)%mod;}
		}

	vector<long long> phi(1000000+tisic,1);
	for(int i =2; i <= 1000000; i++) {
		if(phi[i] == 1) {
			phi[i] =i-1;
			for(int k =2; k <= 1000000/i; k++) phi[k*i] =0;}
		else for(int k =2; k <= i; k++) if(i%k == 0) {
			if((i/k)%k == 0) phi[i] =phi[i/k]*k;
			else phi[i] =phi[i/k]*(k-1);
			break;}
		}

	vector<long long> D(1000000+tisic,0);
	for(int i =1; i <= 1000000; i++) {
		for(int k =1; k <= 1000000/i; k++) D[k*i] +=(k*phi[i])%mod;
		D[i] %=mod;
		if(D[i] < 0) D[i] +=mod;}

	vector<long long> Sd3(1000000+tisic,0);
	for(int i =1; i <= 1000000; i++) Sd3[i] =(Sd3[i-1]+2*D[i])%mod;
	vector<long long> Sd2(1000000+tisic,0);
	for(int i =1; i <= 1000000; i++) Sd2[i] =(Sd2[i-1]+2*D[i]*i)%mod;
	vector<long long> Sd1(1000000+tisic,0);
	for(int i =1; i <= 1000000; i++) Sd1[i] =(Sd1[i-1]+2*D[i]*((1LL*i*i)%mod))%mod;

	long long inv3 =333333336;

	for(int t =0; t < T; t++) {
		int N,M;
		cin >> N >> M;
		if(M < N) swap(M,N);

		long long c2 =N+M+2, c3 =(1LL*(N+1)*(M+1))%mod;

		long long ans =(c3*(S[1][N]-S[3][N])+S[3][N]-S[5][N]-c2*(S[2][N]-S[4][N]))%mod;
		if(ans < 0) ans +=mod;
		ans =(ans*inv3+c3*(S[3][N]-2*S[2][N])+S[5][N]-2*S[4][N]-c2*(S[4][N]-2*S[3][N]))%mod;
		ans =(ans+c3*Sd3[N]-c2*Sd2[N]+Sd1[N])%mod;
		if(ans < 0) ans +=mod;
		cout << ans << "\n";}
	return 0;}

// look at my code
// my code is amazing