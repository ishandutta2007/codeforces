#include <bits/stdc++.h>
using namespace std;

const int mxN=50;
int n, dp[mxN][mxN][mxN][mxN];
string s[mxN];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i2=0; i2<n; ++i2) {
		cin >> s[i2];
		for(int i1=i2; ~i1; --i1) {
			for(int j2=0; j2<n; ++j2) {
				for(int j1=j2; ~j1; --j1) {
					dp[i1][i2][j1][j2]=i1==i2&&j1==j2?s[i1][j1]=='#':max(i2-i1, j2-j1)+1;
					for(int k=i1; k<i2; ++k)
						dp[i1][i2][j1][j2]=min(dp[i1][k][j1][j2]+dp[k+1][i2][j1][j2], dp[i1][i2][j1][j2]);
					for(int k=j1; k<j2; ++k)
						dp[i1][i2][j1][j2]=min(dp[i1][i2][j1][k]+dp[i1][i2][k+1][j2], dp[i1][i2][j1][j2]);
				}
			}
		}
	}
	cout << dp[0][n-1][0][n-1];
}