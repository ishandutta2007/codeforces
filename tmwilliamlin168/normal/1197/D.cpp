#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=3e5;
int n, m;
ll k, a[mxN+1], ans, b[10];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	memset(b, 0xc0, sizeof(b));
	cin >> n >> m >> k;
	b[0]=0;
	for(int i=0; i<n; ++i) {
		cin >> a[i+1], a[i+1]+=a[i];
		for(int j=1; j<=(i+1)%m; ++j) {
			ans=max(ans, b[(i+1-j+m)%m]+a[i+1]-(i+1)/m*k-k);
		}
		for(int j=(i+1)%m+1; j<=m; ++j) {
			ans=max(ans, b[(i+1-j+m)%m]+a[i+1]-(i+1)/m*k);
		}
		b[(i+1)%m]=max(b[(i+1)%m], (i+1)/m*k-a[i+1]);
	}
	cout << ans;
}