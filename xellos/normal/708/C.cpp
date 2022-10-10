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

void DFS(int R, vector< vector<int> > &G, vector<int> &S, vector<int> &par) {
	ALL_THE(G[R],it) if(par[*it] == -1) {
		par[*it] =R;
		DFS(*it,G,S,par);
		S[R] +=S[*it];}
	}

void DFS2(int R, vector< vector<int> > &G, vector<int> &S, vector<int> &par, vector<int> &top) {
	ALL_THE(G[R],it) if(par[*it] == -1) {
		par[*it] =R;
		if(par[R] != R) top[*it] =top[R];
		DFS2(*it,G,S,par,top);
		S[R] +=S[*it];}
	}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cin >> N;
	if(N == 1) {cout << "1\n"; return 0;}
	vector< vector<int> > G(N);
	for(int i =0; i < N-1; i++) {
		int a,b;
		cin >> a >> b;
		G[--a].push_back(--b);
		G[b].push_back(a);}
	vector<int> S(N,1),par(N,-1);
	par[0] =0;
	DFS(0,G,S,par);

	// dva?
	for(int i =0; i < N; i++) if(S[i]*2 == N) {
		for(int j =0; j < N; j++) cout << 1 << ((j == N-1)?"\n":" ");
		return 0;}

	int c =0;
	for(int i =0; i < N; i++) if(S[i]*2 > N) {
		bool isc =true;
		ALL_THE(G[i],it) if(par[*it] == i && S[*it]*2 > N) isc =false;
		if(isc) c =i;}
	
	par.clear(); par.resize(N,-1);
	par[c] =c;
	S.clear(); S.resize(N,1);
	vector<int> top(N,c);
	ALL_THE(G[c],it) top[*it] =*it;
	DFS2(c,G,S,par,top);

	vector<int> ans(N,0);
	ans[c] =1;
	multiset<int> Ss;
	ALL_THE(G[c],it) Ss.insert(S[*it]);
	for(int i =0; i < N; i++) if(i != c) {
		Ss.erase(Ss.find(S[top[i]]));
		if((N-S[i]-*Ss.rbegin())*2 <= N) ans[i] =1;
		Ss.insert(S[top[i]]);}

	for(int j =0; j < N; j++) cout << ans[j] << ((j == N-1)?"\n":" ");
	return 0;}

// look at my code
// my code is amazing