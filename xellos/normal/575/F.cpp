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

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N,x;
	scanf(" %d %d",&N,&x);
	set<int> pos;
	pos.insert(x);
	vector< pair<int,int> > I(N);
	for(int i =0; i < N; i++) {
		scanf(" %d %d",&I[i].ff,&I[i].ss);
		pos.insert(I[i].ff);
		pos.insert(I[i].ss);}

	vector<int> posv;
	ALL_THE(pos,it) posv.push_back(*it);
	int M =posv.size();

	vector<long long> ans(M,OVER9000);
	for(int i =0; i < M; i++) if(posv[i] == x) ans[i] =0;
	for(int i =0; i < N; i++) {
		vector<long long> ans_nw =ans;
		long long x =OVER9000;
		for(int j =0; j < M; j++) {
			x =min(x,ans[j]-posv[j]);
			ans_nw[j] =min(ans_nw[j],posv[j]+x);}
		x =OVER9000;
		for(int j =M-1; j >= 0; j--) {
			x =min(x,ans[j]+posv[j]);
			ans_nw[j] =min(ans_nw[j],-posv[j]+x);}
		for(int j =0; j < M; j++) {
			ans[j] =ans_nw[j];
			if(posv[j] > I[i].ss) ans[j] +=posv[j]-I[i].ss;
			if(posv[j] < I[i].ff) ans[j] +=I[i].ff-posv[j];}
		}

	long long ansF =OVER9000;
	for(int i =0; i < M; i++) ansF =min(ansF,ans[i]);
	printf("%lld\n",ansF);
	return 0;}

// look at my code
// my code is amazing