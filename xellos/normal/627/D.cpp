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
#include <time.h>
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
#define dbl long double
#define pi 3.14159265358979323846
using namespace std;
// mylittledoge

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

vector<int> vis;
int aa;

int DFS(int R, vector< vector<int> > &G, vector<bool> &bl, vector<int> &par, vector<int> &S, vector<int> &S1) {
	vis.push_back(R);
	bool leaf =true;
	ALL_THE(G[R],it) if(par[*it] == -1) leaf =false;
	ALL_THE(G[R],it) if(bl[*it] && par[*it] == -1) S[R] =-1;
	int ret =0;
	ALL_THE(G[R],it) if(!bl[*it] && par[*it] == -1) {
		par[*it] =R;
		ret =max(ret,DFS(*it,G,bl,par,S,S1));
		if(S[*it] == -1) S[R] =-1;
		if(S[R] != -1) S[R] +=S[*it];
		if(S[*it] != -1) S1[R] +=S[*it];}
	int maxf =0;
	ALL_THE(G[R],it) if(!bl[*it] && par[R] != *it && S[*it] == -1)
		maxf =max(maxf,S1[*it]);
	S1[R] +=maxf;
	if(leaf) S[R] =S1[R] =1;
	int v =1;
	vector<int> sonx(2,0);
	ALL_THE(G[R],it) if(!bl[*it] && par[R] != *it) {
		if(S[*it] != -1) v +=S[*it];
		else sonx.push_back(S1[*it]);}
	int vm1 =0, vm2 =1, s =sonx.size();
	for(int i =0; i < s; i++) if(sonx[i] > sonx[vm1]) vm1 =i;
	for(int i =0; i < s; i++) if(i != vm1 && sonx[i] > sonx[vm2]) vm2 =i;
	ret =max(ret,v+sonx[vm1]+sonx[vm2]);
	return ret;}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N,K;
	scanf(" %d %d",&N,&K);
	vector<int> A(N);
	for(int i =0; i < N; i++) scanf(" %d",&A[i]);
	vector< vector<int> > G(N);
	for(int i =0; i < N-1; i++) {
		int a,b;
		scanf("%d %d",&a,&b);
		G[--a].push_back(--b);
		G[b].push_back(a);}

	int Amax =1000000+1, Amin =1000000;
	ALL_THE(A,it) Amin =min(Amin,*it);
	while(Amax-Amin > 1) {
		int Ac =(Amin+Amax)/2;
		aa =Ac;
		bool ok =false;

		vector<bool> bl(N,false);
		for(int i =0; i < N; i++) if(A[i] < Ac) bl[i] =true;
		vector<int> S(N,1),S1(N,1),par(N,-1);

		for(int i =0; i < N; i++) if(!bl[i]) {
			bool is_top =false;
			ALL_THE(G[i],it) if(bl[*it]) is_top =true;
			if(!is_top) continue;
			par[i] =i;
			if(DFS(i,G,bl,par,S,S1) >= K) ok =true;
			ALL_THE(vis,it) bl[*it] =true;
			vis.clear();}

		if(ok) Amin =Ac;
		else Amax =Ac;}

	printf("%d\n",Amin);
	return 0;}

// look at my code
// my code is amazing