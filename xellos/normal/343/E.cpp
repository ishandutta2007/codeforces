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
#define abs(x) (((x) < 0)?-(x):(x))
#define uint unsigned int
#define dbl long double
#define pi 3.14159265358979323846
using namespace std;
// mylittledoge

using cat = long long;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

struct E {
	int u, v, w;
};

cat solve(vector<int> & v_set, vector< vector< pair<int, int> > > & G, vector<E> & edges) {
	if((int)v_set.size() == 1) return 0;
	int v1 = v_set[0], v2 = v_set[1];
	// flow
	int N = G.size();
	vector< vector<int> > C(N, vector<int>(N, 0));
	for(int i = 0; i < N; i++) for(auto p : G[i]) C[i][p.ff] = p.ss;
	int f = 0;
	while(true) {
		vector<int> F(N, 0), prev(N);
		F[v1] = OVER9000;
		static queue<int> q;
		q.push(v1);
		while(!q.empty()) {
			for(auto p : G[q.front()]) if(F[p.ff] == 0 && C[q.front()][p.ff] > 0) {
				prev[p.ff] = q.front();
				F[p.ff] = min(F[q.front()], C[q.front()][p.ff]);
				q.push(p.ff);
			}
			q.pop();
		}
		if(F[v2] == 0) break;
		f += F[v2];
		int cur = v2;
		while(cur != v1) {
			C[prev[cur]][cur] -= F[v2];
			C[cur][prev[cur]] += F[v2];
			cur = prev[cur];
		}
	}
	vector<int> F(N, 0);
	F[v1] = OVER9000;
	queue<int> q;
	q.push(v1);
	while(!q.empty()) {
		for(auto p : G[q.front()]) if(F[p.ff] == 0 && C[q.front()][p.ff] > 0) {
			F[p.ff] = min(F[q.front()], C[q.front()][p.ff]);
			q.push(p.ff);
		}
		q.pop();
	}
	vector<int> v_set1, v_set2;
	for(auto v : v_set) {
		if(F[v] > 0) v_set1.push_back(v);
		else v_set2.push_back(v);
	}
	edges.push_back({v1, v2, f});
	return solve(v_set1, G, edges) + solve(v_set2, G, edges) + f;
}

void build(vector<int> & v_set, vector<E> & edges, vector<int> & seq) {
	if(v_set.size() == 1) {
		seq.push_back(v_set[0]);
		return;
	}
	E * e_min = nullptr;
	for(auto & e : edges) {
		int in = 0;
		for(auto v : v_set) if(v == e.u) in++;
		for(auto v : v_set) if(v == e.v) in++;
		if(in != 2) continue;
		if(!e_min || e.w < e_min->w) e_min = &e;
	}
	int N = edges.size()+1;
	vector<int> in_set(N, 0);
	in_set[v_set[1]] = 1;
	for(int i = 0; i < N; i++) for(auto & e : edges) if(&e != e_min)
		if(in_set[e.u] == 1 || in_set[e.v] == 1) in_set[e.u] = in_set[e.v] = 1;
	vector<int> v_set1, v_set2;
	for(auto v : v_set) {
		if(in_set[v]) v_set2.push_back(v);
		else v_set1.push_back(v);
	}
	build(v_set1, edges, seq);
	build(v_set2, edges, seq);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N, M;
	cin >> N >> M;
	vector< vector< pair<int, int> > > G(N);
	for(int i = 0; i < M; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		G[--u].push_back({--v, w});
		G[v].push_back({u, w});
	}
	vector<int> S(N);
	for(int i = 0; i < N; i++) S[i] = i;
	vector<E> edges;
	cat cost = solve(S, G, edges);
	cout << cost << "\n";
	vector<int> seq;
	build(S, edges, seq);
	for(int i = 0; i < N; i++) cout << seq[i]+1 << ((i == N-1) ? "\n" : " ");
	return 0;
}

// look at my code
// my code is amazing