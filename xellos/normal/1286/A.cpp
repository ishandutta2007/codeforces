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
	int N;
	cin >> N;
	vector<int> P(N);
	int p[2] = {0, 0};
	for(int i = 0; i < N; i++) p[i%2]++;
	for(int i = 0; i < N; i++) {
		cin >> P[i];
		P[i]--;
		if(P[i] >= 0) P[i] %= 2;
		if(P[i] >= 0) p[P[i]]--;
	}
	vector< vector<int> > dp[2];
	dp[0].resize(p[0]+1, vector<int>(p[1]+1, N));
	dp[1].resize(p[0]+1, vector<int>(p[1]+1, N));
	vector< vector<int> > dp_next[2];
	dp[0][0][0] = dp[1][0][0] = 0;
	for(int i = 0; i < N; i++) {
		dp_next[0] = vector< vector<int> >(p[0]+1, vector<int>(p[1]+1, N));
		dp_next[1] = vector< vector<int> >(p[0]+1, vector<int>(p[1]+1, N));
		for(int k = 0; k < 2; k++) for(int l = 0; l < 2; l++) {
			if(P[i] != -1 && P[i] != k) continue;
			for(int a = 0; a <= p[0]; a++) for(int b = 0; b <= p[1]; b++) {
				int x = dp[l][a][b] + (l != k);
				int a_nxt = a, b_nxt = b;
				if(P[i] == -1 && k == 0) a_nxt++;
				if(P[i] == -1 && k == 1) b_nxt++;
				if(a_nxt > p[0] || b_nxt > p[1]) continue;
				dp_next[k][a_nxt][b_nxt] = min(dp_next[k][a_nxt][b_nxt], x);
			}
		}
		dp[0] = dp_next[0];
		dp[1] = dp_next[1];
	}
	cout << min(dp[0][p[0]][p[1]], dp[1][p[0]][p[1]]) << "\n";
	return 0;
}

// look at my code
// my code is amazing