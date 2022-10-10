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
#define OVER9000 1234567890123456789LL
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

pair<long long,long long> bezout(long long a, long long b) {
	// a*ret.ff-b*ret.ss == +-1
	if(a == 1 && b == 0) return make_pair(1,0);
	if(a == 0 && b == 1) return make_pair(0,1);
	bool rev =false;
	if(a > b) {swap(a,b); rev =true;}

	long long c =b/a;
	// a*p.ff-(b-a*c)*p.ss == +-1
	pair<long long,long long> p =bezout(a,b-a*c);
	// a*(p.ff+c*p.ss)-b*p.ss == +-1
	// ret.ff == p.ff+c*p.ss
	// p.ff < b-a*c, p.ss < a: ret.ss = p.ss < a, ret.ff = p.ff+c*p.ss < b+(p.ss-a)*c < b OK
	pair<long long,long long> ret =p;
	ret.ff +=c*p.ss;

	if(rev) swap(ret.ff,ret.ss);
	return ret;}

long long gcd(long long a, long long b) {
	if(a > b) swap(a,b);
	return (a == 0)?b:gcd(b%a,a);}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	long long x,y;
	scanf(" %lld %lld",&x,&y);
	long long x0 =x, y0 =y;
	if(gcd(x,y) != 1) {printf("Impossible\n"); return 0;}

	pair<long long,long long> p =bezout(x,y);
	swap(p.ff,p.ss);
	pair<long long,long long> r =make_pair(x-p.ff,y-p.ss);
//	printf("%lld %lld %lld %lld\n",p.ff,p.ss,r.ff,r.ss);

	vector< pair<int,long long> > ans0;
	while(p.ff+p.ss > 1 || r.ff+r.ss > 1) {
		if(p.ff >= r.ff && p.ss >= r.ss) {
			long long d =min((r.ff == 0)?OVER9000:(p.ff/r.ff),(r.ss == 0)?OVER9000:(p.ss/r.ss));
			ans0.push_back(make_pair(0,d));
			p.ff -=d*r.ff;
			p.ss -=d*r.ss;}
		else {
			long long d =min((p.ff == 0)?OVER9000:(r.ff/p.ff),(p.ss == 0)?OVER9000:(r.ss/p.ss));
			ans0.push_back(make_pair(1,d));
			r.ff -=d*p.ff;
			r.ss -=d*p.ss;}
		}
	bool rev =0;
	if(r.ff*p.ss-p.ff*r.ss == 1) rev =1;

	string ans;
	vector< pair<int,long long> > W =ans0;
	for(int i =ans0.size()-1; i >= 0; i--) {
		string num;
		while(ans0[i].ss > 0) {
			num +=('0'+ans0[i].ss%10);
			ans0[i].ss /=10;}
		reverse(begin(num),end(num));
		ans +=num;
		if(ans0[i].ff^rev) ans +="A";
		else ans +="B";}
	printf("%s\n",ans.c_str());
	return 0;}

// look at my code
// my code is amazing