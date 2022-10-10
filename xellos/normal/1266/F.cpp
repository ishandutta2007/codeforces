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

void find_max_dep(int e, auto & E, auto & G, auto & max_dep, auto & GD, auto & m_val, auto & m_id, auto & m_cnt) {
	if(max_dep[e]) return;
	max_dep[e] = 1;
	if(m_cnt[E[e]] >= 2 || (m_cnt[E[e]] == 1 && m_id[E[e]] != (e^1))) {
		max_dep[e] = m_val[E[e]]+1;
		return;
	}
	for(int i = 0; i < (int)G[E[e]].size(); i++) {
		int e_nxt = G[E[e]][i];
		if(e_nxt != (e^1)) {
			if(!max_dep[e_nxt]) {
				find_max_dep(e_nxt, E, G, max_dep, GD, m_val, m_id, m_cnt);
				GD[E[e]][i] = max_dep[e_nxt];
				if(m_val[E[e]] < max_dep[e_nxt]) {
					m_val[E[e]] = max_dep[e_nxt];
					m_id[E[e]] = e_nxt;
					m_cnt[E[e]] = 0;
				}
				if(m_val[E[e]] == max_dep[e_nxt])
					m_cnt[E[e]]++;
			}
			max_dep[e] = max(max_dep[e], max_dep[e_nxt]+1);
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cin >> N;
	vector<int> E(2*(N-1));
	vector< vector<int> > G(N);
	for(int i = 0; i < N-1; i++) {
		cin >> E[2*i] >> E[2*i+1];
		G[--E[2*i]].push_back(2*i+1);
		G[--E[2*i+1]].push_back(2*i);
	}
	vector<int> max_dep(2*(N-1), 0);
	vector< vector<int> > GD(N);
	for(int i = 0; i < N; i++) GD[i].resize(G[i].size());
	vector<int> m_val(N, 0), m_cnt(N, 0), m_id(N, 0);
	for(int i = 0; i < N; i++) for(int j = 0; j < (int)G[i].size(); j++) {
		find_max_dep(G[i][j], E, G, max_dep, GD, m_val, m_id, m_cnt);
		GD[i][j] = max_dep[G[i][j]];
	}
	vector<int> ans(N+1, 1);
	for(int i = 0; i < N; i++) ans[1] = max(ans[1], 1+(int)G[i].size());
	for(int i = 0; i < N; i++) {
		sort(begin(GD[i]), end(GD[i]));
		for(int j = 0; j < (int)GD[i].size(); j++) {
			if(j < (int)GD[i].size()-1) {
				ans[2*GD[i][j]-1] = max(ans[2*GD[i][j]-1], (int)GD[i].size()-j);
				ans[2*GD[i][j]] = max(ans[2*GD[i][j]], (int)GD[i].size()-j);
			}
			if(j && GD[i][j-1] < GD[i][j])
				ans[2*GD[i][j-1]+1] = max(ans[2*GD[i][j-1]+1], (int)GD[i].size()-j+1);
		}
	}
	int L = 100;
	for(int i = 0; i < N; i++) {
		vector<int> pos(G[i].size());
		vector<int> sz(G[i].size());
		vector<int> V(G[i].size());
		vector<int> nxt(G[i].size());
		for(int j = 0; j < (int)G[i].size(); j++) {
			V[j] = E[G[i][j]];
			pos[j] = GD[V[j]].size();
			nxt[j] = GD[V[j]][pos[j]-1];
			sz[j] = 0;
		}
		for(int k = (int)GD[i].size()-1; k >= 0; k--) {
			if(GD[i][k] <= L) break;
			if(GD[i][k]*2 > N) continue;
			for(int j = 0; j < (int)G[i].size(); j++) {
				while(pos[j] && nxt[j] >= GD[i][k]) {
					pos[j]--, sz[j]++;
					if(pos[j]) nxt[j] = GD[V[j]][pos[j]-1];
				}
				ans[2*GD[i][k]] = max(ans[2*GD[i][k]], sz[j]+(int)GD[i].size()-k-2);
			}
		}
	}
	vector<int> pos(N, 0), sz(N), nxt(N);
	for(int i = 0; i < N; i++) {
		sz[i] = GD[i].size();
		nxt[i] = sz[i] ? GD[i][pos[i]] : 0;
	}
	vector<char> live(N-1, 1);
	for(int d = 1; d <= min(N/2, L); d++) {
		for(int i = 0; i < N; i++) while(sz[i] && nxt[i] < d) {
			pos[i]++, sz[i]--;
			nxt[i] = sz[i] ? GD[i][pos[i]] : 0;
		}
		for(int i = 0; i < N-1; i++) if(live[i]) {
			ans[2*d] = max(ans[2*d], sz[E[2*i]]+sz[E[2*i+1]]-2);
			if(sz[E[2*i]] < 2 || sz[E[2*i+1]] < 2) live[i] = 0;
		}
	}
	for(int i = N; i >= 2; i--) ans[i-2] = max(ans[i-2], ans[i]);
	for(int i = 1; i <= N; i++) cout << ans[i] << ((i == N) ? "\n" : " ");
}

// look at my code
// my code is amazing