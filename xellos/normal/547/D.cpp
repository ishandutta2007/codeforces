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
#define soclose 1e-8
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
#define dbl long double
using namespace std;
// mylittledoge

set<int> S; // volne hrany
vector<int> sol;

void DFS(int R, vector< vector< pair<int,int> > > &G) {
	while(!G[R].empty()) {
		pair<int,int> p =*G[R].rbegin();
		G[R].pop_back();
		if(S.find(p.ss) == S.end()) continue;
		S.erase(p.ss);
		sol[p.ss] =R;
		DFS(p.ff,G);}
	}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	map<int,int> Mx,My;
	vector< pair<int,int> > E(N);
	for(int i =0; i < N; i++) {
		cin >> E[i].ff >> E[i].ss;
		Mx[E[i].ff] =0;
		My[E[i].ss] =0;}
	int nx =0, ny =0;
	ALL_THE(Mx,it) it->ss =nx++;
	ALL_THE(My,it) it->ss =ny++;

	vector< vector< pair<int,int> > > G(nx+ny);
	for(int i =0; i < N; i++) {
		E[i].ff =Mx[E[i].ff];
		E[i].ss =My[E[i].ss]+nx;
		G[E[i].ff].push_back(make_pair(E[i].ss,i));
		G[E[i].ss].push_back(make_pair(E[i].ff,i));
		S.insert(i);}

	bool plusV =false;
	int nn =0;
	for(int i =0; i < nx+ny; i++) if(G[i].size()%2 != 0) {
		if(!plusV) {
			G.resize(nx+ny+1);
			plusV =true;}
		G[nx+ny].push_back(make_pair(i,N+nn));
		G[i].push_back(make_pair(nx+ny,N+nn));
		S.insert(N+nn);
		nn++;}

	sol.resize(N+nn);
	for(uint i =0; i < G.size(); i++) DFS(i,G);

	for(int i =0; i < N; i++) {
		if(E[i].ff == sol[i]) cout << "b";
		else cout << "r";}
	cout << "\n";
	return 0;}

// look at my code
// my code is amazing