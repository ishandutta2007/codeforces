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

long long pw(long long a, long long e, long long mod) {
	if(e <= 0) return 1;
	long long x =pw(a,e/2,mod);
	x =(x*x)%mod;
	if(x < 0) x +=mod;
	if(e%2 != 0) x =(x*a)%mod;
	if(x < 0) x +=mod;
	return x;}

int mx =200000+tisic;
vector<long long> fac(mx,1),inv(mx,1);
long long mod =1000000007;

long long getC(int N, int K) {
	if(K < 0 || N < 0 || N-K < 0) return 0;
	long long ret =(inv[K]*inv[N-K])%mod;
	if(ret < 0) ret +=mod;
	ret =(ret*fac[N])%mod;
	if(ret < 0) ret +=mod;
	return ret;}

long long solve(int x, vector<long long> &ans, vector< pair<int,int> > &bl) {
	if(ans[x] != -1) return ans[x];
	int N =ans.size();
	ans[x] =getC(bl[x].ff+bl[x].ss,bl[x].ff); // nefailne
	for(int i =0; i < N; i++) if(i != x) // failne na tejto
		if(bl[i].ff <= bl[x].ff && bl[i].ss <= bl[x].ss)
			ans[x] =(ans[x]-solve(i,ans,bl)*getC(bl[x].ff+bl[x].ss-bl[i].ff-bl[i].ss,bl[x].ff-bl[i].ff))%mod;
	if(ans[x] < 0) ans[x] +=mod;
	return ans[x];}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int H,W,N;
	cin >> H >> W >> N;
	vector< pair<int,int> > bl(N);
	for(int i =0; i < N; i++) {
		cin >> bl[i].ff >> bl[i].ss;
		bl[i].ff--;
		bl[i].ss--;}
	for(int i =1; i < mx; i++) {
		fac[i] =(i*fac[i-1])%mod;
		if(fac[i] < 0) fac[i] +=mod;
		inv[i] =pw(fac[i],mod-2,mod);}
	
	vector<long long> ans(N,-1); // prva na ktorej failne
	long long ansF =getC(H+W-2,H-1);
	for(int i =0; i < N; i++) ansF =(ansF-solve(i,ans,bl)*getC(H+W-bl[i].ff-bl[i].ss-2,H-bl[i].ff-1))%mod;
	if(ansF < 0) ansF +=mod;
	cout << ansF << "\n";
	return 0;}

// look at my code
// my code is amazing