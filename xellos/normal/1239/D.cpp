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

stack<int> st;

void DFS(int R, auto & G, auto & id, auto & min_id, int & cur_id, auto & comp, auto & in_st, int & c) {
	id[R] = min_id[R] = cur_id++;
	st.push(R);
	in_st[R] = 1;
	for(auto v : G[R]) {
		if(id[v] == -1) {
			DFS(v, G, id, min_id, cur_id, comp, in_st, c);
			min_id[R] = min(min_id[R], min_id[v]);
		}
		else if(in_st[v]) min_id[R] = min(min_id[R], id[v]);
	}
	if(id[R] == min_id[R]) {
		while(st.top() != R) {
			comp[st.top()] = c;
			in_st[st.top()] = 0;
			st.pop();
		}
		comp[R] = c;
		in_st[R] = 0;
		st.pop();
		c++;
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int T;
	cin >> T;
	while(T--) {
		int N, M;
		cin >> N >> M;
		vector< vector<int> > G(2*N);
		for(int i = 0; i < M; i++) {
			int u, v;
			cin >> u >> v;
			u--, v--;
			if(u == v) continue;
			G[2*u].push_back(2*v);
			G[2*v+1].push_back(2*u+1);
		}
		vector<int> id(2*N, -1), min_id(2*N), comp(2*N);
		vector<char> in_st(2*N, 0);
		int cur_id = 0, c = 0;
		for(int i = 0; i < 2*N; i++) if(id[i] == -1)
			DFS(i, G, id, min_id, cur_id, comp, in_st, c);
		bool ok = true;
		for(int i = 0; i < N; i++) if(comp[2*i] == comp[2*i+1]) ok = false;
		if(!ok) {
			cout << "No\n";
			continue;
		}
		vector< vector<int> > DAG(c);
		vector<int> out_deg(c, 0);
		for(int i = 0; i < 2*N; i++) for(auto v : G[i]) if(comp[i] != comp[v]) {
			DAG[comp[v]].push_back(comp[i]);
			out_deg[comp[i]]++;
		}
		queue<int> q;
		for(int i = 0; i < c; i++) if(out_deg[i] == 0) q.push(i);
		vector< vector<int> > comp_v(c);
		for(int i = 0; i < 2*N; i++) comp_v[comp[i]].push_back(i);
		vector<int> ans_val(N, -1);
		int n_cats = 0, n_people = 0;
		while(!q.empty()) {
			bool skip = false;
			for(auto v : comp_v[q.front()])
				if(ans_val[v/2] != -1) skip = true;
			if(!skip) {
				int n_cats_nw = n_cats, n_people_nw = n_people;
				for(auto v : comp_v[q.front()]) {
					if(v%2 == 1) n_cats_nw++;
					else n_people_nw++;
				}
				if(n_cats_nw < N && n_people_nw < N) {
					n_cats = n_cats_nw;
					n_people = n_people_nw;
					for(auto v : comp_v[q.front()]) ans_val[v/2] = v%2;
				}
			}
			for(auto v : DAG[q.front()]) {
				out_deg[v]--;
				if(out_deg[v] == 0) q.push(v);
			}
			q.pop();
		}
		if(n_cats == N || n_people == N || n_cats+n_people != N) {
			cout << "No\n";
			continue;
		}
		vector<int> ans[2];
		for(int i = 0; i < N; i++) ans[ans_val[i]].push_back(i+1);
		cout << "Yes\n" << ans[0].size() << " " << ans[1].size() << "\n";
		for(int i = 0; i < (int)ans[0].size(); i++)
			cout << ans[0][i] << ((i == ans[0].size()-1) ? "\n" : " ");
		for(int i = 0; i < (int)ans[1].size(); i++)
			cout << ans[1][i] << ((i == ans[1].size()-1) ? "\n" : " ");
	}
	return 0;
}

// look at my code
// my code is amazing