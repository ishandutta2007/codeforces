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

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	string S;
	cin >> S;
	int N = S.length();
	vector< vector<int> > dp_st(N+1, vector<int>(N+1, 0));
	vector< vector<int> > dp_st_all(N+1, vector<int>(N+1, 0));
	vector< vector<int> > dp_fi(N+1, vector<int>(N+1, 0));
	vector< vector<int> > dp_fi_all(N+1, vector<int>(N+1, 0));
	dp_st[0][0] = dp_st_all[0][0] = 1;
	for(int i = 0; i < N; i++) for(int b = 0; b < 2; b++) {
		if(S[i] == '(' && b == 1) continue;
		if(S[i] == ')' && b == 0) continue;
		if(b == 0) for(int k = 0; k < N; k++) {
			dp_st[i+1][k+1] += dp_st_all[i][k];
			if(dp_st[i+1][k+1] >= mod) dp_st[i+1][k+1] -= mod;
		}
		if(b == 0) {
			for(int k = 0; k < N; k++) {
				dp_st_all[i+1][k+1] += dp_st_all[i][k];
				if(dp_st_all[i+1][k+1] >= mod) dp_st_all[i+1][k+1] -= mod;
			}
		}
		else {
			for(int k = 0; k <= N; k++) {
				dp_st_all[i+1][k] += dp_st_all[i][k];
				if(dp_st_all[i+1][k] >= mod) dp_st_all[i+1][k] -= mod;
			}
		}
	}
	dp_fi[N][0] = dp_fi_all[N][0] = 1;
	for(int i = N-1; i >= 0; i--) for(int b = 0; b < 2; b++) {
		if(S[i] == '(' && b == 1) continue;
		if(S[i] == ')' && b == 0) continue;
		if(b == 1) for(int k = 0; k < N; k++) {
			dp_fi[i][k+1] += dp_fi_all[i+1][k];
			if(dp_fi[i][k+1] >= mod) dp_fi[i][k+1] -= mod;
		}
		if(b == 0) {
			for(int k = 0; k <= N; k++) {
				dp_fi_all[i][k] += dp_fi_all[i+1][k];
				if(dp_fi_all[i][k] >= mod) dp_fi_all[i][k] -= mod;
			}
		}
		else {
			for(int k = 0; k < N; k++) {
				dp_fi_all[i][k+1] += dp_fi_all[i+1][k];
				if(dp_fi_all[i][k+1] >= mod) dp_fi_all[i][k+1] -= mod;
			}
		}
	}
	vector<cat> cnt_dep_atleast(N+1, 0);
	for(int i = 0; i <= N; i++) for(int k = N-1; k >= 0; k--) {
		dp_fi_all[i][k] += dp_fi_all[i][k+1];
		if(dp_fi_all[i][k] >= mod) dp_fi_all[i][k] -= mod;
	}
	for(int i = 0; i <= N; i++) for(int j = 0; j <= N; j++)
		cnt_dep_atleast[j] = (cnt_dep_atleast[j] + 1LL * dp_st[i][j] * dp_fi_all[i][j]) % mod;
	cat ans = 0;
	for(int i = 0; i < N; i++)
		ans = (ans + i * (cnt_dep_atleast[i]-cnt_dep_atleast[i+1])) % mod;
	if(ans < 0) ans += mod;
	cout << ans << "\n";
	return 0;
}

// look at my code
// my code is amazing