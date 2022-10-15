#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		map<int, int> mp;
		for(int i=0; i<n; ++i) {
			cin >> a[i];
			++mp[a[i]];
		}
		int mc=0;
		for(auto p : mp)
			mc=max(p.second, mc);
		int ans=0;
		for(int x=1; x<n; ++x) {
			if(mc==x?x<=mp.size()-1:mc>x&&x<=mp.size()) {
				ans=x;
			}
		}
		cout << ans << "\n";
	}
}