// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <vector>
#include <set>
#include <tr1/unordered_map>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#define dibs reserve
#define OVER9000 234567890
#define tisic 47
#define soclose 10e-7
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
// so much chocolate
#define ff first
#define ss second
#define uint unsigned int
// mylittlepony
using namespace std;

long long mod =1000000007;
long long Pow(long long a, long long e) {
	if(e == 0) return 1;
	long long x =(e%2 == 0)?Pow(a,e/2):Pow(a,e-1);
	x =(e%2 == 0)?(x*x)%mod:(x*a)%mod;
	if(x < 0) x +=mod;
	return x;}

int main() {
	int N,M,G;
	cin >> N >> M >> G;
	if(M == 0) {
		N =(int)(N%2 == 0);
		cout << (int)(N == G) << "\n";
		return 0;}
	if(M == 1) {
		int ans =0;
		for(int i =0; i <= N; i++) {
			// i nul, potom jednotka
			int x =i+1;
			if(i == N) x =i;
			if(G == (int)(x%2 == 0)) ans++;}
		cout << ans << "\n";
		return 0;}
	
	vector<long long> fac(300000+tisic,1);
	for(int i =0; i < 300000; i++) {
		fac[i+1] =(fac[i]*(i+1))%mod;
		if(fac[i+1] < 0) fac[i+1] +=mod;}

	long long ans =0;
	for(int i =G; i <= N; i +=2) {
		// i nul na zaciatku, potom 1, ostava M-1 jednotiek a N-i nul
		// C(M-1+N-i,M-1)
		long long f1 =fac[M-1+N-i];
		long long f2 =Pow(fac[M-1],mod-2);
		long long f3 =Pow(fac[N-i],mod-2);
		f3 =(f2*f3)%mod; if(f3 < 0) f3 +=mod;
		ans =(ans+f1*f3)%mod;
		if(ans < 0) ans +=mod;}
	cout << ans << "\n";
    return 0;}
        
// look at my code
// my code is amazing