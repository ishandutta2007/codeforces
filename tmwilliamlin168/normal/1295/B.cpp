#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int a[100000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--) {
		int n;
		ll x;
		cin >> n >> x;
		int s=0;
		map<ll, int> mp;
		string t;
		cin >> t;
		for(int i=0; i<n; ++i) {
			++mp[s];
			//cin >> a[i];
			a[i]=t[i]-'0';
			if(a[i])
				a[i]=-1;
			else
				a[i]=1;
			s+=a[i];
		}
		if(!s) {
			cout << (mp[x]?-1:0) << "\n";
			continue;
		}
		ll ans=0;
		if(s<0) {
			if(x<-n)
				x+=(-x-n)/(-s)*(-s);
		} else {
			if(x>n)
				x-=(x-n)/s*s;
		}
		//cout << x << endl;
		for(int i=0; i<=2*n+69; ++i) {
			ans+=mp[x];
			x-=s;
		}
		cout << ans << "\n";
	}
}