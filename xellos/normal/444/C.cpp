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

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

struct fin_range {
	vector<long long> T,Tc;
	fin_range(int N) {
		T.resize(N+tisic,0); 
		Tc.resize(N+tisic,0);}

	int lastone(int x) {return x&(x^(x-1));}

	void put(int zac, int kon, long long val) { // [zac..kon) +=val
		for(int i =zac+1; i < (int)T.size(); i +=lastone(i)) T[i] +=val;
		for(int i =kon+1; i < (int)T.size(); i +=lastone(i)) T[i] -=val;
		for(int i =kon+1; i < (int)Tc.size(); i +=lastone(i)) Tc[i] +=val*kon;
		for(int i =zac+1; i < (int)Tc.size(); i +=lastone(i)) Tc[i] -=val*zac;
		}

	long long get(int pos) {
		long long ret =0;
		for(int i =pos+1; i > 0; i -=lastone(i)) ret +=T[i];
		ret *=(pos+1);
		for(int i =pos+1; i > 0; i -=lastone(i)) ret +=Tc[i];
		return ret;}
	};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N,M;
	scanf(" %d %d",&N,&M);
	map<int, pair<int,int> > I;
	fin_range F(N);

	for(int i =0; i < N; i++) I[i] =make_pair(i+1,i+1);

	for(int i =0; i < M; i++) {
		int tp,l,r;
		scanf(" %d %d %d",&tp,&l,&r);
		l--;
		if(tp == 2) {
			printf("%lld\n",F.get(r-1)-F.get(l-1));
			continue;}
		int x;
		scanf(" %d",&x);
		auto it =I.lower_bound(l);
		while(it != I.end() && it->ss.ff <= r) {
			int d =abs(x-it->ss.ss);
			F.put(it->ff,it->ss.ff,d);
			auto jt =it;
			it++;
			I.erase(jt);}
		// pravy
		if(it != I.end() && it->ff < r) {
			I[r] =it->ss;
			int d =abs(x-it->ss.ss);
			F.put(it->ff,r,d);
			I.erase(it);}
		// lavy
		it =I.lower_bound(l);
		if(it != I.begin() && (it == I.end() || it->ff != l)) {
			it--;
			int d =abs(x-it->ss.ss);
			if(it->ss.ff > r) {
				F.put(l,r,d);
				I[r] =it->ss;}
			else F.put(l,it->ss.ff,d);
			it->ss.ff =l;}
		// novy
		I[l] =make_pair(r,x);}
	return 0;}

// look at my code
// my code is amazing