#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; scanf("%d", &n);
	vector<int> a(n);
	for(int &i : a)
		scanf("%d", &i), i/=100;
	
	
	int s = accumulate(a.begin(), a.end(), 0);
	
	bool dp[s+1][n+1]={};
	dp[0][0]=true;
	for(int j=0;j<=s;j++)
		for(int i=1;i<=n;i++) {
			dp[j][i] |= dp[j][i-1];
			if(j - a[i]>=0)
				dp[j][i] |= dp[j - a[i-1]][i-1];
		}
	if(s%2==0 && dp[s/2][n]) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
	
}