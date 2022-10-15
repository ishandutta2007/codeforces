#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int n, k;
ll a[mxN], b[mxN+1], ans=1e18;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for(int i=0; i<n; ++i) {
		cin >> a[i];
	}
	sort(a, a+n);
	for(int i=0; i<n; ++i)
		b[i+1]=b[i]+a[i];
	for(int i=0, j=0; i<n; i=j) {
		for(; j<n&&a[j]==a[i]; ++j);
		ll c=j-i, x=a[i], cl=(ll)i*(x-1)-b[i], cr=b[n]-b[j]-(ll)(n-j)*(x+1);
		//no left/right
		if(c>=k)
			ans=0;
		//left
		if(c+i>=k)
			ans=min(cl+k-c, ans);
		//right
		if(c+n-j>=k)
			ans=min(cr+k-c, ans);
		//both
		ans=min(cl+cr+k-c, ans);
	}
	cout << max(ans, 0ll);
}