#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=3500;
int n, m, k, a[mxN];

void solve() {
	cin >> n >> m >> k;
	for(int i=0; i<n; ++i)
		cin >> a[i];
	k=min(k, m-1);
	int ans=0;
	for(int i=0; i<=k; ++i) {
		int ca=1e9;
		for(int j=0; j<=m-1-k; ++j)
			ca=min(ca, max(a[i+j], a[i+j+n-m]));
		ans=max(ca, ans);
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--)
		solve();
}