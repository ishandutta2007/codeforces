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

long long mod =1000000007;
long long fac[1000000];
long long facS[1000000];

long long pw(long long a, long long e) {
	if(e <= 0) return 1;
	long long x =pw(a,e/2);
	x =(x*x)%mod;
	if(e%2 != 0) x =(x*a)%mod;
	return x;}

long long cnt(long long K, long long N) {
	// sucin K+1..K+N-1
	if((K+N-1)%mod != (K%mod)+N-1) return 0;
	K =(K+1)%mod;
	long long ret =1;
	for(int i =0; i < N-1; i++) ret =(ret*(K+i))%mod;
	return ret;}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	fac[0] =1;
	for(int i =1; i < 1000000; i++) fac[i] =(i*fac[i-1])%mod;
/*	long long F =1;
	for(int i =0; i < mod; i++) {
		if(i%2000 == 0) facS[i/2000] =F;
		F =((i+1)*F)%mod;}
*/	int N;
	long long S, ans =0;
	cin >> N >> S;
	long long inv =pw(fac[N-1],mod-2);
	vector<long long> A(N);
	for(int i =0; i < N; i++) cin >> A[i];
	for(int i =0; i < (1<<N); i++) {
		long long s =0;
		int x =0;
		for(int j =0; j < N; j++) {
			s +=((i>>j)&1)*(A[j]+1);
			x +=(i>>j)&1;}
		if(s > S) continue;
		if(x%2 == 0) ans +=(inv*cnt(S-s,N))%mod;
		else ans -=(inv*cnt(S-s,N))%mod;}
	ans %=mod;
	if(ans < 0) ans +=mod;
	cout << ans << "\n";
	return 0;}

// look at my code
// my code is amazing