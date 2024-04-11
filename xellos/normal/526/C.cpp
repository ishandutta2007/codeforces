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
#define dbl long double
using namespace std;
using namespace std::tr1;
// mylittledoge

long long gcd(long long a, long long b) {
	if(a >= b) swap(a,b);
	return (a == 0)?b:gcd(b%a,a);}

long long pw(long long a, long long e, long long mod) {
	if(e <= 0) return 1;
	long long x =pw(a,e/2,mod);
	x =(x*x)%mod;
	if(x < 0) x +=mod;
	if(e%2 != 0) x =(x*a)%mod;
	if(x < 0) x +=mod;
	return x;}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	long long C;
	long long H[2];
	long long W[2];
	cin >> C >> H[0] >> H[1] >> W[0] >> W[1];
	long long g =gcd(W[0],W[1]);
	C /=g;
	W[0] /=g, W[1] /=g;

//	male W[0]/W[1]: vsetky D
//	velke W[0],W[1]: malo cukrikov

	if(W[0] > W[1]) {
		swap(W[0],W[1]);
		swap(H[0],H[1]);}

	long long phi[2];
	for(int k =0; k < 2; k++) {
		long long x =W[k];
		phi[k] =W[k];
		for(long long i =2; i*i <= x; i++) if(x%i == 0) {
			phi[k] /=i;
			phi[k] *=i-1;
			while(x%i == 0) x /=i;}
		if(x > 1) {phi[k] /=x; phi[k] *=x-1;}
		}

	if(W[0] <= 100000) {
		long long ans =0;
		for(long long c =C; c >= max(0LL,C-W[0]); c--) {
			// c == a*W[0]+b*W[1]
//			H[0]*a+H[1]*b == (H[0]*W[1]-W[0]*H[1])/W[1]*a+H[1]*c/W[1]
			// max. a?
			// c*invW[1]%W[0] == b
			long long bmin =(c*pw(W[1],phi[0]-1,W[0]))%W[0];
			if(bmin < 0) {cout << "NOOOO\n"; return 0;}
			if(bmin*W[1] <= c) {
				long long a =(c-bmin*W[1])/W[0];
				ans =max(ans,a*H[0]+bmin*H[1]);}
			long long amin =(c*pw(W[0],phi[1]-1,W[1]))%W[1];
			if(amin < 0) {cout << "NOOOO\n"; return 0;}
			if(amin*W[0] <= c) {
				long long b =(c-amin*W[0])/W[1];
				ans =max(ans,amin*H[0]+b*H[1]);}
			}
		cout << ans << "\n";
		return 0;}

	long long ans =0;
	for(int i =0; i <= C/W[0]; i++) {
		long long b =(C-W[0]*i)/W[1];
		ans =max(ans,b*H[1]+i*H[0]);}
	cout << ans << "\n";
	return 0;}

// look at my code
// my code is amazing