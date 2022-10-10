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

void DFS(int R, vector< vector<int> > &G, vector<int> &dep, vector< vector<int> > &par) {
	ALL_THE(G[R],it) if(dep[*it] == -1) {
		dep[*it] =dep[R]+1;
		par[0][*it] =R;
		DFS(*it,G,dep,par);}
	}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N,M,Q;
	scanf(" %d %d %d",&N,&M,&Q);
	vector< vector<int> > G(N);
	for(int i =1; i < N; i++) {
		int a,b;
		scanf(" %d %d",&a,&b);
		G[--a].push_back(--b);
		G[b].push_back(a);}

	vector<int> dep(N,-1);
	vector< vector<int> > par(18,vector<int>(N));
	par[0][0] =0;
	DFS(0,G,dep,par);

	vector< vector< vector<int> > > min10(18,vector< vector<int> >(N));
	for(int i =0; i < M; i++) {
		int c;
		scanf(" %d",&c);
		c--;
		if((int)min10[0][c].size() >= 10) continue;
		min10[0][c].push_back(i);}

	for(int i =1; i < 18; i++) for(int j =0; j < N; j++) if(dep[j]+1 >= (1<<i)) {
		par[i][j] =par[i-1][par[i-1][j]];
		int a =0, b =0, p =par[i-1][j], l =0;
		min10[i][j].dibs(10);
		while(a < (int)min10[i-1][j].size() && b < (int)min10[i-1][p].size() && l < 10) {
			if(min10[i-1][j][a] < min10[i-1][p][b]) {
				min10[i][j].push_back(min10[i-1][j][a]);
				a++, l++;}
			else {
				min10[i][j].push_back(min10[i-1][p][b]);
				b++, l++;}
			}
		while(a < (int)min10[i-1][j].size() && l < 10) {
			min10[i][j].push_back(min10[i-1][j][a]);
			a++, l++;}
		while(b < (int)min10[i-1][p].size() && l < 10) {
			min10[i][j].push_back(min10[i-1][p][b]);
			b++, l++;}
		}

	for(int q =0; q < Q; q++) {
		int u,v,A;
		scanf(" %d %d %d",&u,&v,&A);
		u--, v--;
		vector<int> ans;
		if(dep[u] > dep[v]) swap(u,v);
		for(int k =17; k >= 0; k--) if(dep[par[k][v]] >= dep[u] && dep[v] >= (1<<k)+dep[u]) {
			vector<int> ans_nw;
			int a =0, b =0, l =0;
			while(a < (int)min10[k][v].size() && b < (int)ans.size() && l < A) {
				if(min10[k][v][a] < ans[b]) {
					ans_nw.push_back(min10[k][v][a]);
					a++, l++;}
				else {
					ans_nw.push_back(ans[b]);
					b++, l++;}
				}
			while(a < (int)min10[k][v].size() && l < A) {
				ans_nw.push_back(min10[k][v][a]);
				a++, l++;}
			while(b < (int)ans.size() && l < A) {
				ans_nw.push_back(ans[b]);
				b++, l++;}
			ans =ans_nw;
			v =par[k][v];}

		if(u != v) for(int k =17; k >= 0; k--) if(par[k][v] != par[k][u]) {
			vector<int> ans_nw;
			int a =0, b =0, c =0, l =0;
			while(a < (int)min10[k][v].size() && b < (int)ans.size() && c < (int)min10[k][u].size() && l < A) {
				if(min10[k][v][a] > ans[b] && min10[k][u][c] > ans[b]) {
					ans_nw.push_back(ans[b]);
					b++, l++;}
				else if(min10[k][v][a] < min10[k][u][c]) {
					ans_nw.push_back(min10[k][v][a]);
					a++, l++;}
				else {
					ans_nw.push_back(min10[k][u][c]);
					c++, l++;}
				}
			if(c == min10[k][u].size())
			while(a < (int)min10[k][v].size() && b < (int)ans.size() && l < A) {
				if(min10[k][v][a] > ans[b]) {
					ans_nw.push_back(ans[b]);
					b++, l++;}
				else {
					ans_nw.push_back(min10[k][v][a]);
					a++, l++;}
				}
			else if(a == min10[k][v].size())
			while(b < (int)ans.size() && c < (int)min10[k][u].size() && l < A) {
				if(min10[k][u][c] > ans[b]) {
					ans_nw.push_back(ans[b]);
					b++, l++;}
				else {
					ans_nw.push_back(min10[k][u][c]);
					c++, l++;}
				}
			else if(b == ans.size())
			while(a < (int)min10[k][v].size() && c < (int)min10[k][u].size() && l < A) {
				if(min10[k][v][a] < min10[k][u][c]) {
					ans_nw.push_back(min10[k][v][a]);
					a++, l++;}
				else {
					ans_nw.push_back(min10[k][u][c]);
					c++, l++;}
				}
			while(a < (int)min10[k][v].size() && l < A) {
				ans_nw.push_back(min10[k][v][a]);
				a++, l++;}
			while(b < (int)ans.size() && l < A) {
				ans_nw.push_back(ans[b]);
				b++, l++;}
			while(c < (int)min10[k][u].size() && l < A) {
				ans_nw.push_back(min10[k][u][c]);
				c++, l++;}
			ans =ans_nw;
			u =par[k][u];
			v =par[k][v];}
		int lca =v;
		if(v != u) lca =par[0][lca];
		while(true) {
			vector<int> ans_nw;
			int a =0, b =0, l =0;
			while(a < (int)min10[0][v].size() && b < (int)ans.size() && l < A) {
				if(min10[0][v][a] < ans[b]) {
					ans_nw.push_back(min10[0][v][a]);
					a++, l++;}
				else {
					ans_nw.push_back(ans[b]);
					b++, l++;}
				}
			while(a < (int)min10[0][v].size() && l < A) {
				ans_nw.push_back(min10[0][v][a]);
				a++, l++;}
			while(b < (int)ans.size() && l < A) {
				ans_nw.push_back(ans[b]);
				b++, l++;}
			ans =ans_nw;
			if(v == lca) break;
			v =par[0][v];}
		swap(v,u);
		while(true) {
			if(v == lca) break;
			vector<int> ans_nw;
			int a =0, b =0, l =0;
			while(a < (int)min10[0][v].size() && b < (int)ans.size() && l < A) {
				if(min10[0][v][a] < ans[b]) {
					ans_nw.push_back(min10[0][v][a]);
					a++, l++;}
				else {
					ans_nw.push_back(ans[b]);
					b++, l++;}
				}
			while(a < (int)min10[0][v].size() && l < A) {
				ans_nw.push_back(min10[0][v][a]);
				a++, l++;}
			while(b < (int)ans.size() && l < A) {
				ans_nw.push_back(ans[b]);
				b++, l++;}
			ans =ans_nw;
			v =par[0][v];}

		printf("%d",(int)ans.size());
		ALL_THE(ans,it) printf(" %d",*it+1);
		printf("\n");}
	return 0;}

// look at my code
// my code is amazing