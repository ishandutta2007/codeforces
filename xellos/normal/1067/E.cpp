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

cat mod = 998244353;

void DFS(int R, int par, vector< vector<int> > & G, vector< vector<cat> > & cnt, vector< vector<cat> > & sum) {
	cat cnt_cur[] = {0, 1};
	cat sum_cur[] = {0, 0};
	cat cnt_cur_nw[2], sum_cur_nw[2];
	ALL_THE(G[R], it) if(*it != par) {
		DFS(*it, R, G, cnt, sum);
		// cut
		cnt_cur_nw[1] = (2 * cnt[*it][0] + cnt[*it][1]) * cnt_cur[1] % mod;
		sum_cur_nw[1] = ((2 * sum[*it][0] + sum[*it][1]) * cnt_cur[1] + (2 * cnt[*it][0] + cnt[*it][1]) * sum_cur[1]) % mod;
		cnt_cur_nw[0] = (2 * (cnt[*it][0] + cnt[*it][1]) * cnt_cur[0] + cnt[*it][1] * cnt_cur[1]) % mod;
		sum_cur_nw[0] = (2 * (sum[*it][0] + sum[*it][1]) * cnt_cur[0] + 2 * (cnt[*it][0] + cnt[*it][1]) * sum_cur[0] + sum[*it][1] * cnt_cur[1] + cnt[*it][1] * sum_cur[1] + cnt[*it][1] * cnt_cur[1]) % mod;
		for(int k = 0; k < 2; k++) {
			cnt_cur[k] = cnt_cur_nw[k];
			sum_cur[k] = sum_cur_nw[k];
		}
	}
	for(int k = 0; k < 2; k++) {
		cnt[R][k] = cnt_cur[k];
		sum[R][k] = sum_cur[k];
	}
}

// cut, 0, 0 -> 0
// cut, 0, 1 -> 0
// cut, 1, 0 -> 1
// cut, 1, 1 -> 1
// noc, 0, 0 -> 0
// noc, 0, 1 -> 0
// noc, 1, 0 -> 1
// noc, 1, 1 -> 0 +
// 0, 0 -> 0 x2
// 0, 1 -> 0 x2
// 1, 0 -> 1 x2
// 1, 1 -> 0 x1
// 1, 1 -> 1 x1

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
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
	vector< vector<cat> > cnt(N, vector<cat>(2, 0)), sum(N, vector<cat>(2, 0));
	DFS(0, 0, G, cnt, sum);
	cout << (2 * sum[0][0] + 2 * sum[0][1]) % mod << "\n";
	return 0;
}

// look at my code
// my code is amazing