#include<bits/stdc++.h>
using namespace std;
#define int		long long
#define double	long double
#define pb		push_back
#define pob		pop_back
#define mp		make_pair
#define fi		first
#define se		second
#define pque	priority_queue
#define endl	'\n'
typedef vector <int> 	vi;
typedef pair <int, int> ii;
typedef vector <vi > 	vvi;
typedef vector <ii > 	vii;

const int N = 1000 + 5, M = 2000 + 5, mod = 998244353, inf = 1e18 + 7;

int n, m;
int dp[N][4][M];

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	dp[1][0][1] = 1;
	dp[1][1][1] = 0;
	dp[1][2][1] = 0;
	dp[1][3][1] = 1;
	dp[1][0][2] = 0;
	dp[1][1][2] = 1;
	dp[1][2][2] = 1;
	dp[1][3][2] = 0;
	for (int i = 2; i <= n; i++){
        for (int k = 1; k <= 2 * i; k++){
            dp[i][0][k] = (dp[i - 1][0][k] + dp[i - 1][1][k] + dp[i - 1][2][k] + dp[i - 1][3][k - 1]) % mod;
            dp[i][1][k] = (dp[i - 1][0][k - 1] + dp[i - 1][1][k] + dp[i - 1][2][k - 2] + dp[i - 1][3][k - 1]) % mod;
            dp[i][2][k] = (dp[i - 1][0][k - 1] + dp[i - 1][1][k - 2] + dp[i - 1][2][k] + dp[i - 1][3][k - 1]) % mod;
            dp[i][3][k] = (dp[i - 1][0][k - 1] + dp[i - 1][1][k] + dp[i - 1][2][k] + dp[i - 1][3][k]) % mod;
        }
	}
	cout << (dp[n][0][m] + dp[n][1][m] + dp[n][2][m] + dp[n][3][m]) % mod;
}

/*

*/