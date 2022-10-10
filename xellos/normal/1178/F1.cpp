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

void solve(int L, int R, auto & dp, auto & C) {
	if(L >= R) {
		dp[L][R] = 1;
		return;
	}
	if(dp[L][R] != -1) return;
	dp[L][R] = 0;
	int min_col_pos = L, min_col = C[L];
	for(int i = L+1; i < R; i++) if(C[i] < min_col) {
		min_col = C[i];
		min_col_pos = i;
	}
	cat sum_l = 0, sum_r = 0;
	for(int l = L; l <= min_col_pos; l++) {
		solve(L, l, dp, C);
		solve(l, min_col_pos, dp, C);
		sum_l = (sum_l + dp[L][l] * dp[l][min_col_pos]) % mod;
	}
	for(int r = min_col_pos+1; r <= R; r++) {
		solve(min_col_pos+1, r, dp, C);
		solve(r, R, dp, C);
		sum_r = (sum_r + dp[min_col_pos+1][r] * dp[r][R]) % mod;
	}
	dp[L][R] = sum_l * sum_r % mod;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N, M;
	cin >> N >> M;
	vector<int> C(M);
	for(int i = 0; i < M; i++) cin >> C[i];
	vector< vector<cat> > dp(M+1, vector<cat>(M+1, -1));
	solve(0, M, dp, C);
	cout << dp[0][M] << "\n";
	return 0;
}

// look at my code
// my code is amazing