#include <bits/stdc++.h>
using namespace std;

const int mxN=500;
int n, dp1[mxN][mxN+1], dp2[mxN][mxN+1];
string s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> s;
	for(int i=n-1; ~i; --i) {
		for(int j=i+1; j<=n; ++j) {
			dp1[i][j]=s[i]==s[j-1]?dp1[i][j-1]:1e9;
			for(int k=i+1; k<j; ++k)
				dp1[i][j]=min(dp1[i][k]+dp2[k][j], dp1[i][j]);
			dp2[i][j]=1e9;
			for(int k=i; k<j; ++k)
				dp2[i][j]=min(dp2[i][k]+dp1[k][j]+1, dp2[i][j]);
		}
	}
	cout << dp2[0][n];
}