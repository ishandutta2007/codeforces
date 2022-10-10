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
#define param vector<int>
using namespace std;
// mylittledoge

void DFS(int R, vector< param > &G, param &up, param &dep, param &par) {
	ALL_THE(G[R],it) if(*it != par[R] && par[*it] != -1)
		if(dep[up[*it]] < dep[up[R]]) up[R] =up[*it];
	ALL_THE(G[R],it) if(*it != par[R]) {
		if(par[*it] == -1) {
			par[*it] =R;
			dep[*it] =dep[R]+1;
			DFS(*it,G,up,dep,par);}
		if(dep[up[*it]] < dep[up[R]]) up[R] =up[*it];}
	}

void DFS2(int R, vector< param > &G, param &up, param &par, param &inSSC, param &isSSC, int top) {
	isSSC[R] =top;
	inSSC[top]++;
	ALL_THE(G[R],it) if(*it != par[R] && par[*it] == -1 && up[*it] != *it) {
		par[*it] =R;
		DFS2(*it,G,up,par,inSSC,isSSC,top);}
	}

void DFS3(int R, vector< param > &G, param &par, param &S, param &dep, param &W) {
	S[R] =W[R];
	ALL_THE(G[R],it) if(*it != par[R]) {
		dep[*it] =dep[R]+1;
		par[*it] =R;
		DFS3(*it,G,par,S,dep,W);
		S[R] +=S[*it];}
	}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N,M;
	cin >> N >> M;
	vector< param > G(N);
	for(int i =0; i < M; i++) {
		int a,b;
		cin >> a >> b;
		G[--a].push_back(--b);
		G[b].push_back(a);}
	param up(N),dep(N),par(N,-1);
	dep[0] =par[0] =0;
	for(int i =0; i < N; i++) up[i] =i;
	DFS(0,G,up,dep,par);
	param inSSC(N,0),isSSC(N,-1);
	for(int i =0; i < N; i++) if(up[i] != i) par[i] =-1;
	for(int i =0; i < N; i++) if(up[i] == i) {
		DFS2(i,G,up,par,inSSC,isSSC,i);}

	int ans =0;
	for(int i =0; i < N; i++) {
		ans +=inSSC[i]*(inSSC[i]-1);}

	map<int,int> m;
	for(int i =0; i < N; i++) if(inSSC[i] > 0) m[i] =0;
	int N2 =0;
	ALL_THE(m,it) it->ss =N2++;
	vector< vector<int> > G2(N2);
	for(int i =0; i < N; i++) ALL_THE(G[i],it) if(isSSC[*it] != isSSC[i]) 
		G2[m[isSSC[*it]]].push_back(m[isSSC[i]]);
	vector<int> W2(N2);
	for(int i =0; i < N; i++) if(inSSC[i] > 0) W2[m[i]] =inSSC[i];

	// najdi centroid
	param S(N2),par2(N2,-1),dep2(N2,0);
	par2[0] =0;
	DFS3(0,G2,par2,S,dep2,W2);
	int cen =-1;
	for(int i =0; i < N2; i++) {
		bool ok =true;
		int s =0;
		ALL_THE(G2[i],it) if(par2[i] != *it) {
			s +=S[*it];
			if(S[*it] > N/2) ok =false;}
		if(ok && N-s-W2[i] <= N/2) cen =i;}
	
	par2.clear(); par2.resize(N,-1);
	par2[cen] =cen;
	DFS3(cen,G2,par2,S,dep2,W2);
	for(int i =0; i < N2; i++) if(i != cen) {
		int a =i, s =0;
		while(true) {
			a =par2[a];
			s +=W2[a];
			if(cen == a) break;}
		ans +=s*W2[i];}

	int X =G2[cen].size();
	vector<int> P;
	ALL_THE(G2[cen],it) P.push_back(S[*it]);

	vector<bool> pos(N,false);
	pos[0] =true;
	for(int i =0; i < X; i++) {
		vector<bool> posN =pos;
		for(int j =0; j < N; j++) if(posN[j]) pos[j+P[i]] =true;
		}
	int Y =0;
	for(int i =0; i < N; i++) if(pos[i]) Y =max(Y,(N-W2[cen]-i)*i);

	cout << Y+N+ans << "\n";
	return 0;}

// look at my code
// my code is amazing