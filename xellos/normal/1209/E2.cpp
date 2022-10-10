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
	vector< vector<cat> > disj[13];
	for(int n = 1; n <= 12; n++) {
		disj[n].resize(1<<n);
		for(int i = 0; i < (1<<n); i++)
			for(int j = 0; j < (1<<n); j++)
				if((i&j) == 0) disj[n][i].push_back(j);
	}
	int T;
	cin >> T;
	while(T--) {
		int N, M;
		cin >> N >> M;
		vector< vector<int> > A(N, vector<int>(M, 0));
		vector< pair<int, int> > mx(M, {0, 0});
		for(int i = 0; i < N; i++) for(int j = 0; j < M; j++) {
			cin >> A[i][j];
			mx[j].ff = max(mx[j].ff, A[i][j]);
		}
		for(int j = 0; j < M; j++) mx[j].ss = j;
		sort(begin(mx), end(mx));
		vector< vector<int> > C(min(N, M), vector<int>(N));
		for(int i = 0; i < min(N, M); i++) {
			int id = mx[M-1-i].ss;
			for(int j = 0; j < N; j++) C[i][j] = A[j][id];
		}
		vector<cat> dp(1<<N, 0);
		for(int i = 0; i < min(N, M); i++) {
			vector<cat> max_sum(1<<N, 0), sum(1<<N, 0);
			for(int j = 0; j < N; j++) {
				vector<int> v(N);
				for(int k = 0; k < N; k++) v[(j+k)%N] = C[i][k];
				int b = 0;
				for(int k = 0; k < (1<<N); k++) {
					while(b < N && (1<<b) <= k) b++;
					for(int l = b; l < N; l++) sum[(1<<l)+k] = sum[k]+v[l];
					max_sum[k] = max(max_sum[k], sum[k]);
				}
			}
			vector<cat> dp_nw = dp;
			for(int j = 0; j < (1<<N); j++)
				for(auto x : disj[N][j])
					dp_nw[j+x] = max(dp_nw[j+x], dp[j]+max_sum[x]);
			dp = dp_nw;
		}
		cout << dp[(1<<N)-1] << "\n";
	}
	return 0;
}

// look at my code
// my code is amazing