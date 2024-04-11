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
#define soclose 1e-10
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

void DFS(int R, int par, vector< vector<int> > &G, vector<int> &ans0, vector<int> &ans1) {
	int s =0;
	vector<int> dif;
	ALL_THE(G[R],it) if(*it != par) {
		DFS(*it,R,G,ans0,ans1);
		s +=ans0[*it];
		dif.push_back(ans1[*it]-ans0[*it]);}
	ans0[R] =ans1[R] =s+1;
	sort(begin(dif),end(dif));
	if(!dif.empty()) {
		ans1[R] =min(ans1[R],s+dif[0]);
		ans0[R] =min(ans0[R],s+dif[0]);}
	if(dif.size() > 1) 
		ans0[R] =min(ans0[R],s+dif[0]+dif[1]-1);
	}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N,X,Y;
	cin >> N >> X >> Y;
	if(N == 1) {cout << "0\n"; return 0;}
	vector< vector<int> > G(N);
	for(int i =0; i < N-1; i++) {
		int a,b;
		cin >> a >> b;
		G[--a].push_back(--b);
		G[b].push_back(a);}

	if(X > Y) {
		bool star =false;
		for(int i =0; i < N; i++) if(G[i].size() == N-1) star =true;
		if(star) cout << 1LL*Y*(N-2)+X << "\n";
		else cout << 1LL*Y*(N-1) << "\n";
		return 0;}

	vector<int> ans0(N,N+1),ans1(N,N+1);
	DFS(0,0,G,ans0,ans1);
	int p =min(ans0[0],ans1[0]);
	cout << 1LL*(p-1)*Y+1LL*(N-p)*X << "\n";
	return 0;}

// look at my code
// my code is amazing