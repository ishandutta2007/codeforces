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
#define OVER9000 1234567890123456789LL
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

struct edge {
	int l,u,v;};

void DFS(int R, vector< vector< pair<int,int> > > &G, vector<int> &par, vector<int> &dep, vector<int> &up) {
	up[R] =R;
	ALL_THE(G[R],it) {
		if(par[it->ff] == -1) {
			par[it->ff] =R;
			dep[it->ff] =dep[R]+1;
			DFS(it->ff,G,par,dep,up);
			if(dep[up[it->ff]] < dep[up[R]]) up[R] =up[it->ff];}
		if(it->ff != par[R] && dep[it->ff] < dep[up[R]]) up[R] =it->ff;}
	}

int main() {
	int N,M,st,fin;
	scanf(" %d %d %d %d",&N,&M,&st,&fin);
	st--; fin--;
	vector<edge> E(M);
	vector< vector< pair<int,int> > > G(N);
	auto Gi =G;
	for(int i =0; i < M; i++) {
		int a,b,c;
		scanf(" %d %d %d",&a,&b,&c);
		G[--a].push_back(make_pair(--b,c));
		Gi[b].push_back(make_pair(a,c));
		E[i].u =a;
		E[i].v =b;
		E[i].l =c;}

	vector<long long> Dst(N,OVER9000);
	Dst[st] =0;
	priority_queue< pair<long long,int>, vector< pair<long long,int> >, greater< pair<long long,int> > > q;
	q.push(make_pair(0,st));
	while(!q.empty()) {
		pair<long long,int> p =q.top();
		q.pop();
		if(Dst[p.ss] != p.ff) continue;
		ALL_THE(G[p.ss],it) if(Dst[it->ff] > p.ff+it->ss) {
			Dst[it->ff] =p.ff+it->ss;
			q.push(make_pair(Dst[it->ff],it->ff));}
		}

	vector<long long> Dfin(N,OVER9000);
	Dfin[fin] =0;
	q.push(make_pair(0,fin));
	while(!q.empty()) {
		pair<long long,int> p =q.top();
		q.pop();
		if(Dfin[p.ss] != p.ff) continue;
		ALL_THE(Gi[p.ss],it) if(Dfin[it->ff] > p.ff+it->ss) {
			Dfin[it->ff] =p.ff+it->ss;
			q.push(make_pair(Dfin[it->ff],it->ff));}
		}

	vector< vector< pair<int,int> > > Gbest(N);
	for(int i =0; i < M; i++) if(Dst[E[i].u]+Dfin[E[i].v]+E[i].l == Dst[fin]) {
		Gbest[E[i].u].push_back(make_pair(E[i].v,i));
		Gbest[E[i].v].push_back(make_pair(E[i].u,i));}
	vector<int> par(N,-1),dep(N,0),up(N);
	par[st] =st;
	DFS(st,Gbest,par,dep,up);

	vector<bool> yes(M,false);
	for(int i =0; i < N; i++) if(up[i] == i) {
		int rm =0;
		ALL_THE(Gbest[i],it) if(it->ff == par[i]) rm++;
		if(rm > 1) continue;
		ALL_THE(Gbest[i],it) if(it->ff == par[i]) yes[it->ss] =true;}

	for(int i =0; i < M; i++) {
		if(yes[i]) {printf("YES\n"); continue;}
		long long mind =Dst[fin]-1-Dst[E[i].u]-Dfin[E[i].v];
		if(mind <= 0) printf("NO\n");
		else printf("CAN %I64d\n",E[i].l-mind);}
	return 0;}

// look at my code
// my code is amazing