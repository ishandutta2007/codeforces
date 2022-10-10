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

void DFS(int R, vector< vector< pair<int,int> > > &G, vector<int> &par, vector<int> &dep) {
	ALL_THE(G[R],it) if(par[it->ff] == -1) {
		par[it->ff] =R;
		dep[it->ff] =dep[R]+1;
		DFS(it->ff,G,par,dep);}
	}

void DFS2(int R, int par, vector< vector< pair<int,int> > > &G, vector<int> &poc) {
	ALL_THE(G[R],it) if(it->ff != par) {
		DFS2(it->ff,R,G,poc);
		poc[R] +=poc[it->ff];}
	}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N;
	scanf(" %d",&N);
	vector< vector< pair<int,int> > > G(N);
	for(int i =0; i < N-1; i++) {
		int a,b,x;
		scanf(" %d %d %d",&a,&b,&x);
		G[--a].push_back(make_pair(--b,0));
		G[b].push_back(make_pair(a,x));}

	vector< vector<int> > par(18,vector<int>(N,-1));
	par[0][0] =0;
	vector<int> dep(N,0);
	DFS(0,G,par[0],dep);
	for(int i =1; i < 18; i++) for(int j =0; j < N; j++) par[i][j] =par[i-1][par[i-1][j]];

	int Q;
	scanf(" %d",&Q);
	vector<int> V(Q+1,0);
	for(int i =0; i < Q; i++) {
		scanf(" %d",&V[i+1]);
		V[i+1]--;}

	vector<int> poc_up(N,0),poc_dn(N,0);

	for(int q =0; q < Q; q++) {
		int u =V[q], v =V[q+1];
		if(dep[u] > dep[v]) swap(u,v);
		for(int k =17; k >= 0; k--) 
			if(dep[par[k][v]] >= dep[u]) v =par[k][v];

		for(int k =17; k >= 0; k--)
			if(par[k][v] != par[k][u]) {
				u =par[k][u];
				v =par[k][v];}
		if(u != v) {
			u =par[0][u];
			v =par[0][v];}

		poc_up[V[q]]++;
		poc_up[u]--;
		poc_dn[V[q+1]]++;
		poc_dn[u]--;}

	DFS2(0,0,G,poc_up);
	DFS2(0,0,G,poc_dn);

	long long mod =1000000007;
	vector<long long> pw(Q+tisic,1);
	for(int i =1; i <= Q; i++) {
		pw[i] =(pw[i-1]*2)%mod;
		if(pw[i] < 0) pw[i] +=mod;}

	long long ans =0;
	for(int i =0; i < N; i++) ALL_THE(G[i],it) if(it->ss == 1) {
		if(par[0][i] == it->ff) ans +=pw[poc_up[i]]-1;
		else ans +=pw[poc_dn[it->ff]]-1;}

	ans %=mod;
	if(ans < 0) ans +=mod;
	printf("%lld\n",ans);
	return 0;}

// look at my code
// my code is amazing