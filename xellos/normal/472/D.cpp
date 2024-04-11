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
#define soclose 1e-9
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

int main() {
	int N;
	cin >> N;
	vector< vector<int> > D(N,vector<int>(N));
	for(int i =0; i < N; i++) for(int j =0; j < N; j++)
		scanf("%d",&D[i][j]);

	for(int i =0; i < N; i++) if(D[i][i] != 0) {cout << "NO\n"; return 0;}
	for(int i =0; i < N; i++) for(int j =0; j < N; j++)
		if(D[i][j] != D[j][i]) {cout << "NO\n"; return 0;}
	
	vector< vector<int> > G(N);
	for(int i =1; i < N; i++) {
		int d =-1,x;
		for(int j =0; j < N; j++) if(D[0][i] == D[0][j]+D[i][j] && D[i][j] > 0)
			if(d < D[0][j]) {d =D[0][j]; x =j;}
		if(d == -1) {cout << "NO\n"; return 0;}
		G[x].push_back(i);
		G[i].push_back(x);}

	vector< vector<int> > Dt(N,vector<int>(N,0));
	queue<int> q;
	for(int k =0; k < N; k++) {
		q.push(k);
		vector<bool> vis(N,false);
		vis[k] =true;
		while(!q.empty()) {
			ALL_THE(G[q.front()],it) if(!vis[*it]) {
				vis[*it] =true;
				Dt[k][*it] =Dt[k][q.front()]+D[q.front()][*it];
				q.push(*it);}
			q.pop();}
		}

	for(int i =0; i < N; i++) for(int j =0; j < N; j++) 
		if(D[i][j] != Dt[i][j]) {cout << "NO\n"; return 0;}
	cout << "YES\n";
	return 0;}

// look at my code
// my code is amazing