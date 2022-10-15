#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int n;
ll a[mxN];

ll mss(vector<ll> a) {
	ll ans=0, msf=0;
	for(ll b : a) {
		msf=max(msf+b, 0ll);
		ans=max(msf, ans);
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--) {
		cin >> n;
		ll s=0;
		for(int i=0; i<n; ++i) {
			cin >> a[i];
			if(i&1^1)
				s+=a[i];
		}
		vector<ll> b1, b2;
		for(int i=0; i+1<n; i+=2)
			b1.push_back(a[i+1]-a[i]);
		for(int i=1; i+1<n; i+=2)
			b2.push_back(a[i]-a[i+1]);
		cout << s+max({0ll, mss(b1), mss(b2)}) << "\n";
	}
}