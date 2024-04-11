#include <bits/stdc++.h>
using namespace std;

const int mxN=5e5;
int n, k, d, a[mxN], dp[mxN+1];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k >> d;
	for(int i=0; i<n; ++i)
		cin >> a[i];
	sort(a, a+n);
	for(int i1=1, i2=0; i1<=n; ++i1) {
		while(a[i1-1]-a[i2]>d)
			++i2;
		if(i1>=k)
			dp[i1]=dp[i1-1]+(dp[i1-k]>(i2?dp[i2-1]:-1));
	}
	cout << (dp[n]>dp[n-1]?"YES":"NO");
}