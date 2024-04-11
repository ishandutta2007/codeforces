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
	vector<int> A(N), S(N), C(N+M+1, 0);
	for(int i = 0; i < N; i++) cin >> A[i];
	for(int i = 0; i < N; i++) cin >> S[i];
	for(int i = 0; i < N+M; i++) cin >> C[i+1];
	vector< vector<int> > dp(N, vector<int>(N/2+1, -1000000000));
	vector<int> mx(N, 0);
	for(int l = 1; l <= M; l++) {
		vector<int> dp_cur(N+1, -1000000000);
		dp_cur[0] = 0;
		int mx_cur = 0;
		for(int i = N-1; i >= 0; i--) {
			if(A[i] < l) {
				for(int j = 0; j <= mx[i]; j++) dp_cur[j] = max(dp_cur[j], dp[i][j]);
				mx_cur = max(mx_cur, mx[i]);
			}
			if(A[i] == l) {
				for(int j = N-1; j >= 0; j--) dp_cur[j+1] = max(dp_cur[j+1], dp_cur[j]-S[i]);
				mx_cur++;
			}
			if(A[i] <= l) {
				for(int j = 0; j+1 <= mx_cur; j += 2)
					dp[i][j/2] = max(dp_cur[j+1] + C[l] * (j+1), dp_cur[j] + C[l] * j);
				if(mx_cur%2 == 0) dp[i][mx_cur/2] = dp_cur[mx_cur] + C[l] * mx_cur;
				mx[i] = mx_cur/2;
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < N; i++) for(int j = 0; j <= mx[i]; j++) {
		int cur = dp[i][j], cur_n = j, cur_l = M+1;
		while(cur_n) {
			cur += C[cur_l] * cur_n;
			cur_n /= 2;
			cur_l++;
		}
		ans = max(ans, cur);
	}
	cout << ans << "\n";
	return 0;
}

// look at my code
// my code is amazing