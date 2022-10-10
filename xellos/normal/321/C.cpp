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
#define patkan 9
#define dibs reserve
#define OVER9000 123456789012345678LL
#define tisic 47
#define soclose 10e-7
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
#define uint unsigned int
#define ff first
#define ss second
#define abs(x) ((x < 0)?(-x):x)
// mylittlepony
using namespace std;

int N,a,b;
vector< vector<int> > G;
vector<int> num;
vector<int> U;
vector<int> toE;
vector<int> D;

void makeN(int R, int dep) {
	// najdi najplytsi
	queue<int> q;
	q.push(R);
	U[R] =1;
	vector<int> T;
	vector<int> bot;
	while(!q.empty()) {
		a =q.front();
		T.push_back(a);
		ALL_THE(G[a],it) {
			if(U[*it] == 0) {
				U[*it] =1;
				q.push(*it);}
			if(U[*it] < 2) D[a]++;}
		if(D[a] <= 1) bot.push_back(a);
		q.pop();}
	ALL_THE(T,it) U[*it] =0;
	
	ALL_THE(bot,it) q.push(*it);
	while(!q.empty()) {
		a =q.front();
		ALL_THE(G[a],it) if(U[*it] == 0) {
			D[*it]--;
			if(D[*it] == 1) {U[*it] =1; q.push(*it);}}
		q.pop();}
	
	int pl =a;
//	cout << a << "\n";
	
	ALL_THE(T,it) U[*it] =toE[*it] =D[*it] =0;
	U[pl] =2;
	num[pl] =dep;
	ALL_THE(G[pl],it) if(U[*it] < 2) makeN(*it,dep+1);}

int main() {
	cin >> N;
	G.resize(N);
	for(int i =0; i < N-1; i++) {
		cin >> a >> b;
		G[--a].push_back(--b);
		G[b].push_back(a);}
	num.resize(N,-1);
	U.resize(N,0);
	toE.resize(N,0);
	D.resize(N,0);
	makeN(0,0);
	for(int i =0; i < N; i++) cout << (char)('A'+num[i]) << ((i == N-1)?"\n":" ");
	return 0;}
        
// look at my code
// my code is amazing