#include <bits/stdc++.h>
using namespace std;

const int mxN=50, mxR=5000;

int n, r, f[mxN], s[mxN], p[mxN];
double dp[mxN][mxR+1], m;

double solve(int i=0, int used=0) {
	if(used>r)
		return m;
	if(i>=n)
		return 0;
	if(dp[i][used]==-1)
		dp[i][used]=min((p[i]*(f[i]+solve(i+1, used+f[i]))+(100-p[i])*(s[i]+solve(i+1, used+s[i])))/100, m);
	return dp[i][used];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> r;
	for(int i=0; i<n; ++i)
		cin >> f[i] >> s[i] >> p[i];
	double lo=1, hi=4e7;
	for(int i=0; i<60; ++i) {
		for(int j=0; j<n; ++j)
			for(int k=0; k<=r; ++k)
				dp[j][k]=-1;
		m=(lo+hi)/2;
		if(solve()<m)
			hi=m;
		else
			lo=m;
	}
	cout << fixed << setprecision(17) << (lo+hi)/2;
}