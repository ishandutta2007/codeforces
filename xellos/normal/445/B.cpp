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

void DFS(int R, vector< vector<int> > &G, vector<bool> &vis) {
	ALL_THE(G[R],it) if(!vis[*it]) {
		vis[*it] =true;
		DFS(*it,G,vis);}
	}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N,M;
	scanf(" %d %d",&N,&M);
	vector< vector<int> > G(N);
	for(int i =0; i < M; i++) {
		int a,b;
		scanf(" %d %d",&a,&b);
		G[--a].push_back(--b);
		G[b].push_back(a);}

	vector<bool> vis(N,false);
	int C =0;
	for(int i =0; i < N; i++) if(!vis[i]) {
		vis[i] =true;
		DFS(i,G,vis);
		C++;}

	printf("%lld\n",1LL<<(N-C));
	return 0;}

// look at my code
// my code is amazing