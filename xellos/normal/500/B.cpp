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
#define OVER9000 223456789012345678LL
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.rbegin(); LIE != CAKE.rend(); LIE++)
#define tisic 47
#define soclose 1e-10
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
	vector<int> P(N);
	for(int i =0; i < N; i++) cin >> P[i];
	vector<string> G(N);
	for(int i =0; i < N; i++) cin >> G[i];
	queue<int> q;
	vector<bool> vis(N,false);
	for(int k =0; k < N; k++) if(!vis[k]) {
		vector<int> C(1,k);
		q.push(k);
		vis[k] =true;
		while(!q.empty()) {
			for(int i =0; i < N; i++) if(G[q.front()][i] == '1' && !vis[i]) {
				vis[i] =true;
				C.push_back(i);
				q.push(i);}
			q.pop();}
		sort(C.begin(),C.end());
		vector<int> p(C.size());
		for(int i =0; i < C.size(); i++) p[i] =P[C[i]];
		sort(p.begin(),p.end());
		for(int i =0; i < C.size(); i++) P[C[i]] =p[i];}
	
	for(int i =0; i < N; i++) cout << P[i] << ((i == N-1)?"\n":" ");
	return 0;}

// look at my code
// my code is amazing