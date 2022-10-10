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

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int MX = 5000;
	vector<int> P;
	for(int i = 2; i <= MX; i++) {
		bool ok = true;
		for(int j = 2; j < i; j++) if(i%j == 0) ok = false;
		if(ok) P.push_back(i);
	}
	reverse(begin(P), end(P));
	vector< vector<int> > E(MX+1, vector<int>(P.size(), 0));
	for(int i = 1; i <= MX; i++) {
		E[i] = E[i-1];
		int a = i;
		for(int j = 0; j < (int)P.size(); j++)
			while(a%P[j] == 0)
				a /= P[j], E[i][j]++;
	}
	for(int i = 1; i <= MX; i++)
		while(!E[i].empty() && E[i].back() == 0) E[i].pop_back();
	map< vector<int>, int> M;
	vector<int> par(MX, 0), dep(MX, 0);
	for(int i = 1; i <= MX; i++) {
		M[E[i]] = i-1;
		for(int j = 0; j < (int)E[i].size(); j++) dep[i-1] += E[i][j];
	}
	vector<int> seq;
	while(M.size() > 1) {
		vector<int> v = rbegin(M)->ff;
		int id = rbegin(M)->ss;
		seq.push_back(id);
		M.erase(--end(M));
		const vector<int> & w = rbegin(M)->ff;
		int c = 0;
		while(c < (int)w.size()) {
			if(v[c] == w[c]) c++;
			else break;
		}
		if(c == (int)w.size()) {
			par[id] = rbegin(M)->ss;
			continue;
		}
		v.resize(c+1);
		v[c] = w[c];
		while(!v.empty() && v.back() == 0) v.pop_back();
		int id_nw;
		auto it = M.find(v);
		if(it == end(M)) {
			id_nw = M[v] = par.size();
			par.push_back(0);
			dep.push_back(0);
			for(int i = 0; i < (int)v.size(); i++) dep[id_nw] += v[i];
		}
		else id_nw = it->ss;
		par[id] = id_nw;
	}
	seq.push_back(0);
	reverse(begin(seq), end(seq));
	int V = par.size(), N;
	cin >> N;
	vector<int> cnt(V, 0);
	for(int i = 0; i < N; i++) {
		int a;
		cin >> a;
		cnt[max(1,a)-1]++;
	}
	vector<int> sum = cnt;
	vector< vector<int> > sons(V);
	for(int i = V-1; i > 0; i--) {
		int v = seq[i];
		sum[par[v]] += sum[v];
		sons[par[v]].push_back(v);
	}
	vector<cat> sum_dist_down(V, 0), sum_dist_up(V, 0);
	for(int i = V-1; i > 0; i--) {
		int v = seq[i];
		sum_dist_down[par[v]] += sum_dist_down[v] + 1LL*sum[v]*(dep[v]-dep[par[v]]);
	}
	for(int i = 0; i < V; i++) {
		int v = seq[i];
		cat s = sum_dist_up[v];
		for(int j = 0; j < (int)sons[v].size(); j++)
			s += sum_dist_down[sons[v][j]] + 1LL*(dep[sons[v][j]]-dep[v]) * sum[sons[v][j]];
		for(int j = 0; j < (int)sons[v].size(); j++) {
			int d = dep[sons[v][j]]-dep[v];
			s -= sum_dist_down[sons[v][j]] + 1LL*(dep[sons[v][j]]-dep[v]) * sum[sons[v][j]];
			sum_dist_up[sons[v][j]] = s + 1LL*d * (sum[0]-sum[sons[v][j]]);
			s += sum_dist_down[sons[v][j]] + 1LL*(dep[sons[v][j]]-dep[v]) * sum[sons[v][j]];
		}
	}
	cat ans = sum_dist_down[0];
	for(int i = 0; i < V; i++) ans = min(ans, sum_dist_down[i]+sum_dist_up[i]);
	cout << ans << "\n";
	return 0;
}

// look at my code
// my code is amazing