#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2005, mod = 1e9 + 7;
int dp[N][N];
vector <int> g[N];

signed main(){
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++){
		for (int j = i; j <= n; j += i){
			g[i].push_back(j);
		}
	}
	dp[0][1] = 1;
	for (int i = 0; i < k; i++){
		for (int x = 1; x <= n; x++){
			for (int j = 0; j < g[x].size(); j++){
				dp[i + 1][g[x][j]] = (dp[i + 1][g[x][j]] + dp[i][x]) % mod;
			}
		}
	}
	int ans = 0;
	for (int x = 1; x <= n; x++){
	    ans = (ans + dp[k][x]) % mod;
	}
	cout << ans;                      
}