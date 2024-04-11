#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5;
int n, a[mxN*2];

void solve() {
	cin >> n;
	int c0=0;
	for(int i=0; i<2*n; ++i) {
		cin >> a[i];
		if(a[i]==1)
			++c0;
		else
			--c0;
	}
	map<int, int> mp;
	mp[0]=0;
	for(int i=1, b=0; i<=n; ++i) {
		if(a[n-i]==1)
			++b;
		else
			--b;
		if(mp.find(b)==mp.end())
			mp[b]=i;
	}
	int ans=2*n;
	for(int i=0, b=0; i<=n; ++i) {
		if(i) {
			if(a[n+i-1]==1)
				++b;
			else
				--b;
		}
		if(mp.find(c0-b)!=mp.end())
			ans=min(ans, i+mp[c0-b]);
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