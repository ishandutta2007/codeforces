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
using namespace std;
// mylittledoge

long long cpw(long long a, long long e, long long mod) {
	if(e <= 0) return 1;
	long long x =cpw(a,e/2,mod);
	x =(x*x)%mod;
	if(x < 0) x +=mod;
	if(e%2 != 0) x =(x*a)%mod;
	if(x < 0) x +=mod;
	return x;}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N,K;
	string s;
	cin >> N >> K >> s;
	long long ans =0, mod =1000000007;
	if(K == 0) {
		for(int i =0; i < N; i++) ans =(ans*10+s[i]-'0')%mod;
		if(ans < 0) ans +=mod;
		cout << ans << "\n";
		return 0;}
	vector< vector<int> > P(10,vector<int>(N,0));
	for(int i =0; i < N; i++) P[s[i]-'0'][N-i-1]++;

	vector<long long> pw(N+1,1),fac(N+1,1),iF(N+1,1);
	for(int i =0; i < N; i++) {
		pw[i+1] =(pw[i]*10)%mod;
		fac[i+1] =(fac[i]*(i+1))%mod;
		iF[i+1] =cpw(fac[i+1],mod-2,mod);}

	for(int d =1; d < 10; d++) {
		int s =0;
		for(int i =N-1; i >= 0; i--) {
			// pocet sposobov ako medzi N-1-i miest rozdelit K-1 plusiek * s
			if(N-2-i >= 0 && N-1-i-K >= 0) {
				long long x =(fac[N-2-i]*iF[K-1])%mod;
				if(x < 0) x +=mod;
				x =(x*iF[N-1-i-K])%mod;
				if(x < 0) x +=mod;
				x =(x*s)%mod;
				if(x < 0) x +=mod;
				x =(x*pw[i])%mod;
				if(x < 0) x +=mod;
				ans =(ans+x*d)%mod;}
			// pocet sposobov ako medzi N-1-i rozdelit K plusiek * P[d][i]
			if(N-1-i >= 0 && N-1-i-K >= 0) {
				long long x =(fac[N-1-i]*iF[K])%mod;
				x =(x*iF[N-1-i-K])%mod;
				if(x < 0) x +=mod;
				x =(x*P[d][i])%mod;
				if(x < 0) x +=mod;
				x =(x*pw[i])%mod;
				if(x < 0) x +=mod;
				ans =(ans+x*d)%mod;}
			s +=P[d][i];}
		}

	if(ans < 0) ans +=mod;
	cout << ans << "\n";
	return 0;}

// look at my code
// my code is amazing