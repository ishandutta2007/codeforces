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

int main() {
	int N,M;
	scanf(" %d %d",&N,&M);
	vector< vector<int> > G(N);
	for(int i =0; i < M; i++) {
		int a,b;
		scanf(" %d %d",&a,&b);
		G[--a].push_back(--b);
		G[b].push_back(a);}

	vector<int> ans(N,0);
	queue<int> q;
	for(int i =0; i < N; i++) {
		int zle =0;
		ALL_THE(G[i],it) if(ans[i] == ans[*it]) zle++;
		if(zle > 1) q.push(i);}

	while(!q.empty()) {
		int zle =0;
		ALL_THE(G[q.front()],it) if(ans[q.front()] == ans[*it]) zle++;
		if(zle > 1) {
			ans[q.front()] =1-ans[q.front()];
			ALL_THE(G[q.front()],it) q.push(*it);}
		q.pop();}

	for(int i =0; i < N; i++) printf("%d",ans[i]);
	printf("\n");
	return 0;}

// look at my code
// my code is amazing