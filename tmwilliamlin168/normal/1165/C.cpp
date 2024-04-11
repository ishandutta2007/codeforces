#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	string s;
	cin >> s;
	int dp[n+1]={};
	int pd[n+1]={};
	memset(dp, 0x3f,sizeof(dp));
	dp[0]=0;
	for(int i=0; i<n; ++i) {
		if(dp[i]+1<dp[i+1]) {
			dp[i+1]=dp[i]+1;
			pd[i+1]=1;
		}
		if(i<n-1&&s[i]!=s[i+1]) {
			dp[i+2]=dp[i];
			pd[i+2]=2;
		}
	}
	cout << dp[n] << "\n";
	string t;
	for(int i=n; i>0; ) {
		if(pd[i]==1) {
			--i;
		} else {
			i-=2;
			t+=s[i+1];
			t+=s[i];
		}
	}
	reverse(t.begin(),t.end());
	cout << t;
}