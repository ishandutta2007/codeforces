#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=100;
int q, n, k;
ll a[mxN];

void solve() {
	cin >> n >> k;
	ll l=-2e18, r=2e18;
	for(int i=0; i<n; ++i) {
		cin >> a[i];
		l=max(l, a[i]-k);
		r=min(r, a[i]+k);
	}
	if(l>r)
		cout << -1 << "\n";
	else
		cout << r << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> q;
	while(q--)
		solve();
}