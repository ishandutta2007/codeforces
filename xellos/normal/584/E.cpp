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

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N;
	scanf(" %d",&N);
	vector<int> P(N),Q(N),pos_fin(N);
	for(int i =0; i < N; i++) {
		scanf(" %d",&P[i]);
		P[i]--;}
	for(int i =0; i < N; i++) {
		scanf(" %d",&Q[i]);
		Q[i]--;
		pos_fin[Q[i]] =i;}

	set<int> mv_lft, mv_rt;
	for(int i =0; i < N; i++) if(pos_fin[P[i]] != i) {
		if(pos_fin[P[i]] > i) mv_rt.insert(i);
		else mv_lft.insert(i);}

	int ans =0;
	vector< pair<int,int> > ans_op;
	while(!mv_lft.empty()) {
		auto it =mv_lft.begin();
		auto jt =mv_rt.lower_bound(*it); jt--;
		int x =*it, y =*jt;
		ans +=x-y;
		ans_op.push_back(make_pair(x,y));
		swap(P[x],P[y]);
		mv_lft.erase(it);
		mv_rt.erase(jt);
		if(pos_fin[P[x]] > x) mv_rt.insert(x);
		if(pos_fin[P[y]] < y) mv_lft.insert(y);}
	printf("%d\n%d\n",ans,(int)ans_op.size());
	ALL_THE(ans_op,it) printf("%d %d\n",it->ff+1,it->ss+1);
	return 0;}

// look at my code
// my code is amazing