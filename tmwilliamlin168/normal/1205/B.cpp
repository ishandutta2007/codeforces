#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n, b[60], d[120][120], ans;
ll a[100000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i=0; i<n; ++i) {
		cin >> a[i];
		for(int j=0; j<60; ++j)
			b[j]+=a[i]>>j&1;
	}
	for(int i=0; i<60; ++i) {
		if(b[i]>2) {
			cout << 3;
			return 0;
		}
	}
	sort(a, a+n, greater<ll>());
	while(n&&!a[n-1])
		--n;
	for(int i=0; i<n; ++i)
		for(int j=0; j<n; ++j)
			d[i][j]=a[i]&a[j]?1:n;
	ans=n+1;
	for(int k=0; k<n; ++k) {
		for(int i=0; i<n; ++i)
			for(int j=0; j<n; ++j)
				if(i^k&&j^k&&i^j&&a[i]&a[k]&&a[j]&a[k])
					ans=min(d[i][j]+2, ans);
		for(int i=0; i<n; ++i)
			for(int j=0; j<n; ++j)
				d[i][j]=min(d[i][k]+d[k][j], d[i][j]);
	}
	cout << (ans>n?-1:ans);
}