#include <bits/stdc++.h>
using namespace std;

const int mxN=1e5;
int n, m, y1, y2, a[mxN], b[mxN], ans=2;
unordered_map<int, int> mp;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> y1;
	for(int i=0; i<n; ++i)
		cin >> a[i];
	cin >> m >> y2;
	for(int i=0; i<m; ++i)
		cin >> b[i];
	for(int k=2; k<1e9; k*=2) {
		for(int i=0; i<n; ++i)
			++mp[a[i]&(k-1)];
		for(int i=0; i<m; ++i)
			++mp[(b[i]+k/2)&(k-1)];
		for(auto it=mp.begin(); it!=mp.end(); ++it)
			ans=max(it->second, ans);
		mp.clear();
	}
	cout << ans;
}