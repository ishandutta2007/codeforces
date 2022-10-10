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

int N,K;
long long ans =0;
vector< vector<int> > G;
vector<int> par;
vector< vector<long long> > pD;

void DFS(int R) {
	pD[R][0] =1;
	ALL_THE(G[R],it) if(par[*it] == -1) {
		par[*it] =R;
		DFS(*it);
		for(int i =1; i <= K; i++) pD[R][i] +=pD[*it][i-1];}
	ans +=pD[R][K];
	vector<long long> p(K+1,0);
	ALL_THE(G[R],it) if(par[*it] == R) {
		for(int i =0; i < K; i++) ans +=p[i]*pD[*it][K-i-1];
		for(int i =0; i < K; i++) p[i+1] +=pD[*it][i];}
	}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;
	G.resize(N);
	for(int i =1; i < N; i++) {
		int a,b;
		cin >> a >> b;
		G[--a].push_back(--b);
		G[b].push_back(a);}
	par.resize(N,-1);
	pD.resize(N,vector<long long>(K+1,0));
	par[0] =0;
	DFS(0);
	cout << ans << "\n";
	return 0;}

// look at my code
// my code is amazing