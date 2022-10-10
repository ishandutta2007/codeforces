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

bool is_edge(int u, int v) {
	cout << "? " << u+1 << " " << v+1 << endl;
	int ans;
	cin >> ans;
	return ans;
}

struct SCC_info {
	vector<int> par, id, min_id;
	stack<int> st;
	vector<bool> in_st;
	int cur_id;
};

void DFS(int R, vector< vector<int> > & G, SCC_info & I, vector< vector<int> > & SCC) {
	I.in_st[R] = true;
	I.st.push(R);
	I.id[R] = I.min_id[R] = I.cur_id++;
	ALL_THE(G[R], it) {
		if(I.id[*it] >= I.cur_id) {
			I.par[*it] = R;
			DFS(*it, G, I, SCC);
			I.min_id[R] = min(I.min_id[R], I.min_id[*it]);
		}
		else if(I.in_st[*it]) I.min_id[R] = min(I.min_id[R], I.id[*it]);
	}
	if(I.min_id[R] == I.id[R]) {
		vector<int> v(1, R);
		while(I.st.top() != R) {
			v.push_back(I.st.top());
			I.in_st[v.back()] = false;
			I.st.pop();
		}
		I.st.pop();
		I.in_st[R] = false;
		SCC.push_back(v);
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N, M;
	cin >> N >> M;
	vector< vector<int> > G(N), Gi(N);
	for(int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		G[--u].push_back(--v);
		Gi[v].push_back(u);
	}
	SCC_info I;
	I.par.resize(N, -1);
	I.id.resize(N, N);
	I.min_id.resize(N, N);
	I.in_st.resize(N, false);
	I.cur_id = 0;
	vector< vector<int> > SCC;
	for(int i = 0; i < N; i++) if(I.id[i] == N) DFS(i, G, I, SCC);
	vector<int> SCC_id(N);
	int C = SCC.size();
	for(int i = 0; i < C; i++) ALL_THE(SCC[i], it) SCC_id[*it] = i;
	vector< vector<int> > G_DAG(C);
	vector<int> deg(C, 0);
	for(int i = 0; i < N; i++) ALL_THE(G[i], it) if(SCC_id[i] != SCC_id[*it]) {
		G_DAG[SCC_id[i]].push_back(SCC_id[*it]);
		deg[SCC_id[*it]]++;
	}
	vector<int> top;
	for(int i = 0; i < C; i++) if(deg[i] == 0) top.push_back(i);
	int v[2] = {top[0]}; // currently tested pair of top SCCs
	while(top.size() != 1U) {
		if(SCC[top.back()].empty()) {
			top.pop_back();
			continue;
		}
		if(SCC[top[0]].empty()) {
			swap(top[0], top.back());
			top.pop_back();
			continue;
		}
		v[1] = (top.back() == v[0]) ? top[0] : top.back();
		int cur = 0;
		while(!SCC[v[1-cur]].empty()) {
			if(is_edge(SCC[v[cur]].back(), SCC[v[1-cur]].back())) SCC[v[1-cur]].pop_back();
			else {
				SCC[v[cur]].pop_back();
				cur = 1-cur;
			}
		}
		ALL_THE(G_DAG[v[1-cur]], it) {
			deg[*it]--;
			if(deg[*it] == 0) top.push_back(*it);
		}
		v[0] = v[cur];
	}
	cout << "! " << SCC[v[0]][0]+1 << endl;
	return 0;
}

// look at my code
// my code is amazing