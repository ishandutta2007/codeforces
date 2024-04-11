#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5, M=998244353;
int n;
ll a[mxN], b[mxN];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i=0; i<n; ++i) {
		cin >> a[i];
		a[i]*=(i+1);
		a[i]*=(n-i);
	}
	sort(a, a+n);
	for(int i=0; i<n; ++i) {
		cin >> b[i];
	}
	sort(b, b+n, greater<ll>());
	ll ans=0;
	for(int i=0; i<n; ++i) {
		ans += a[i]%M*b[i]%M;
	}
	cout << ans%M;
}