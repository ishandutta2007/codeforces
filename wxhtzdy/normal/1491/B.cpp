#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, u, v;
	cin >> n >> u >> v;
	int a[n];
	for(int i=0; i<n; ++i)
		cin >> a[i];
	for(int i=1; i<n; ++i)
		if(abs(a[i]-a[i-1])>=2) {
			cout << "0\n";
			return;
		}
	for(int i=1; i<n; ++i) 
		if(abs(a[i]-a[i-1])==1) {
			cout << min(u, v) << "\n";
			return;
		}
	cout << v+min(u, v) << "\n";
}

int main() { 
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while(tt--) 
		solve();
	return 0;
}