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
		string s;
		cin >> s;
		int n=s.size();
		map<int, int> mp;
		int c=0;
		for(int i=0; i<n; ++i) {
			if(s[i]=='+')
				++c;
			else
				--c;
			if(mp.find(c)==mp.end())
				mp[c]=i+1;
		}
		ll ans=0;
		for(int i=-1; ; --i) {
			if(mp.find(i)==mp.end())
				break;
			ans+=mp[i];
		}
		cout << ans+n << "\n";
	}
}