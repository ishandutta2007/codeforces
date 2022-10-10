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

bool try_solve(int rb, int rt, vector< vector<int> > &Gb, vector< vector<int> > &Gt, vector<int> &match) {
	int N = Gb.size();
	for(int i = 0; i < N; i++) match[i] = -1;
	match[rb] = rt;
	vector<int> freev, part(N, -1);
	part[rt] = rt;
	for(int i = 0; i < N; i++) if(match[i] == -1) freev.push_back(i);
	vector<bool> block(N, false);
	queue<int> q;
	q.push(rb);
	for(int i = 0; i < N; i++) {
		if(q.empty()) return false;
		int v = q.front(), w = match[q.front()];
		ALL_THE(Gb[v], it) block[*it] = true;
		ALL_THE(Gt[w], it) if(part[*it] == -1) {
			part[*it] = v;
			int u = -1;
			for(int j = 0; j < 3+(int)Gb[v].size(); j++) {
				int x = rand()%freev.size();
				if(block[freev[x]]) continue;
				u = freev[x];
				swap(freev[x], freev.back());
				freev.pop_back();
				break;
			}
			if(u == -1) return false;
			match[u] = *it;
			q.push(u);
		}
		ALL_THE(Gb[v], it) block[*it] = false;
		q.pop();
	}
	return true;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cin >> N;
	vector< vector<int> > G[2];
	vector<int> deg[2];
	int R[2];
	for(int i = 0; i < 2; i++) {
		G[i].resize(N);
		deg[i].resize(N, 0);
		for(int j = 0; j < N-1; j++) {
			int u, v;
			cin >> u >> v;
			if(i) u -= N, v -= N;
			G[i][--u].push_back(--v);
			G[i][v].push_back(u);
			deg[i][u]++, deg[i][v]++;
		}
		R[i] = 0;
		for(int j = 0; j < N; j++) if(deg[i][j] > deg[i][R[i]]) R[i] = j;
	}
	int REP = 100;
	srand(23479+N);
	for(int rep = 0; rep < REP; rep++) {
		int t = rand()%2;
		vector<int> vr;
		for(int i = 0; i < N; i++)
			if(N-1-deg[1-t][i] >= deg[t][R[t]]) vr.push_back(i);
		if(vr.empty()) continue;
		int r = vr[rand()%vr.size()];
		vector<int> match[2];
		for(int i = 0; i < 2; i++) match[i] = vector<int>(N);
		bool ok = try_solve(R[t], r, G[t], G[1-t], match[t]);
		if(ok) {
			cout << "Yes\n";
			for(int i = 0; i < N; i++) match[1-t][match[t][i]] = i;
			for(int i = 0; i < N; i++) cout << N+1+match[0][i] << ((i == N-1)?"\n":" ");
			return 0;
		}
		ok = try_solve(r, R[t], G[1-t], G[t], match[1-t]);
		if(ok) {
			cout << "Yes\n";
			for(int i = 0; i < N; i++) match[t][match[1-t][i]] = i;
			for(int i = 0; i < N; i++) cout << N+1+match[0][i] << ((i == N-1)?"\n":" ");
			return 0;
		}
	}
	cout << "No\n";
	return 0;}

// look at my code
// my code is amazing