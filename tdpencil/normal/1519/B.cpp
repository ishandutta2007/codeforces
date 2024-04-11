#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define ar array
#define all(x) x.begin(),x.end()
#define sz(x) int(x.size())
#define vt vector
#define lb lower_bound
#define ub upper_bound
#define pb push_back

void io() {
	ios_base::sync_with_stdio(false); cin.tie(0);
}
int n, m, k;
const int mxN = 2e5 + 1;
int a[mxN], b[mxN], cnt[mxN];

bool dp[101][101][10001];
void solve() 
{
	cin >> n >> m >> k;
	n--, m--;

	cout << (dp[n][m][k] ? "YES\n" : "NO\n");
} 

void prec() {
	for(int i = 0; i < 101; i++) {
		for(int j = 0; j < 101; j++) {
			for(int k = 1; k <= 10000; k++) {
				if(i >= 1 && k - j - 1>= 0) dp[i][j][k] |= dp[i - 1][j][k - j - 1];
				if(j >= 1 && k - i - 1>= 0) dp[i][j][k] |= dp[i][j - 1][k - i - 1];
			}
		}
	}
}
int main() {
	dp[0][0][0] = 1;

	prec();
	io();
	
	int t = 1;
	cin >> t;
	while(t--) solve();
}