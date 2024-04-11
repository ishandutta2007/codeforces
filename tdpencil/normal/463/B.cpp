#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define vt vector
#define ar array

int main() {
	int n; cin >> n;
	ll ans=0;
	ll cur=0;
	vt<int> a(n+1);
	for(int i=1; i <= n; ++i)
		cin >> a[i];
	int mx=0;
	for(int i=1; i <= n; ++i)
		mx = max(mx, a[i]);
	ans = mx;
	cout << ans << "\n";
}