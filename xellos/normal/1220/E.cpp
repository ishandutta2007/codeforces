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

void DFS(int R, int par, vector< vector<int> > & G, vector<cat> & W_sum, vector<int> & W) {
	for(auto v : G[R]) if(v != par) {
		W_sum[v] = W_sum[R] + W[v];
		DFS(v, R, G, W_sum, W);
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N, M;
	cin >> N >> M;
	vector<int> W(N);
	for(int i = 0; i < N; i++) cin >> W[i];
	if(N == 1) {
		cout << W[0] << "\n";
		return 0;
	}
	vector< vector<int> > G(N);
	vector< set<int> > Gs(N);
	for(int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		G[--u].push_back(--v);
		G[v].push_back(u);
		Gs[u].insert(v);
		Gs[v].insert(u);
	}
	if(M == N-1) { // tree
		vector<cat> W_sum(N);
		int S;
		cin >> S;
		S--;
		W_sum[S] = W[S];
		DFS(S, S, G, W_sum, W);
		cat ans = 0;
		for(int i = 0; i < N; i++) ans = max(ans, W_sum[i]);
		cout << ans << "\n";
		return 0;
	}
	vector<cat> W_path(N, 0);
	vector<int> on_path(N, 0), par(N);
	queue<int> q;
	for(int i = 0; i < N; i++) if(Gs[i].size() == 1) q.push(i);
	vector<int> seq;
	while(!q.empty()) {
		seq.push_back(q.front());
		on_path[q.front()] = 1;
		int nxt = *begin(Gs[q.front()]);
		Gs[nxt].erase(q.front());
		Gs[q.front()].clear();
		par[q.front()] = nxt;
		if(Gs[nxt].size() == 1) q.push(nxt);
		q.pop();
	}
	reverse(begin(seq), end(seq));
	for(auto v : seq) W_path[v] = W_path[par[v]] + W[v];
	cat sum_nonpath = 0;
	for(int i = 0; i < N; i++) if(on_path[i] == 0) sum_nonpath += W[i];
	int S;
	cin >> S;
	S--;
	if(on_path[S]) {
		cat ans = 0;
		vector<cat> W_path_noS(N, 0);
		int cur = S;
		while(on_path[cur]) {
			W[cur] = 0;
			cur = par[cur];
		}
		for(auto v : seq) W_path_noS[v] = W_path_noS[par[v]] + W[v];
		for(int i = 0; i < N; i++) ans = max(ans, W_path_noS[i] + W_path[S]);
		ans += sum_nonpath;
		cout << ans << "\n";
	}
	else {
		cat max_path = 0;
		for(int i = 0; i < N; i++) if(on_path[i]) max_path = max(max_path, W_path[i]);
		cat ans = max_path + sum_nonpath;
		cout << ans << "\n";
	}
	return 0;
}

// look at my code
// my code is amazing