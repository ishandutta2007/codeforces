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
#define OVER9000 1234567890123456789LL
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
#define dbl double
using namespace std;
using namespace std::tr1;
// mylittledoge

long long gcd(long long a, long long b) {
	if(a > b) swap(a,b);
	return (a == 0)?b:gcd(b%a,a);}

long long lcm(long long a, long long b, long long mx) {
	long long d =gcd(a,b);
	if(a/d > mx/b) return -1;
	return a*(b/d);}

long long xmpr(long long a, long long b, long long mod) {
	// mod <= ~10**12
	long long q =a%1000000, r =a/1000000;
	long long h =b%1000000, k =b/1000000;
	long long ret =(q*h+(r*h+q*k)%mod*1000000)%mod;
	ret =(ret+(1000000000000LL*r)%mod*k%mod)%mod;
	return ret;}

long long pw(long long a, long long e, long long mod) {
	if(e <= 0) return 1;
	long long x =pw(a,e/2,mod);
	x =xmpr(x,x,mod);
	if(e%2 != 0) x =xmpr(x,a,mod);
	return x;}

int main() {
	long long N,M;
	int K;
	scanf(" %lld %lld %d",&N,&M,&K);
	vector<long long> V(K);
	for(int i =0; i < K; i++) scanf(" %lld",&V[i]);

	long long R =1;
	for(int i =0; i < K; i++) if(R != -1) R =lcm(R,V[i],N);
	if(R == -1) {cout << "NO\n"; return 0;}
	vector< pair<long long,long long> > p;
	long long r =R;
	for(int i =2; i <= 1000000; i++) if(r%i == 0) {
		int x =0;
		while(r%i == 0) {x++; r /=i;}
		p.push_back(make_pair(i,x));}
	if(r > 1) p.push_back(make_pair(r,1));

	vector< pair<long long, pair<long long,long long> > > rem;
	ALL_THE(p,it) {
		long long maxdiv =1, r =1;
		for(int i =0; i < K; i++) {
			long long curdiv =1, v =V[i];
			while(v%it->ff == 0) {
				v /=it->ff; 
				curdiv *=it->ff;}
			maxdiv =max(maxdiv,curdiv);
			if(maxdiv == curdiv) r =(V[i]-i)%maxdiv;}
		if(r < 0) r +=maxdiv;
		long long mmaxdiv =1;
		for(int i =0; i < it->ss; i++) mmaxdiv *=it->ff;
		if(maxdiv != mmaxdiv) {
			if(r%(maxdiv*it->ff) == 0) r +=maxdiv;
			maxdiv *=it->ff;}
		rem.push_back(make_pair(r,make_pair(it->ff,maxdiv)));}

	int E =rem.size();
	long long C =0, prod =1;
	for(int i =0; i < E; i++) prod *=rem[i].ss.ss;
	for(int i =0; i < E; i++) {
		long long a =(prod/rem[i].ss.ss)%rem[i].ss.ss;
		long long b =1;
		if(rem[i].ss.ss != 1)
			b =pw(a,rem[i].ss.ss/(rem[i].ss.ff)*(rem[i].ss.ff-1)-1,rem[i].ss.ss);
		b *=prod/rem[i].ss.ss;
		C =(C+xmpr(b,rem[i].ff,prod))%prod;}
	if(C <= 0) C +=prod;
//	cout << R << " R\n" << C << " C\n";

	if(C+K-1 > M) {cout << "NO\n"; return 0;}
	for(int i =0; i < K; i++)
		if(gcd(C+i,R) != V[i]) {cout << "NO\n"; return 0;}
	cout << "YES\n";
	return 0;}

// look at my code
// my code is amazing