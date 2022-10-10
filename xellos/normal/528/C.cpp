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
#define dibs reserve
#define OVER9000 1234567890
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-5
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
#define dbl long double
#define pi 3.14159265359
using namespace std;
// mylittledoge

vector<int> sol;
set<int> del;

void DFS(int R, vector< vector< pair<int,int> > > &G) {
	while(!G[R].empty()) {
		int x =G[R].rbegin()->ff, y =G[R].rbegin()->ss;
		G[R].pop_back();
		if(del.find(y) != del.end()) continue;
		del.insert(y);
		DFS(x,G);}
	sol.push_back(R);}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N,M;
	cin >> N >> M;
	vector< vector< pair<int,int> > > G(N);
	for(int i =0; i < M; i++) {
		int a,b;
		cin >> a >> b;
		a--, b--;
		G[b].push_back(make_pair(a,i));
		G[a].push_back(make_pair(b,i));}

	vector<int> odd;
	for(int i =0; i < N; i++) if(G[i].size()%2 != 0)
		odd.push_back(i);
	for(int i =0; i < (int)odd.size(); i +=2) {
		G[odd[i+1]].push_back(make_pair(odd[i],M));
		G[odd[i]].push_back(make_pair(odd[i+1],M));
		M++;}
	if(M%2 != 0) {
		G[0].push_back(make_pair(0,M));
		G[0].push_back(make_pair(0,M));
		M++;}

	DFS(0,G);

	cout << M << "\n";
	for(uint i =1; i < sol.size(); i++) {
		if(i%2 == 0) cout << sol[i-1]+1 << " " << sol[i]+1 << "\n";
		else cout << sol[i]+1 << " " << sol[i-1]+1 << "\n";}
	return 0;}

// look at my code
// my code is amazing