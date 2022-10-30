#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e3, M=998244353;
int n;
string s;
ll dp1[mxN+1][mxN+1], dp2[mxN+1][mxN+1];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s;
	n=s.size();
	dp1[0][0]=dp2[n][0]=1;
	for(int i=0; i<n; ++i) {
		for(int j=0; j<=i; ++j) {
			if(dp1[i][j]>=M)
				dp1[i][j]-=M;
			if(s[i]^')')
				dp1[i+1][j+1]+=dp1[i][j];
			if(s[i]^'(')
				dp1[i+1][j]+=dp1[i][j];
		}
	}
	for(int i=n-1; ~i; --i) {
		for(int j=0; j<=n-1-i; ++j) {
			if(dp2[i+1][j]>=M)
				dp2[i+1][j]-=M;
			if(s[i]^')')
				dp2[i][j]+=dp2[i+1][j];
			if(s[i]^'(')
				dp2[i][j+1]+=dp2[i+1][j];
		}
	}
	for(int i=0; i<=n; ++i) {
		if(dp1[n][i]>=M)
			dp1[n][i]-=M;
		if(dp2[0][i]>=M)
			dp2[0][i]-=M;
	}
	for(int i=0; i<=n; ++i) {
		for(int j=n-1; ~j; --j) {
			//dp1[i][j]+=dp1[i][j+1];
			//if(dp1[i][j]>=M)
				//dp1[i][j]-=M;
			dp2[i][j]+=dp2[i][j+1];
			if(dp2[i][j]>=M)
				dp2[i][j]-=M;
		}
	}
	//cout << dp2[1][1] << endl;
	ll ans=0;
	for(int j=1; j<n; ++j) {
		for(int i=1; i<n; ++i) {
			//ans+=(dp1[i][j]-dp1[i-1][j]*(s[i-1]=='?'?2:1)+2*M)*dp2[i][j]%M;
			//cout << dp1[i][j]-dp1[i-1][j]*(s[i-1]=='?'?2:1) << endl;
			if(s[i-1]^')')
				ans+=dp1[i-1][j-1]*dp2[i][j]%M;
			//ans+=(dp2[i][j]-dp2[i+1][j]*(s[i]=='?'?2:1)+2*M)*dp1[i][j+1]%M;
		}
		//cout << j << " " << ans%M << endl;
	}
	cout << ans%M;
}