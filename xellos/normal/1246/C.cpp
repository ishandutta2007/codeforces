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
	int N, M;
	cin >> N >> M;
	vector<string> L(N);
	for(int i = 0; i < N; i++) cin >> L[i];
	if(L[N-1][M-1] == 'R') {
		cout << "0\n";
		return 0;
	}
	if(N+M == 2) {
		cout << "1\n";
		return 0;
	}
	vector< vector<int> > cnt[2];
	cnt[0].resize(N, vector<int>(M, 0));
	for(int i = 0; i < N; i++) {
		for(int j = M-2; j >= 0; j--)
			cnt[0][i][j] = cnt[0][i][j+1] + (L[i][j+1] == 'R');
		for(int j = M-2; j >= 0; j--)
			cnt[0][i][j] = M-1-j-cnt[0][i][j];
	}
	cnt[1].resize(N, vector<int>(M, 0));
	for(int i = 0; i < M; i++) {
		for(int j = N-2; j >= 0; j--)
			cnt[1][j][i] = cnt[1][j+1][i] + (L[j+1][i] == 'R');
		for(int j = N-2; j >= 0; j--)
			cnt[1][j][i] = N-1-j-cnt[1][j][i];
	}
	cat mod = 1000000007;
	vector< vector<cat> > ans[2];
	ans[0].resize(N, vector<cat>(M, 0));
	ans[1].resize(N, vector<cat>(M, 0));
	vector< vector<cat> > pref_sum[2];
	pref_sum[0].resize(N+1, vector<cat>(M+1, 0));
	pref_sum[1].resize(N+1, vector<cat>(M+1, 0));
	ans[0][N-1][M-1] = ans[1][N-1][M-1] = 1;
	pref_sum[0][N-1][M-1] = pref_sum[1][N-1][M-1] = 1;
	for(int i = N-1; i >= 0; i--) for(int j = M-1; j >= 0; j--) if(i+j < N-1+M-1) {
		ans[0][i][j] = pref_sum[0][i][j+1] - pref_sum[0][i][j+cnt[0][i][j]+1];
		ans[1][i][j] = pref_sum[1][i+1][j] - pref_sum[1][i+cnt[1][i][j]+1][j];
		if(ans[0][i][j] < 0) ans[0][i][j] += mod;
		if(ans[1][i][j] < 0) ans[1][i][j] += mod;
		pref_sum[0][i][j] = pref_sum[0][i][j+1] + ans[1][i][j];
		pref_sum[1][i][j] = pref_sum[1][i+1][j] + ans[0][i][j];
		if(pref_sum[0][i][j] >= mod) pref_sum[0][i][j] -= mod;
		if(pref_sum[1][i][j] >= mod) pref_sum[1][i][j] -= mod;
	}
	cout << (ans[0][0][0]+ans[1][0][0]) % mod << "\n";
	return 0;
}

// look at my code
// my code is amazing