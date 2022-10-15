#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--) {
		int n;
		string s;
		cin >> n >> s;
		ar<int, 2> a={};
		map<ar<int, 2>, int> mp;
		mp[a]=0;
		int ans=1e9, ml=0;
		for(int i=0; i<n; ++i) {
			if(s[i]=='L')
				--a[0];
			if(s[i]=='R')
				++a[0];
			if(s[i]=='D')
				--a[1];
			if(s[i]=='U')
				++a[1];
			if(mp.find(a)!=mp.end()) {
				int b=i+1-mp[a];
				//ans=min(i+1-mp[a], ans);
				if(b<ans) {
					ml=mp[a];
					ans=b;
				}
			}
			mp[a]=i+1;
		}
		//cout << (ans>n?-1:ans) << "\n";
		if(ans>n)
			cout << "-1\n";
		else
			cout << ml+1 << " " << ml+ans << "\n";
	}
}