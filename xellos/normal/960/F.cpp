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

struct fin {
	vector<int> T;
	fin() {}
	fin(int N) {T.resize(N+10, 0);}

	int lastone(int x) {return x&(x^(x-1));}

	void put(int pos, int val) {
		for(int i = pos+1; i < (int)T.size(); i += lastone(i)) T[i] = max(T[i], val);
	}

	int get(int pos) {
		int ret = 0;
		for(int i = pos+1; i > 0; i -= lastone(i)) ret = max(ret, T[i]);
		return ret;
	}
};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N, M;
	cin >> N >> M;
	vector< pair<int, int> > E(M);
	vector<int> W(M);
	vector< vector< pair<int, int> > > G(N), Gi(N);
	for(int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v >> W[i];
		E[i] = make_pair(--u, --v);
		G[u].push_back(make_pair(v, i));
		Gi[v].push_back(make_pair(u, i));
	}
	vector< map<int, int> > comp(N);
	vector<fin> F(N);
	for(int i = 0; i < N; i++) {
		ALL_THE(Gi[i], it) comp[i][W[it->ss]] = 0;
		ALL_THE(G[i], it) comp[i][W[it->ss]] = 0;
		int m = 0;
		ALL_THE(comp[i], it) it->ss = m++;
		F[i] = fin(m);
	}
	vector<int> ans(M, 0);
	int ansF = 0;
	for(int i = 0; i < M; i++) {
		int wx = comp[E[i].ff][W[i]];
		ans[i] = 1 + F[E[i].ff].get(wx-1);
		int wy = comp[E[i].ss][W[i]];
		F[E[i].ss].put(wy, ans[i]);
		ansF = max(ansF, ans[i]);
	}
	cout << ansF << "\n";
	return 0;}

// look at my code
// my code is amazing