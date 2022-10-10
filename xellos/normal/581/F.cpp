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

vector< vector<int> > ans[2];
int DFS(int R, int par, vector< vector<int> > &G) {
	bool leaf =true;
	int ret =0; // number of leaves
	ans[0][R][0] =ans[1][R][0] =0;
	ALL_THE(G[R],it) if(par != *it) {
		leaf =false;
		int l_akt =DFS(*it,R,G);
		for(int k =0; k < 2; k++) {
			vector<int> ans_nw(ret+l_akt+1,G.size()+1);
			for(int l =0; l < 2; l++)
				for(int i =ret; i >= 0; i--) for(int j =l_akt; j >= 0; j--)
					ans_nw[i+j] =min(ans_nw[i+j],ans[k][R][i]+ans[l][*it][j]+abs(k-l));
			for(int i =0; i <= ret+l_akt; i++) ans[k][R][i] =ans_nw[i];}
		ret +=l_akt;}
	if(leaf) {
		ret++;
		ans[1][R][0] =G.size()+1;
		ans[1][R][1] =0;}
	return ret;}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N;
	scanf(" %d",&N);
	if(N == 2) {printf("1\n"); return 0;}

	vector< vector<int> > G(N);
	for(int i =0; i < N-1; i++) {
		int a,b;
		scanf(" %d %d",&a,&b);
		G[--a].push_back(--b);
		G[b].push_back(a);}
	
	int R =0;
	for(int i =0; i < N; i++) if((int)G[i].size() > 1) R =i;
	for(int i =0; i < 2; i++) ans[i].resize(N,vector<int>(N+1,N+1));
	int leaves =DFS(R,R,G);
	printf("%d\n",min(ans[0][R][leaves/2],ans[1][R][leaves/2]));
	return 0;}

// look at my code
// my code is amazing