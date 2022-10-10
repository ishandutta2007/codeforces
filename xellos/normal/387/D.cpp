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
#include <iomanip>
#define dibs reserve
#define OVER9000 1234567890
#define patkan 9
#define tisic 47
#define soclose 1e-9
#define pi 3.1415926535898
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):(x))
#define uint unsigned int
// mylittlepony
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	int N,M, ans =OVER9000;
	cin >> N >> M;
	vector< vector<int> > G0(N);
	for(int i =0; i < M; i++) {
		int a,b;
		cin >> a >> b;
		G0[--a].push_back(--b);}

	vector< vector<int> > F(2*N,vector<int>(2*N,0));
	vector< vector<int> > G(2*N);
	for(int c =0; c < N; c++) {
		int akt =G0[c].size();
		for(int i =0; i < N; i++) if(i != c)
			ALL_THE(G0[i],it) if(*it == c) akt++;
		if(M-akt+(N-2-akt) >= ans) continue;

		for(int i =0; i < N; i++) if(i != c) {
			F[0][i+1-int(i > c)] =1;
			G[0].push_back(i+1-int(i > c));
			G[i+1-int(i > c)].push_back(0);}
		for(int i =0; i < N; i++) if(i != c) {
			F[N+i-int(i > c)][2*N-1] =1;
			G[2*N-1].push_back(N+i-int(i > c));
			G[N+i-int(i > c)].push_back(2*N-1);}
		for(int i =0; i < N; i++) if(i != c)
			ALL_THE(G0[i],it) if(*it != c) {
				F[i+1-int(i > c)][N+*it-int(*it > c)] =1;
				G[i+1-int(i > c)].push_back(N+*it-int(*it > c));
				G[N+*it-int(*it > c)].push_back(i+1-int(i > c));
				if(F[0][i+1-int(i > c)] && F[N+*it-int(*it > c)][2*N-1]) {
					F[0][i+1-int(i > c)] =F[N+*it-int(*it > c)][2*N-1] =0;
					F[i+1-int(i > c)][0] =F[2*N-1][N+*it-int(*it > c)] =1;
					F[i+1-int(i > c)][N+*it-int(*it > c)] =0;
					F[N+*it-int(*it > c)][i+1-int(i > c)] =1;
					akt++;}
				}

		vector<int> ako(2*N,-1),inQ;
		ako[0] =0;
		queue<int> q;
		while(true) {
			q.push(0);
			while(!q.empty()) {
				if(ako[2*N-1] != -1) break;
				ALL_THE(G[q.front()],it) if(ako[*it] == -1 && F[q.front()][*it] > 0) {
					ako[*it] =q.front();
					inQ.push_back(*it);
					q.push(*it);}
				q.pop();}
			while(!q.empty()) q.pop();
			if(ako[2*N-1] == -1) break;

			akt++;
			int a =2*N-1;
			while(a > 0) {
				F[ako[a]][a]--;
				F[a][ako[a]]++;
				a =ako[a];}

			ALL_THE(inQ,it) ako[*it] =-1;
			inQ.clear();}

		for(int i =0; i < 2*N; i++) {
			G[i].clear();}
		for(int i =0; i < N; i++) if(i != c)
			ALL_THE(G0[i],it) if(*it != c) {
				F[i+1-int(i > c)][N+*it-int(*it > c)] =0;
				F[N+*it-int(*it > c)][i+1-int(i > c)] =0;}
		for(int i =0; i < N; i++) if(i != c)
			F[0][i+1-int(i > c)] =F[i+1-int(i > c)][0] =0;
		for(int i =0; i < N; i++) if(i != c)
			F[N+i-int(i > c)][2*N-1] =F[2*N-1][N+i-int(i > c)] =0;

		ans =min(ans,M-akt+(N-1+1+2*(N-1)-akt));}

	cout << ans << "\n";
	return 0;}

// look at my code
// my code is amazing