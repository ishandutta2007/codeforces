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
#define OVER9000 1234567890123456789LL
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
	vector<cat> H(N+2), P(M+N+2);
	H[0] = -1e15;
	H[N+1] = 1e15;
	for(int i = 0; i < N; i++) cin >> H[i+1];
	for(int i = 0; i <= N+1; i++) P[M+i] = H[i];
	for(int i = 0; i < M; i++) cin >> P[i];
	sort(begin(P), end(P));
	auto it = unique(begin(P), end(P));
	P.resize(it-begin(P));
	M = P.size();
	N += 2;

	cat mi = -1, mx = 1e15;
	while(mx-mi > 1) {
		cat c = (mi+mx)/2;
		vector<cat> dp[2] = {vector<cat>(N, OVER9000), vector<cat>(N, OVER9000)};
		dp[0][0] = dp[1][0] = 0;
		int cur_l = 0;
		for(int i = 1; i < M; i++) {
			while(cur_l < N-1 && H[cur_l+1] < P[i]) cur_l++;
			if(dp[0][cur_l]+2*(P[i-1]-H[cur_l]) <= c)
				dp[0][cur_l+1] = min(dp[0][cur_l+1], (H[cur_l+1]-P[i]));
			if(dp[1][cur_l]+(P[i-1]-H[cur_l]) <= c)
				dp[0][cur_l+1] = min(dp[0][cur_l+1], (H[cur_l+1]-P[i]));
			if(dp[0][cur_l]+2*(P[i-1]-H[cur_l]) <= c)
				dp[1][cur_l+1] = min(dp[1][cur_l+1], 2*(H[cur_l+1]-P[i]));
			if(dp[1][cur_l]+(P[i-1]-H[cur_l]) <= c)
				dp[1][cur_l+1] = min(dp[1][cur_l+1], 2*(H[cur_l+1]-P[i]));
		}
		if(min(dp[0][N-1], dp[1][N-1]) <= c) mx = c;
		else mi = c;
	}
	cout << mx << "\n";
	return 0;
}

// look at my code
// my code is amazing