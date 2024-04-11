#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=4e4;
int n, m, k, a[mxN], b[mxN];
ll ans, c1[mxN+1], c2[mxN+1];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	for(int i=0; i<n; ++i)
		cin >> a[i];
	for(int i=0; i<m; ++i)
		cin >> b[i];
	for(int i=0, j=-1; i<n; ++i) {
		if(!a[i])
			j=i;
		++c1[i-j];
	}
	for(int i=0, j=-1; i<m; ++i) {
		if(!b[i])
			j=i;
		++c2[i-j];
	}
	for(int i=n; i; --i)
		c1[i-1]+=c1[i];
	for(int i=m; i; --i)
		c2[i-1]+=c2[i];
	for(int i=1; i*i<=k; ++i)
		if(k%i==0&&k/i<=mxN)
			ans+=c1[i]*c2[k/i];
	for(int i=1; i*i<k; ++i)
		if(k%i==0&&k/i<=mxN)
			ans+=c2[i]*c1[k/i];
	cout << ans;
}