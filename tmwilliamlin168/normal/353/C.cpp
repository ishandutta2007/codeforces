#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5;
int n, a[mxN], dp[mxN+1][2];
string m;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i=0; i<n; ++i)
		cin >> a[i];
	cin >> m;
	for(int i=0; i<n; ++i) {
		for(int j : {0, 1}) {
			for(int k=0; k<=1; ++k) {
				int j2=k<m[i]-'0'||k==m[i]-'0'&&j;
				dp[i+1][j2]=max(dp[i+1][j2], dp[i][j]+(k?a[i]:0));
			}
		}
	}
	cout << dp[n][1];
}