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
#define dbl long double
#define pi 3.14159265359
using namespace std;
// mylittledoge

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N,M;
	cin >> N >> M;
	vector< vector<int> > D(N,vector<int>(N,1000000));
	vector< vector<int> > G(N);
	for(int i =0; i < M; i++) {
		int a,b;
		cin >> a >> b;
		G[--b].push_back(--a);
		G[a].push_back(b);}
	
	for(int i =0; i < N; i++) {
		D[i][i] =0;
		queue<int> q;
		q.push(i);
		while(!q.empty()) {
			ALL_THE(G[q.front()],it) if(D[i][*it] > D[i][q.front()]+1) {
				D[i][*it] =D[i][q.front()]+1;
				q.push(*it);}
			q.pop();}
		}

	int S[2],T[2],L[2];
	for(int i =0; i < 2; i++) {
		cin >> S[i] >> T[i] >> L[i]; 
		S[i]--; T[i]--;}

	if(D[S[0]][T[0]] > L[0] || D[S[1]][T[1]] > L[1]) {cout << "-1\n"; return 0;}

	int ans =D[S[0]][T[0]]+D[S[1]][T[1]];
	for(int i =0; i < N; i++) for(int j =0; j < N; j++)
		if(D[S[0]][i]+D[i][j]+D[j][T[0]] <= L[0] && D[S[1]][i]+D[i][j]+D[j][T[1]] <= L[1])
			ans =min(ans,D[S[0]][i]+D[j][T[0]]+D[i][j]+D[S[1]][i]+D[j][T[1]]);
	swap(S[0],T[0]);
	for(int i =0; i < N; i++) for(int j =0; j < N; j++)
		if(D[S[0]][i]+D[i][j]+D[j][T[0]] <= L[0] && D[S[1]][i]+D[i][j]+D[j][T[1]] <= L[1])
			ans =min(ans,D[S[0]][i]+D[j][T[0]]+D[i][j]+D[S[1]][i]+D[j][T[1]]);

	cout << M-ans << "\n";
	return 0;}

// look at my code
// my code is amazing