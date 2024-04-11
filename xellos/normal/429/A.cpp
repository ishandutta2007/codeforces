// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <unordered_map>
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
using namespace std;
// mylittledoge

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	vector< vector<int> > G(N);
	for(int i =1; i < N; i++) {
		int a,b;
		cin >> a >> b;
		G[--a].push_back(--b);
		G[b].push_back(a);}

	vector<int> D(N);
	for(int i =0; i < N; i++) cin >> D[i];
	for(int i =0; i < N; i++) {
		int a;
		cin >> a;
		D[i] =D[i]^a;}

	queue<int> q;
	vector<int> vis(N,true);
	vis[0] =false;
	q.push(0);
	vector<int> par(N,0);
	vector<int> s(N,0);
	int ans =0;
	vector<int> op;
	while(!q.empty()) {
		int x =(q.front() == 0 || par[q.front()] == 0)?0:D[par[par[q.front()]]];
		if(x != D[q.front()]) {
			op.push_back(q.front());
			ans++;}
		ALL_THE(G[q.front()],it) if(vis[*it]) {
			vis[*it] =false;
			par[*it] =q.front();
			q.push(*it);}
		q.pop();}

	cout << ans << "\n";
	for(int i =0; i < ans; i++) cout << op[i]+1 << "\n";
	return 0;}

// look at my code
// my code is amazing