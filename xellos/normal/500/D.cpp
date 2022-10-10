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
#define OVER9000 223456789012345678LL
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.rbegin(); LIE != CAKE.rend(); LIE++)
#define tisic 47
#define soclose 1e-10
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
using namespace std;
// mylittledoge

struct info {
	int u,v;
	long long l;
};

void DFS(int r, vector< vector<int> > &G, vector<int> &par, vector<int> &dep, vector<int> &S, vector<info> &E) {
	ALL_THE(G[r],it) if(E[*it].u == r && par[E[*it].v] == -1) {
		par[E[*it].v] =r;
		dep[E[*it].v] =dep[r]+1;
		DFS(E[*it].v,G,par,dep,S,E);
		S[r] +=S[E[*it].v];}
	ALL_THE(G[r],it) if(E[*it].v == r && par[E[*it].u] == -1) {
		par[E[*it].u] =r;
		dep[E[*it].u] =dep[r]+1;
		DFS(E[*it].u,G,par,dep,S,E);
		S[r] +=S[E[*it].u];}
	}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	// 6*sum(vzdialenost 2och)/n/(n-1)
	int N,Q;
	cin >> N;
	vector<info> E(N-1);
	vector< vector<int> > G(N);
	vector<int> S(N,1),par(N,-1),dep(N,0);
	for(int i =0; i < N-1; i++) {
		cin >> E[i].u >> E[i].v >> E[i].l;
		G[--E[i].u].push_back(i);
		G[--E[i].v].push_back(i);}

	par[0] =0;
	DFS(0,G,par,dep,S,E);
	long long sum =0;
	for(int i =0; i < N-1; i++) {
		if(dep[E[i].u] > dep[E[i].v]) swap(E[i].u,E[i].v);
		sum +=E[i].l*S[E[i].v]*(N-S[E[i].v]);}

	cin >> Q;
	for(int q =0; q < Q; q++) {
		int id;
		long long n;
		cin >> id >> n;
		id--;
		sum -=(E[id].l-n)*S[E[id].v]*(N-S[E[id].v]);
		E[id].l =n;
		cout << sum*6.0/N/(N-1) << "\n";}
	return 0;}

// look at my code
// my code is amazing