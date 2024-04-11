#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e6, M=998244353;
int n, s0[mxN+1], s1[mxN+1], s2[mxN+1];
string s;
ll iv[mxN+1], f1[mxN+1], f2[mxN+1], e1[mxN+1], e2[mxN+1];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s;
	n=s.size();
	for(int i=0; i<n; ++i) {
		s0[i+1]=s0[i]+(s[i]=='(');
		s1[i+1]=s1[i]+(s[i]==')');
		s2[i+1]=s2[i]+(s[i]=='?');
	}
	iv[1]=1;
	for(int i=2; i<=n; ++i)
		iv[i]=M-M/i*iv[M%i]%M;
	f1[0]=f2[0]=1;
	for(int i=1; i<=n; ++i) {
		f1[i]=f1[i-1]*i%M;
		f2[i]=f2[i-1]*iv[i]%M;
	}
	ll ans=0;
	/*
	for(int j=1; j<n; ++j) {
		for(int i=1; i<n; ++i) {
			//ans+=(dp1[i][j]-dp1[i-1][j]*(s[i-1]=='?'?2:1)+2*M)*dp2[i][j]%M;
			//cout << dp1[i][j]-dp1[i-1][j]*(s[i-1]=='?'?2:1) << endl;
			if(s[i-1]^')')
				ans+=dp1[i-1][j-1]*dp2[i][j]%M;
			//ans+=(dp2[i][j]-dp2[i+1][j]*(s[i]=='?'?2:1)+2*M)*dp1[i][j+1]%M;
		}
		//cout << j << " " << ans%M << endl;
	}*/
	e1[0]=e2[0]=1;
	for(int i=1; i<=n; ++i) {
		ll x1=0, x2=0;
		if(i<s2[n])
			x1=f1[s2[n]-1]*f2[i]%M*f2[s2[n]-1-i];
		if(i<=s2[n])
			x2=f1[s2[n]]*f2[i]%M*f2[s2[n]-i];
		e1[i]=(e1[i-1]+x1)%M;
		e2[i]=(e2[i-1]+x2)%M;
	}
	for(int i=1; i<n; ++i) {
		if(s2[n]-s2[i]+s1[n]-s1[i]-1-s0[i-1]<0)
			continue;
		if(s[i-1]=='?')
			ans+=e1[s2[n]-s2[i]+s1[n]-s1[i]-1-s0[i-1]];
		else if(s[i-1]=='(')
			ans+=e2[s2[n]-s2[i]+s1[n]-s1[i]-1-s0[i-1]];
	}
	cout << ans%M;
}