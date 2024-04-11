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
#define OVER9000 1234567890123456780LL
#define patkan 9
#define tisic 47
#define soclose 1e-10
#define pi 3.1415926535898
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):(x))
#define uint unsigned int
#include <time.h>
// mylittlepony
using namespace std;

vector< vector<int> > G;
vector<int> P;
vector<bool> vis;
vector<int> par;
vector<int> path;

void DFS(int R) {
	vis[R] =true;
	ALL_THE(G[R],it) if(!vis[*it]) {
		// cesta R->*it
		P[*it] =1-P[*it];
		path.push_back(*it);
		par[*it] =R;
		DFS(*it);
		// cesta *it->R
		path.push_back(R);
		P[R] =1-P[R];
		// este raz?
		if(P[*it] == 1) {
			// cesta R->*it->R
			path.push_back(*it);
			path.push_back(R);
			P[*it] =0;
			P[R] =1-P[R];}
		}
	}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N,M;
	cin >> N >> M;
	G.resize(N);
	for(int i =0; i < M; i++) {
		int a,b;
		cin >> a >> b;
		G[--a].push_back(--b);
		G[b].push_back(a);}
	P.resize(N);
	for(int i =0; i < N; i++) cin >> P[i];
	vis.resize(N,false);
	par.resize(N);
	for(int i =0; i < N; i++) if(P[i] == 1) {
		path.push_back(i);
		P[i] =0;
		DFS(i);
		if(P[i] == 1 && !G[i].empty()) {
			path.push_back(G[i][0]);
			P[G[i][0]] =1;
			path.push_back(i);
			P[i] =0;
			path.push_back(G[i][0]);
			P[G[i][0]] =0;}
		break;}
	for(int i =0; i < N; i++) if(P[i] == 1) {
		cout << "-1\n";
		return 0;}

	cout << path.size() << "\n";
	for(uint i =0; i < path.size(); i++) cout << path[i]+1 << ((i+1 == path.size())?"\n":" ");
	return 0;}

// look at my code
// my code is amazing