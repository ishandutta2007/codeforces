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

int gcd(int x, int y) {
	if(x > y) swap(x,y);
	return (x == 0)?y:gcd(y%x,x);}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N;
	scanf(" %d",&N);
	vector<int> A(N);
	for(int i =0; i < N; i++) scanf(" %d",&A[i]);
	long long ans =0;

	vector< vector<int> > cnt_maxl; // pre dane g vo svojom ringu najvacsie, maxl[g][i] >= s
	map<int,int> Mg;
	for(int g =1; g <= N; g++) if(N%g == 0) {
		vector<int> mx(g,0);
		for(int i =0; i < N; i++) mx[i%g] =max(mx[i%g],A[i]);
		vector<int> pos(N,false);
		for(int i =0; i < N; i++) if(mx[i%g] == A[i]) pos[i] =true;
		vector<int> maxl(N,0);
		int l =0;
		for(int i =0; i < N; i++) {
			if(pos[i]) l++;
			else l =0;}
		if(l == N) for(int i =0; i < N; i++) maxl[i] =N;
		else for(int i =0; i < N; i++) {
			if(pos[i]) l++;
			else l =0;
			maxl[i] =l;}
		vector<int> poc(N+1,0);
		for(int i =0; i < N; i++) poc[maxl[i]]++;
		for(int i =N-1; i >= 0; i--) poc[i] +=poc[i+1];
		Mg[g] =cnt_maxl.size();
		cnt_maxl.push_back(poc);}

	for(int s =1; s < N; s++) {
		int g =gcd(s,N);
//		cout << s << " " << cnt_maxl[Mg[g]][s] << "\n";
		ans +=cnt_maxl[Mg[g]][s];}

	printf("%lld\n",ans);
	return 0;}

// look at my code
// my code is amazing