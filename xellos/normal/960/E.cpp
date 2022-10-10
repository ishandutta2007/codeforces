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

cat mod = 1000000007;

void DFS(int R, vector< vector<int> > &G, vector<int> &par, vector<int> &S, vector<int> &S_alt) {
	S[R] = S_alt[R] = 1;
	ALL_THE(G[R], it) if(par[*it] == -1) {
		par[*it] = R;
		DFS(*it, G, par, S, S_alt);
		S[R] += S[*it];
		S_alt[R] -= S_alt[*it];
	}
}

void DFS_down(int R, vector< vector<int> > &G, vector<int> &par, vector<int> &S_alt, vector<int> &S_adown) {
	cat sum = 0;
	ALL_THE(G[R], it) if(par[*it] == R) sum = (sum + S_alt[*it]) % mod;
	ALL_THE(G[R], it) if(par[*it] == R) {
		S_adown[*it] = (-S_adown[R]-1+sum-S_alt[*it])%mod;
		DFS_down(*it, G, par, S_alt, S_adown);
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cin >> N;
	vector<cat> V(N);
	for(int i = 0; i < N; i++) cin >> V[i];
	vector< vector<int> > G(N);
	vector<int> par(N, -1);
	for(int i = 0; i < N-1; i++) {
		int u, v;
		cin >> u >> v;
		G[--u].push_back(--v);
		G[v].push_back(u);
	}
	vector<int> S(N, 0), S_alt(N, 0);
	par[0] = 0;
	DFS(0, G, par, S, S_alt);
	vector<int> S_adown(N, 0);
	DFS_down(0, G, par, S_alt, S_adown);
	cat ans = 0;
	for(int i = 0; i < N; i++)
		ans = (ans + V[i] * N) % mod;
	for(int i = 1; i < N; i++) {
		// i -> par[i]
		cat alt = -S_alt[i], cnt = N-S[i];
		ans = (ans + V[par[i]] * alt % mod * cnt) % mod;
		// par[i] -> i
		alt = S_adown[i];
		cnt = S[i];
		ans = (ans + V[i] * alt % mod * cnt) % mod;
	}
	ans %= mod;
	if(ans < 0) ans += mod;
	cout << ans << "\n";
	return 0;}

// look at my code
// my code is amazing