// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <iomanip>
#define dibs reserve
#define OVER9000 1034567890
#define patkan 9
#define tisic 47
#define soclose 1e-9
#define pi 3.1415926535898
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):(x))
#define uint unsigned int
// mylittlepony
using namespace std;

int N,M;
vector< vector<int> > G,hore;
vector<int> par,dep;
vector<int> ans[3]; 

void DFS(int R) {
	ALL_THE(G[R],it) {
		if(par[*it] == -1) {
			par[*it] =R;
			dep[*it] =dep[R]+1;
			DFS(*it);}
		else if(par[R] != *it && dep[*it] < dep[R]) hore[*it].push_back(R);}
	while(hore[R].size() >= 2) {
		ans[0].push_back(*hore[R].rbegin());
		ans[1].push_back(R);
		hore[R].pop_back();
		ans[2].push_back(*hore[R].rbegin());
		hore[R].pop_back();}
	if(hore[R].size() == 1) {
		ans[0].push_back(par[R]);
		ans[1].push_back(R);
		ans[2].push_back(hore[R][0]);}
	else hore[par[R]].push_back(R);}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	if(M%2 != 0) {cout << "No solution\n"; return 0;}
	G.resize(N);
	hore.resize(N);
	par.resize(N,-1);
	dep.resize(N);
	for(int i =0; i < M; i++) {
		int a,b;
		cin >> a >> b;
		G[--a].push_back(--b);
		G[b].push_back(a);}
		
	par[0] =dep[0] =0;
	DFS(0);
	for(int i =0; i < ans[0].size(); i++) 
		cout << ans[0][i]+1 << " " << ans[1][i]+1 << " " << ans[2][i]+1 << "\n";
	return 0;}

// look at my code
// my code is amazing