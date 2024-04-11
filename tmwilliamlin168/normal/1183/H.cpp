#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=100;
int n, prv[26];
ll k, dp[mxN+1][mxN+1], a2[mxN+1];
string s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k >> s;
	dp[0][0]=1;
	for(int i=0; i<n; ++i) {
		for(int j=0; j<26; ++j) {
			prv[j]=i;
			while(prv[j]&&s[prv[j]-1]-'a'!=j) {
				--prv[j];
			}
		}
		for(int j=1; j<=n; ++j) {
			for(int k=0; k<26; ++k)
				if(prv[k])
					dp[i+1][j]+=dp[prv[k]][j-1];
			dp[i+1][j]+=dp[0][j-1];
			dp[i+1][j]=min(k, dp[i+1][j]);
		}
	}
	for(int k=0; k<26; ++k) {
		prv[k]=n;
		while(prv[k]&&s[prv[k]-1]-'a'!=k)
			--prv[k];
		if(!prv[k])
			continue;
		for(int j=0; j<=n; ++j)
			a2[j]+=dp[prv[k]][j];
	}
	++a2[0];
	ll ans=0;
	for(int i=n; ~i; --i) {
		ll take=min(k, a2[i]);
		k-=take;
		ans+=take*(n-i);
	}
	if(k) {
		cout << -1;
		return 0;
	}
	cout << ans;
}