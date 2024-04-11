#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5;
int n;
ll h[2][mxN], dp[mxN+1][3];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	for(int i : {0, 1})
		for(int j=0; j<n; ++j)
			cin >> h[i][j];
	auto u=[](ll &a, ll b) {
		a=max(a, b);
	};
	for(int i=0; i<n; ++i) {
		//0
		u(dp[i+1][0], dp[i][0]);
		u(dp[i+1][1], dp[i][0]+h[0][i]);
		u(dp[i+1][2], dp[i][0]+h[1][i]);
		//1
		u(dp[i+1][0], dp[i][1]);
		u(dp[i+1][2], dp[i][1]+h[1][i]);
		//2
		u(dp[i+1][0], dp[i][2]);
		u(dp[i+1][1], dp[i][2]+h[0][i]);
	}
	cout << max({dp[n][0], dp[n][1], dp[n][2]});
}