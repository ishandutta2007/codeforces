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

void DFS_start(int R, auto & G, auto & par, auto & sz) {
	sz[R] = 1;
	for(auto & p : G[R]) if(par[p.ff] == -1) {
		par[p.ff] = R;
		DFS_start(p.ff, G, par, sz);
		sz[R] += sz[p.ff];
	}
}

bool fail;

int DFS(int R, auto & G, auto & par, auto & cnt, auto & sums, auto & sums_new, int & first_z, int K, int sum_cur = 0) {
	if(fail) return 0;
	while(first_z <= K && cnt[first_z] >= 2) first_z++;
	while(first_z > K && cnt[first_z]) first_z++;
	if(sum_cur > first_z) {
		fail = true;
		return 0;
	}
	sums_new.push_back(first_z);
	int ret = first_z - sum_cur;
	cnt[first_z] |= 2;
	for(auto s : sums) cnt[s+first_z] |= 1;
	while(first_z <= K && cnt[first_z] >= 2) first_z++;
	while(first_z > K && cnt[first_z]) first_z++;
	for(auto & p : G[R]) if(par[p.ff] == R)
		p.ss = DFS(p.ff, G, par, cnt, sums, sums_new, first_z, K, sum_cur + ret);
	return ret;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cin >> N;
	vector< vector< pair<int, int> > > G(N);
	for(int i = 0; i < N-1; i++) {
		int u, v;
		cin >> u >> v;
		G[--u].push_back({--v, 0});
		G[v].push_back({u, 0});
	}
	vector<int> par(N, -1), sz(N);
	par[0] = 0;
	DFS_start(0, G, par, sz);
	int C = 0;
	for(int i = 1; i < N; i++) {
		bool is_centroid = true;
		for(auto & p : G[i]) if(par[p.ff] == i)
			if(sz[p.ff]*2 > N) is_centroid = false;
		if((N-sz[i])*2 > N) is_centroid = false;
		if(is_centroid) C = i;
	}
	par = vector<int>(N, -1);
	par[C] = C;
	DFS_start(C, G, par, sz);
	for(auto & p : G[C]) p = {sz[p.ff], p.ff};
	sort(begin(G[C]), end(G[C]));
	for(auto & p : G[C]) p = {p.ss, 0};
	for(int k = 1; k <= 5*N; k++) {
		static vector<int> sums;
		sums.clear();
		static vector<char> cnt = vector<char>(2*N*N+2, 0);
		memset(cnt.data(), 0, 2*N*N+2);
		int first_z = 1;
		fail = false;
		for(auto & p : G[C]) {
			static vector<int> sums_new;
			sums_new.clear();
			p.ss = DFS(p.ff, G, par, cnt, sums, sums_new, first_z, k);
			if(fail) break;
			for(auto x : sums_new) sums.push_back(x);
		}
		if(first_z > N*N*2/9 && !fail) break;
		if(k == 5*N) {
			cerr << "FAIL\n";
			exit(1);
		}
	}
	for(int i = 0; i < N; i++) for(auto & p : G[i]) if(par[p.ff] == i)
		cout << i+1 << " " << p.ff+1 << " " << p.ss << "\n";
	return 0;
}

// look at my code
// my code is amazing