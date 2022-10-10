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

void DFS(int R, vector< vector<int> > &G, vector<int> &par, vector<int> &dep) {
	ALL_THE(G[R],it) if(par[R] != *it) {
		par[*it] =R;
		dep[*it] =dep[R]+1;
		DFS(*it,G,par,dep);}
	}

int LCAd(int u, int v, vector< vector<int> > &par, vector<int> &dep) {
	if(dep[u] > dep[v]) swap(u,v);
	for(int k =19; k >= 0; k--) if(dep[par[k][v]] > dep[u]) v =par[k][v];
	if(par[0][v] == u) return v;
	if(dep[par[0][v]] == dep[u]) v =par[0][v];
	for(int k =19; k >= 0; k--) if(par[k][v] != par[k][u]) {
		v =par[k][v];
		u =par[k][u];}
	return par[0][v];}

int solve(int R, vector< vector<int> > &G, vector<int> &cov, vector<int> &par) {
	int x =0, ans =0;
	ALL_THE(G[R],it) if(*it != par[R]) {
		ans +=solve(*it,G,cov,par);
		x +=cov[*it];}
	if(cov[R]) return ans;
	if(R != 0 && cov[par[R]]) x++;
	if(x > 1) {
		ans++;
		x =0;}
	cov[R] =x;
	return ans;}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N,Q;
	cin >> N;
	vector< vector<int> > G(N);
	for(int i =0; i < N-1; i++) {
		int u,v;
		cin >> u >> v;
		G[--u].push_back(--v);
		G[v].push_back(u);}

	vector<int> dep(N,0);
	vector< vector<int> > par(20,vector<int>(N,-1));
	par[0][0] =0;
	DFS(0,G,par[0],dep);
	for(int k =1; k < 20; k++) for(int i =0; i < N; i++) 
		par[k][i] =par[k-1][par[k-1][i]];

	cin >> Q;
	int K =100;
	vector<int> cov(N,0);
	vector< vector<int> > ulca(N);
	for(int q =0; q < Q; q++) {
		int M;
		cin >> M;
		vector<int> V(M);
		for(int i =0; i < M; i++) {
			cin >> V[i];
			V[i]--;}
		if(M > K) {
			bool pos =true;
			ALL_THE(V,it) cov[*it] =1;
			ALL_THE(V,it) if(pos)
				ALL_THE(G[*it],jt) if(cov[*jt]) {pos =false; break;}
			if(!pos) cout << "-1\n";
			else cout << solve(0,G,cov,par[0]) << "\n";
			for(int i =0; i < N; i++) cov[i] =0;
			continue;}
		
		vector< pair<int,int> > dlca;
		bool pos =true;
		for(int i =0; i < M; i++) for(int j =i+1; j < M; j++) {
			int l =LCAd(V[i],V[j],par,dep);
			if(l == V[i] || l == V[j]) {pos =false; break;}
			dlca.push_back(make_pair(dep[l],l));
			if(dep[V[i]] > dep[l]) ulca[l].push_back(V[i]);
			if(dep[V[j]] > dep[l]) ulca[l].push_back(V[j]);}
		if(!pos) {cout << "-1\n"; continue;}
		sort(begin(dlca),end(dlca));

		ALL_THE(V,it) cov[*it] =1;
		int ans =0;
		for(int i =dlca.size()-1; i >= 0; i--) if(!cov[dlca[i].ss]) {
			int x =0;
			ALL_THE(ulca[dlca[i].ss],it) if(cov[*it] == 1) {
				x++;
				cov[*it] =2;}
			ALL_THE(ulca[dlca[i].ss],it) if(cov[*it] == 2) cov[*it] =1;
			if(dlca[i].ss != 0 && cov[par[0][dlca[i].ss]]) x++;
			if(x > 1) {
				ans++;
				ALL_THE(ulca[dlca[i].ss],it) cov[*it] =0;
				}
			}
		ALL_THE(dlca,it) ulca[it->ss].clear();
		ALL_THE(V,it) cov[*it] =0;
		cout << ans << "\n";}
	return 0;}

// look at my code
// my code is amazing