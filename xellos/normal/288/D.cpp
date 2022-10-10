// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <tr1/unordered_map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
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
#define dbl double
using namespace std;
using namespace std::tr1;
// mylittledoge

void DFS(int R, vector< vector<int> > &G, vector<int> &S, vector<int> &par) {
	S[R] =1;
	ALL_THE(G[R],it) if(par[*it] == -1) {
		par[*it] =R;
		DFS(*it,G,S,par);
		S[R] +=S[*it];}
	}

int main() {
	int N;
	scanf(" %d",&N);
	vector< vector<int> > G(N);
	for(int i =0; i < N-1; i++) {
		int a,b;
		scanf(" %d %d",&a,&b);
		G[--a].push_back(--b);
		G[b].push_back(a);}

	vector<int> S(N),par(N,-1);
	par[0] =0;
	DFS(0,G,S,par);

	vector<long long> cezV(N,0);
	for(int i =0; i < N; i++) {
		cezV[i] =1LL*N*(N-1)/2;
		ALL_THE(G[i],it) if(par[*it] == i) cezV[i] -=1LL*S[*it]*(S[*it]-1)/2;
		if(i > 0) cezV[i] -=1LL*(N-S[i])*(N-S[i]-1)/2;}

	long long ans =0;
	for(int i =1; i < N; i++) {
		// pocet ciest prechadzajucich hornym
		long long p =cezV[par[i]];
		p -=1LL*S[i]*(N-S[i]);
		ans +=p*S[i]*(S[i]-1)/2;
		// dolnym
		p =cezV[i];
		p -=1LL*S[i]*(N-S[i]);
		ans +=p*(N-S[i])*(N-S[i]-1)/2;}

	printf("%I64d\n",ans);
	return 0;}

// look at my code
// my code is amazing