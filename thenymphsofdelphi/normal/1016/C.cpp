#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define fi first
#define se second
using namespace std;

const int mod = 1e9 + 7, N = 3e5 + 5;
int n, m, val = 0;
int a[N][2], dp[N][2];
bool temp[N][2];

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++){
	    cin >> a[i][0];
	}
	for (int i = 1; i <= n; i++){
	    cin >> a[i][1];
	}
	int val = 0;
	for (int i = n; i >= 1; i--){
	    dp[i][0] = dp[i + 1][0] + a[i][0] * (2 * i - 2) + a[i][1] * (2 * n - 1) - val;
		dp[i][1] = dp[i + 1][1] + a[i][1] * (2 * i - 2) + a[i][0] * (2 * n - 1) - val;
		val += a[i][0] + a[i][1];
	}
	int ans = dp[1][0], x = 1, y = 0, sum = 0;
	for (int i = 0; i < 2 * n; i++){
	    sum += i * a[x][y];
	    temp[x][y] = 1;
		if (temp[x][y^1]){
			ans = max(ans, sum + dp[x + 1][y]);
			x++;
		}
		else{
		    y ^= 1;
		}
	}
	cout << ans;
}