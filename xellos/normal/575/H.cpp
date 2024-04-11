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
	if(x < 0) x +=mod;
	if(e%2 != 0) x =(x*a)%mod;
	if(x < 0) x +=mod;
	return x;}

long long mod =1000000007;
int mx =2000000;
vector<long long> fac(mx+tisic,1),inv(mx+tisic,1),inv_fac(mx+tisic,1);

long long getC(int N, int K) {
	if(K < 0 || K > N) return 0;
	long long ret =(inv_fac[K]*inv_fac[N-K])%mod;
	ret =(ret*fac[N])%mod;
	return ret;}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N;
	scanf(" %d",&N);
	for(int i =1; i <= 2*N+patkan; i++) {
		fac[i] =(i*fac[i-1])%mod;
		if(i%2 == 0 && i > 2) inv[i] =(inv[i/2]*inv[2])%mod;
		else inv[i] =pw(i,mod-2,mod);
		inv_fac[i] =(inv[i]*inv_fac[i-1])%mod;}

	long long ans =1;
	for(int i =0; i <= N; i++) ans =(ans*2)%mod;
	ans--;
	for(int x =1; x <= N; x++) {
		long long akt =((N+1)*getC(x+N+1,x)+(x-N-1)*getC(N+1,x))%mod;
		akt =(akt*inv[x+1])%mod;
		ans +=akt;}
	ans %=mod;
	if(ans < 0) ans +=mod;
	printf("%lld\n",ans);
	return 0;}

// look at my code
// my code is amazing