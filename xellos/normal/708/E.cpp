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

long long pw(long long a, long long e, long long mod) {
	if(e <= 0) return 1;
	long long x =pw(a,e/2,mod);
	x =(x*x)%mod;
	if(e%2 != 0) x =(x*a)%mod;
	return x;}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);

	long long mod =1000000007;
	vector<long long> fac(100000+tisic,1),inv(100000+tisic,1);
	for(int i =1; i <= 100000; i++) {
		fac[i] =(i*fac[i-1])%mod;
		inv[i] =pw(fac[i],mod-2,mod);}

	int N,M,K;
	cin >> N >> M;
	long long a,b;
	cin >> a >> b >> K;
	long long pb =(a*pw(b,mod-2,mod))%mod; if(pb < 0) pb +=mod;
	long long ps =(1-pb)%mod; if(ps < 0) ps +=mod;

	vector<long long> A(M+1,0);
	if(a == b) {
		if(K < M) A[K] =1;}
	else {
		vector<long long> ppb(100000+tisic,1),pps(100000+tisic,1);
		for(int i =1; i <= 100000; i++) {
			ppb[i] =(pb*ppb[i-1])%mod;
			pps[i] =(ps*pps[i-1])%mod;}
		for(int i =0; i <= M; i++) if(i <= K) {
			A[i] =(ppb[i]*pps[K-i])%mod;
			A[i] =(A[i]*fac[K])%mod;
			A[i] =((A[i]*inv[i])%mod*inv[K-i])%mod;}
		}

	vector<long long> As =A;
	for(int i =1; i <= M; i++) As[i] =(As[i-1]+As[i])%mod;

	vector< vector<long long> > S(N+1,vector<long long>(M+1,0));
	S[0][M] =1;
	for(int k =0; k < N; k++) {
		long long x =0;
		for(int j =0; j < M; j++) {
			x =(x+S[k][j]*A[j])%mod;
			S[k+1][j+1] =((S[k][M]-S[k][M-1-j])%mod*As[j]-x)%mod;
			S[k+1][j+1] =(A[M-1-j]*S[k+1][j+1])%mod;
			}
		for(int j =0; j < M; j++) S[k+1][j+1] =(S[k+1][j+1]+S[k+1][j])%mod;
		}
	long long ans =S[N][M];
	if(ans < 0) ans +=mod;
	cout << ans << "\n";

	return 0;}

// look at my code
// my code is amazing