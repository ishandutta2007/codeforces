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

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	vector<int> V[2];
	vector<int> id[2];
	for(int i =0; i < N; i++) {
		int a;
		cin >> a;
		id[a%2].push_back(i);
		V[a%2].push_back(a);}
	if(V[0].size() != V[1].size()) {cout << "Impossible\n"; return 0;}
	int n =V[0].size();

	vector<bool> isP(100000,true);
	for(int i =2; i < 50000; i++) if(isP[i]) 
		for(int j =2; j <= 50000/i; j++) isP[i*j] =false;

	vector< vector<int> > F(2*n+2,vector<int>(2*n+2,0));
	for(int i =0; i < n; i++) F[0][i+1] =F[n+1+i][2*n+1] =2;
	for(int i =0; i < n; i++) for(int j =0; j < n; j++) 
		if(isP[V[0][i]+V[1][j]]) F[i+1][n+1+j] =1;

	int f =0;
	queue<int> q;
	while(true) {
		vector<int> ako(2*n+2,-1);
		ako[0] =0;
		q.push(0);
		while(!q.empty()) {
			for(int i =0; i < 2*n+2; i++) if(F[q.front()][i] > 0 && ako[i] == -1) {
				ako[i] =q.front();
				q.push(i);}
			q.pop();}
		if(ako[2*n+1] == -1) break;
		f++;

		int akt =2*n+1;
		while(akt > 0) {
			F[ako[akt]][akt]--;
			F[akt][ako[akt]]++;
			akt =ako[akt];}
		}

	if(f != 2*n) {cout << "Impossible\n"; return 0;}
	vector< vector<int> > G(N);
	for(int i =0; i < n; i++) for(int j =0; j < n; j++)
		if(F[i+1][n+1+j] == 0 && F[n+1+j][i+1] == 1) {
//			cout << i << " " << j << "\n";
			G[id[0][i]].push_back(id[1][j]);
			G[id[1][j]].push_back(id[0][i]);}
	vector< vector<int> > ans;
	vector<bool> vis(N,false);
	for(int i =0; i < N; i++) if(!vis[i]) {
		vis[i] =true;
		vector<int> v(1,i);
		int akt =G[i][0];
		while(true) {
			vis[akt] =true;
			v.push_back(akt);
			if(vis[G[akt][0]] && vis[G[akt][1]]) break;
			if(vis[G[akt][0]]) akt =G[akt][1];
			else akt =G[akt][0];}
		ans.push_back(v);}
	cout << ans.size() << "\n";
	ALL_THE(ans,it) {
		vector<int> v =*it;
		cout << v.size();
		ALL_THE(v,jt) cout << " " << *jt+1;
		cout << "\n";}
	return 0;}

// look at my code
// my code is amazing