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
	string s;
	cin >> N >> s;
	vector< vector<char> > dp(N+1, vector<char>(N+1, 0));
	for(int i = 0; i <= N; i++) dp[i][i] = 1;
	for(int l = 0; l < N; l++) {
		for(int i = 0; i <= N-l; i++) for(int j = 0; j <= l; j++)
			dp[i][i+l] |= dp[i][i+j] & dp[i+j][i+l];
		for(int i = 0; i <= N-l; i++) if(dp[i][i+l]) {
			int r = i+l;
			if(r < N-1 && s[r+1] == s[r]-1) dp[i][i+l+1] = 1;
			if(i >= 2 && s[i-2] == s[i-1]-1) dp[i-1][i+l] = 1;
			if(i && r < N && s[i-1] == s[r]-1) dp[i][i+l+1] = 1;
			if(i && r < N && s[r] == s[i-1]-1) dp[i-1][i+l] = 1;
		}
	}
	vector<int> ans(N+1, 0);
	for(int i = 0; i < N; i++) for(int j = i+1; j <= N; j++) {
		ans[j] = max(ans[j], ans[i]);
		if(dp[i][j]) ans[j] = max(ans[j], j-i+ans[i]);
	}
	cout << ans[N] << "\n";
	return 0;
}

// look at my code
// my code is amazing