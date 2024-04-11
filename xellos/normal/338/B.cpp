// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <vector>
#include <set>
#include <tr1/unordered_map>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#define dibs reserve
#define OVER9000 1234567890
#define tisic 47
#define soclose 10e-7
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
// so much chocolate
#define ff first
#define ss second
#define uint unsigned int
// mylittlepony
using namespace std;

int N,M,D,a,b;
vector< vector<int> > G;
vector<bool> inf;
vector<int> live;
vector<int> dist;
vector<int> distA;
vector<int> S; // pocet synov podstromu
queue<int> q;
vector<int> A;

void count(int R) {
	vector<int> comp(1,R);
	// najdi najhlbsi
	// zisti komponent
	q.push(R);
	live[R] =1;
	while(!q.empty()) {
		a =q.front();
		ALL_THE(G[a],it) if(live[*it] == 0) {
			live[*it] =1;
			comp.push_back(*it);
			q.push(*it);}
		q.pop();}
	// zrataj velkosti podstromov
	int Rn =-1, x =comp.size();
	for(int i =comp.size()-1; i >= 0; i--) {
		S[comp[i]] =1;
		int y =0;
		ALL_THE(G[comp[i]],it) if(S[*it] >= 0) {
			S[comp[i]] +=S[*it];
			y =max(y,S[*it]);}
		y =max(y,(int)comp.size()-S[comp[i]]);
		if(y < x) {x =y; Rn =comp[i];}}
	
	// novy komponent
	ALL_THE(comp,it) live[*it] =0;
	live[Rn] =1;
	vector<int> compN(1,Rn);
	q.push(Rn);
	while(!q.empty()) {
		a =q.front();
		ALL_THE(G[a],it) if(live[*it] == 0) {
			live[*it] =1;
			compN.push_back(*it);
			q.push(*it);}
		q.pop();}
	ALL_THE(comp,it) live[*it] =0;
	// DFS vzdialenosti
	for(int i =compN.size()-1; i >= 0; i--) {
		a =compN[i];
		if(inf[a]) A[a] =0;
		ALL_THE(G[a],it) if(live[*it] == 0) A[a] =max(A[a],A[*it]+1);}
	dist[Rn] =A[Rn];
	x =-1;
	ALL_THE(G[Rn],it) if(live[*it] == 0 && A[Rn] == A[*it]+1) x =*it;
	int y =-OVER9000;
	ALL_THE(G[Rn],it) if(live[*it] == 0 && *it != x) y =max(y,A[*it]+1);
	if(inf[Rn]) y =max(y,0);
	live[Rn] =1;
	ALL_THE(G[Rn],it) if(live[*it] == 0) {
		live[*it] =1;
		if(x == *it) dist[*it] =y+1;
		else dist[*it] =dist[Rn]+1;
		q.push(*it);}
	while(!q.empty()) {
		a =q.front();
		ALL_THE(G[a],it) if(live[*it] == 0) {
			dist[*it] =dist[q.front()]+1;
			live[*it] =1;
			q.push(*it);}
		q.pop();}
		
	ALL_THE(comp,it) {
		A[*it] =-OVER9000;
		live[*it] =0, S[*it] =-1, distA[*it] =max(distA[*it],dist[*it]);
		dist[*it] =-OVER9000;}
	live[Rn] =2;
	ALL_THE(G[Rn],it) if(live[*it] == 0) count(*it);}

int main() {
	cin >> N >> M >> D;
	G.resize(N);
	inf.resize(N,false);
	for(int i =0; i < M; i++) {
		cin >> a;
		inf[--a] =true;}
	for(int i =0; i < N-1; i++) {
		cin >> a >> b;
		G[--a].push_back(--b);
		G[b].push_back(a);}
		
	distA.resize(N,0);
	dist.resize(N,-OVER9000);
	S.resize(N,-1);
	live.resize(N,0);
	A.resize(N,-OVER9000);
	count(0);
	
	int ans =0;
	for(int i =0; i < N; i++) if(distA[i] <= D) ans++;
	cout << ans << "\n";
    return 0;}
        
// look at my code
// my code is amazing