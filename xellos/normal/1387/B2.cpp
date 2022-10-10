// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <chrono>
#include <random>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <iomanip>
#define dibs reserve
#define OVER9000 1234567890
#define tisic 47
#define soclose 1e-8
#define patkan 9
#define ff first
#define ss second
using uint = unsigned int;
using cat = long long;
using dbl = long double;
constexpr dbl pi = 3.14159265358979323846;
using namespace std;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

template <typename T>
T abs(T x) { return (x < 0) ? (-x) : x; }

void DFS(int R, auto & G, auto & par, auto & sz) {
	for(auto s : G[R]) if(par[s] == -1) {
		par[s] = R;
		DFS(s, G, par, sz);
		sz[R] += sz[s];
	}
}

void DFS2(int R, int par, auto & G, auto & sub, auto & sz) {
	for(auto s : G[R]) if(s != par) {
		if(R == par) sub[s] = s;
		else sub[s] = sub[R];
		DFS2(s, R, G, sub, sz);
		sz[R] += sz[s];
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cin >> N;
	vector< vector<int> > G(N);
	for(int i = 0; i < N-1; i++) {
		int u, v;
		cin >> u >> v;
		G[--u].push_back(--v);
		G[v].push_back(u);
	}
	vector<int> par(N, -1), sz(N, 1);
	par[0] = 0;
	DFS(0, G, par, sz);
	pair<int, int> C = {-1, -1};
	for(int i = 0; i < N; i++) if(2*sz[i] >= N) {
		bool is_c = true;
		for(auto s : G[i]) if(par[i] != s && 2*sz[s] > N) is_c = false;
		if(is_c) {
			if(C.ff == -1) C.ff = i;
			else C.ss = i;
		}
	}
	cat sum = 0;
	vector<int> sub(N, -1);
	if(C.ss == -1) {
		sub[C.ff] = C.ff;
		sz = vector<int>(N, 1);
		DFS2(C.ff, C.ff, G, sub, sz);
		for(int i = 0; i < N; i++) if(i != C.ff) sum += 2*sz[i];
	}
	else {
		sz = vector<int>(N, 1);
		sub[C.ff] = C.ff;
		DFS2(C.ff, C.ss, G, sub, sz);
		sub[C.ss] = C.ss;
		DFS2(C.ss, C.ff, G, sub, sz);
		for(int i = 0; i < N; i++) sum += 2*sz[i]-1;
	}
	vector< vector<int> > gr(N);
	for(int i = 0; i < N; i++) gr[sub[i]].push_back(i);
	priority_queue< pair<int, int> > q;
	for(int i = 0; i < N; i++) q.push({gr[i].size(), i});
	vector<int> P;
	int cur = -1;
	for(int i = 0; i < N; i++) {
		pair<int, int> p = {-1, -1};
		if(q.top().ss == cur) {
			p = q.top();
			q.pop();
		}
		int id = q.top().ss;
		q.pop();
		if(gr[id].empty()) return 1;
		P.push_back(gr[id].back());
		gr[id].pop_back();
		q.push({gr[id].size(), id});
		cur = id;
		if(p.ff != -1) q.push(p);
	}
	if(sub[P[N-1]] == sub[P[0]]) swap(P[N-1], P[N-2]);
	vector<int> ans(N);
	for(int i = 0; i < N; i++) ans[P[i]] = P[(i+1)%N];
	cout << sum << "\n";
	for(int i = 0; i < N; i++) cout << ans[i]+1 << ((i == N-1) ? "\n" : " ");
}

// look at my code
// my code is amazing