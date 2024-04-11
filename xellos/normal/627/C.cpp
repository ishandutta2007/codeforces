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
	long long D,B;
	int N;
	scanf(" %lld %lld %d",&D,&B,&N);
	vector< pair<long long,long long> > st(N);
	for(int i =0; i < N; i++) scanf(" %lld %lld",&st[i].ss,&st[i].ff);
	sort(begin(st),end(st));
	map<long long,long long> M; // velkost tanku
	M[0] =B;
	M[D] =0;
	long long cost =0;

	vector<long long> pos(1,0);
	pos.push_back(D);
	ALL_THE(st,it) pos.push_back(it->ss);
	sort(begin(pos),end(pos));
	for(int i =1; i < (int)pos.size(); i++) if(pos[i]-pos[i-1] > B) {
		printf("-1\n");
		return 0;} 

	for(int i =0; i < N; i++) {
		auto it =M.lower_bound(st[i].ss);
		auto jt =it; jt--;
		if(jt->ss >= it->ff-jt->ff) continue;
		long long in =max(0LL,jt->ff+jt->ss-st[i].ss);
		long long out =min(B,it->ff-st[i].ss);
		cost +=max(0LL,out-in)*st[i].ff;
		M[st[i].ss] =max(in,out);}

	printf("%lld\n",cost);
	return 0;}

// look at my code
// my code is amazing