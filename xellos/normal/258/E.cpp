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
#define soclose 1e-5
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

void DFS(int R, vector< vector<int> > &G, vector<int> &par, vector< pair<int,int> > &I) {
	I[R].ss =I[R].ff+1;
	ALL_THE(G[R],it) if(par[*it] == -1) {
		par[*it] =R;
		I[*it].ff =I[R].ss;
		DFS(*it,G,par,I);
		I[R].ss =I[*it].ss;}
	}

struct node {
	int z,k,sum,cov;
	int son[2];
	};

struct intervalac {
	vector<node> T;

	void constI(int akt) {
		node n =T[akt];
		if(n.k-n.z == 1) return;
		for(int i =0; i < 2; i++) {
			if(i == 0) n.k =(n.z+n.k)/2;
			else {n.z =n.k; n.k =T[akt].k;}
			T[akt].son[i] =T.size();
			T.push_back(n);
			constI(T.size()-1);}
		}

	intervalac() {}
	intervalac(int N) {
		node n;
		n.son[0] =n.son[1] =-1;
		n.z =n.cov =n.sum =0, n.k =N;
		T.dibs(2*N);
		T.push_back(n);
		constI(0);}

	void put(int akt, int zac, int kon, int val) {
		node n =T[akt];
		if(n.z >= kon || zac >= n.k) return;
		if(n.z == zac && n.k == kon) {
			T[akt].cov +=val;
			return;}
		put(n.son[0],zac,min((n.z+n.k)/2,kon),val);
		put(n.son[1],max((n.z+n.k)/2,zac),kon,val);
		T[akt].sum =(T[n.son[0]].cov == 0)?T[n.son[0]].sum:(n.k-n.z)/2;
		T[akt].sum +=(T[n.son[1]].cov == 0)?T[n.son[1]].sum:(n.k-n.z+1)/2;}
	};

int main() {
	int N,M;
	scanf(" %d %d",&N,&M);
	vector< vector<int> > G(N);
	for(int i =0; i < N-1; i++) {
		int a,b;
		scanf(" %d %d",&a,&b);
		G[--a].push_back(--b);
		G[b].push_back(a);}

	vector<int> par(N,-1);
	vector< pair<int,int> > I(N);
	I[0].ff =par[0] =0;
	DFS(0,G,par,I);

	vector< vector< pair< pair<int,int>,int> > > upd(N+tisic);
	for(int i =0; i < N; i++) {
		upd[i].push_back(make_pair(make_pair(i,i+1),1));
		upd[i+1].push_back(make_pair(make_pair(i,i+1),-1));}
	for(int i =0; i < M; i++) {
		int a,b;
		scanf(" %d %d",&a,&b);
		a--, b--;
		upd[I[a].ff].push_back(make_pair(make_pair(I[b].ff,I[b].ss),1));
		upd[I[a].ss].push_back(make_pair(make_pair(I[b].ff,I[b].ss),-1));
		upd[I[b].ff].push_back(make_pair(make_pair(I[a].ff,I[a].ss),1));
		upd[I[b].ss].push_back(make_pair(make_pair(I[a].ff,I[a].ss),-1));
		upd[I[a].ff].push_back(make_pair(make_pair(I[a].ff,I[a].ss),1));
		upd[I[a].ss].push_back(make_pair(make_pair(I[a].ff,I[a].ss),-1));
		upd[I[b].ff].push_back(make_pair(make_pair(I[b].ff,I[b].ss),1));
		upd[I[b].ss].push_back(make_pair(make_pair(I[b].ff,I[b].ss),-1));}

	vector<int> C(N,0);
	intervalac I2(N);
	for(int i =0; i < N; i++) {
		ALL_THE(upd[i],it) I2.put(0,it->ff.ff,it->ff.ss,it->ss);
		C[i] =I2.T[0].sum;
		if(I2.T[0].cov > 0) C[i] =N;}

	for(int i =0; i < N; i++) {
		printf("%d",C[I[i].ff]-1);
		if(i < N-1) printf(" ");
		else printf("\n");}
	return 0;}

// look at my code
// my code is amazing