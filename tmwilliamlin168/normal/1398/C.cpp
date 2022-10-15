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
		cin >> n;
		string a;
		cin >> a;
		int s=0;
		ll ans=0;
		map<int, int> mp;
		mp[0]++;
		for(int i=0; i<n; ++i) {
			s+=a[i]-'0';
			ans+=mp[s-(i+1)];
			++mp[s-(i+1)];
		}
		cout << ans << "\n";
	}
}