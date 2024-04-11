#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e3;
int n, m, q, c[2][mxN+1][mxN+1], dp[31][2][2];
string g[mxN];

ar<int, 2> qry2(int x) {
	memset(dp, 0, sizeof(dp));
	dp[30][0][0]=1;
	for(int i=29; ~i; --i) {
		dp[i][1][0]+=dp[i+1][1][0]+dp[i+1][1][1];
		dp[i][1][1]+=dp[i+1][1][0]+dp[i+1][1][1];
		if(x>>i&1) {
			dp[i][1][0]+=dp[i+1][0][0];
			dp[i][1][1]+=dp[i+1][0][1];
			dp[i][0][0]+=dp[i+1][0][1];
			dp[i][0][1]+=dp[i+1][0][0];
		} else {
			dp[i][0][0]+=dp[i+1][0][0];
			dp[i][0][1]+=dp[i+1][0][1];
		}
	}
	//if(!x)
		//cout << dp[0][1][0] << " " << dp[0][1][1] << endl;
	return {dp[0][1][0], dp[0][1][1]};
}

ll qry1(int x, int y) {
	int x2=x/n, y2=y/m;
	int bx=__builtin_popcount(x2)&1, by=__builtin_popcount(y2)&1;
	ll r=c[bx^by^1][x%n][y%m];
	ar<int, 2> ax=qry2(x2), ay=qry2(y2);
	//cout << r << endl;
	r+=c[1][n][m]*((ll)ax[0]*ay[0]+(ll)ax[1]*ay[1]);
	r+=c[0][n][m]*((ll)ax[1]*ay[0]+(ll)ax[0]*ay[1]);
	//cout << r << endl;
	r+=c[bx^1][x%n][m]*(ll)ay[0];
	r+=c[bx][x%n][m]*(ll)ay[1];
	//cout << r << endl;
	r+=c[by^1][n][y%m]*(ll)ax[0];
	r+=c[by][n][y%m]*(ll)ax[1];
	//cout << ax[0] << " " << ax[1] << endl;
	//cout << x << " " << y << " " << r << endl;
	return r;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> q;
	for(int i=0; i<n; ++i) {
		cin >> g[i];
		for(int j=0; j<m; ++j)
			c[g[i][j]-'0'][i+1][j+1]=1;
	}
	for(int k : {0, 1}) {
		for(int i=1; i<=n; ++i) {
			for(int j=1; j<=m; ++j)
				c[k][i][j]+=c[k][i][j-1];
			for(int j=1; j<=m; ++j)
				c[k][i][j]+=c[k][i-1][j];
		}
	}
	while(q--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << qry1(x2, y2)-qry1(x1-1, y2)-qry1(x2, y1-1)+qry1(x1-1, y1-1) << "\n";
	}
}