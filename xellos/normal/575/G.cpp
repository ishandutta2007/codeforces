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
	int N,M;
	scanf(" %d %d",&N,&M);
	vector< vector< pair<int,int> > > G(N);
	for(int i =0; i < M; i++) {
		int a,b,c;
		scanf(" %d %d %d",&a,&b,&c);
		G[a].push_back(make_pair(b,c));
		G[b].push_back(make_pair(a,c));}

	vector<int> dst0(N,-1),dst(N,-1);
	dst0[N-1] =0;
	queue<int> q;
	q.push(N-1);
	vector<int> ako(N,-1);
	ako[N-1] =N-1;
	while(!q.empty()) {
		ALL_THE(G[q.front()],it) if(it->ss == 0 && dst0[it->ff] == -1) {
			ako[it->ff] =q.front();
			dst0[it->ff] =dst0[q.front()]+1;
			q.push(it->ff);}
		q.pop();}

	dst[0] =0;
	q.push(0);
	while(!q.empty()) {
		ALL_THE(G[q.front()],it) if(dst[it->ff] == -1) {
			dst[it->ff] =dst[q.front()]+1;
			q.push(it->ff);}
		q.pop();}

	int opt_dig =N+tisic;
	for(int i =0; i < N; i++) if(dst0[i] != -1) opt_dig =min(opt_dig,dst[i]);
	
	vector< vector<int> > by_dst(N+tisic);
	for(int i =0; i < N; i++) if(dst[i] != -1 && dst[i] <= opt_dig)
		if(dst[i] != opt_dig || dst0[i] != -1) by_dst[dst[i]].push_back(i);

	string ans;
	for(int i =opt_dig; i > 0; i--) {
		int d =10;
		ALL_THE(by_dst[i],it) if(ako[*it] != -1)
			ALL_THE(G[*it],jt) if(dst[jt->ff] == i-1) d =min(d,jt->ss);
		ans +=('0'+d);
		ALL_THE(by_dst[i],it) if(ako[*it] != -1)
			ALL_THE(G[*it],jt) if(dst[jt->ff] == i-1 && jt->ss == d) 
				if(dst0[jt->ff] == -1 || dst0[jt->ff] > dst0[*it]) {
					dst0[jt->ff] =dst0[*it];
					ako[jt->ff] =*it;}
		}

	if(ans.empty()) ans ="0";
	cout << ans << "\n" << opt_dig+dst0[0]+1 << "\n";
	int x =0;
	while(true) {
		cout << x;
		if(x == N-1) {cout << "\n"; return 0;}
		cout << " ";
		x =ako[x];}
	return 0;}

// look at my code
// my code is amazing