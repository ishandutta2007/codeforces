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
	int N,M;
	cin >> N >> M;
	vector< vector<int> > G(N);
	vector< vector<int> > Gr(N);
	vector<int> D(N,0);
	for(int i =0; i < M; i++) {
		int a,b;
		cin >> a >> b;
		G[--a].push_back(--b);
		G[b].push_back(a);
		Gr[a].push_back(b);
		D[b]++;}

	queue<int> q;
	vector<bool> vis(N,false);

	int ans =0;
	for(int i =0; i < N; i++) if(!vis[i]) {
		vis[i] =true;
		vector<int> v(1,i);
		
		q.push(i);
		while(!q.empty()) {
			ALL_THE(G[q.front()],it) if(!vis[*it]) {
				vis[*it] =true;
				v.push_back(*it);
				q.push(*it);}
			q.pop();}

		// je to dag?
		ALL_THE(v,it) if(D[*it] == 0) q.push(*it);
		while(!q.empty()) {
			ALL_THE(Gr[q.front()],it) {
				D[*it]--;
				if(D[*it] == 0) q.push(*it);}
			q.pop();}
		bool isC =false;
		ALL_THE(v,it) if(D[*it] != 0) isC =true;
		ans +=(!isC)?((int)v.size()-1):v.size();}

	cout << ans << "\n";
	return 0;}

// look at my code
// my code is amazing