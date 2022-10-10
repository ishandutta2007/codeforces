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
#include <time.h>
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
#define pi 3.14159265358979323846
using namespace std;
// mylittledoge

typedef long long cat;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N, M;
	cin >> N >> M;
	vector< vector<int> > G(N);
	for(int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		G[--u].push_back(--v);
		G[v].push_back(u);
	}
	vector<int> dist(N, N+1000), ako(N, -1);
	dist[0] = 0;
	queue<int> q;
	q.push(0);
	while(!q.empty()) {
		ALL_THE(G[q.front()], it) if(dist[*it] == N+1000) {
			dist[*it] = dist[q.front()] + 1;
			ako[*it] = q.front();
			q.push(*it);
		}
		q.pop();
	}
	int ans = dist[N-1];
	vector<int> seq;
	// simple path, any cost
	int akt = N-1;
	if(ans < N+1000) while(true) {
		seq.push_back(akt);
		if(akt == 0) break;
		akt = ako[akt];
	}
	reverse(begin(seq), end(seq));
	if(ans <= 4) {
		cout << ans << "\n";
		for(int i = 0; i <= ans; i++) cout << seq[i]+1 << ((i == ans)?"\n":" ");
		return 0;
	}
	// cost 4, cycle with length 3
	vector<int> E1(N, 0);
	ALL_THE(G[0], it) E1[*it] = 1;
	for(int i = 0; i < N; i++) ALL_THE(G[i], it) if(E1[i] && E1[*it] == 0 && *it != 0) {
		ans = 4;
		seq = {0, i, *it, 0, N-1};
	}
	if(ans <= 5) {
		cout << ans << "\n";
		for(int i = 0; i <= ans; i++) cout << seq[i]+1 << ((i == ans)?"\n":" ");
		return 0;
	}
	// no answer?
	if(M == (cat)G[0].size()*((cat)G[0].size()+1)/2 && E1[N-1] == 0) {
		bool no_answer = true;
		for(int i = 1; i < N; i++) if(E1[i] == 0 && !G[i].empty()) no_answer = false;
		if(no_answer) {
			cout << "-1\n";
			return 0;
		}
	}
	// cost 5, cycle with length 3
	// create hashtable
	constexpr int SZ = 1<<20;
	constexpr cat p = 999983;
	vector< vector<cat> > hashtable(SZ);
	for(int i = 0; i < N; i++) for(int j = 0; j < (int)G[i].size(); j++) if(G[i][j] < i)
		hashtable[((i+1)*p+G[i][j]+1)&(SZ-1)].push_back(i*p+G[i][j]);
	// check pairs
	for(int i = 0; i < N; i++) sort(begin(G[i]), end(G[i]));
	int cnt = 0;
	for(int i = 1; i < N-1; i++) {
		if(ans <= 5) break;
		vector<int> adj1;
		ALL_THE(G[i], it) if(E1[*it]) adj1.push_back(*it);
		int n = adj1.size();
		for(int j = 0; j < n; j++) for(int k = 0; k < j; k++) {
			if(ans == 5) break;
			cnt++;
			// if(cnt > 50000000) break;
			cat e = adj1[j]*p+adj1[k];
			int h = ((adj1[j]+1)*p+(adj1[k]+1))&(SZ-1);
			bool edge_exists = false;
			for(int l = 0; l < (int)hashtable[h].size(); l++) 
				if(hashtable[h][l] == e) {edge_exists = true; break;}
			if(!edge_exists) {
				ans = 5;
				seq = {0, adj1[j], i, adj1[k], adj1[j], N-1};
				break;
			}
		}
	}

	if(ans == N+1000) {
		cout << "-1\n";
		return 0;
	}
	cout << ans << "\n";
	for(int i = 0; i <= ans; i++) cout << seq[i]+1 << ((i == ans)?"\n":" ");
	return 0;}

// look at my code
// my code is amazing