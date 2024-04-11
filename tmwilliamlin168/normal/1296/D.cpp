#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int n, a, b, k, h[mxN], c[mxN];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> a >> b >> k;
	for(int i=0; i<n; ++i) {
		cin >> h[i];
		h[i]%=(a+b);
		if(!h[i])
			h[i]=a+b;
		c[i]=(h[i]-1)/a;
	}
	sort(c, c+n);
	int ans=0;
	for(int i=0; i<n&&k>=c[i]; ++i)
		k-=c[i], ++ans;
	cout << ans;
}