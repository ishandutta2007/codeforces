#include <bits/stdc++.h>
using namespace std;

const int mxN=2e3;
int n, k, c[mxN][mxN];
string g[mxN];
unordered_set<int> dp[2];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	for(int i=0; i<n; ++i) {
		cin >> g[i];
		for(int j=0; j<n; ++j) {
			if(j)
				c[i][j]=max(c[i][j-1], c[i][j]);
			if(i)
				c[i][j]=max(c[i-1][j], c[i][j]);
			c[i][j]+=g[i][j]=='a';
		}
	}
	dp[0]={0};
	for(int i=0; i<2*n-1; ++i) {
		dp[i&1^1].clear();
		bool ca=0;
		for(int j=max(i-n+1, 0); j<=min(i, n-1); ++j) {
			if(c[j][i-j]+k<i+1)
				continue;
			ca=1;
			if(j+1<n)
				dp[i&1^1].insert(j+1);
			if(i-j+1<n)
				dp[i&1^1].insert(j);
		}
		if(ca) {
			cout << 'a';
			continue;
		}
		char mc='z';
		for(int a : dp[i&1])
			mc=min(g[a][i-a], mc);
		cout << mc;
		for(int a : dp[i&1]) {
			if(g[a][i-a]!=mc)
				continue;
			if(a+1<n)
				dp[i&1^1].insert(a+1);
			if(i-a+1<n)
				dp[i&1^1].insert(a);
		}
	}
}