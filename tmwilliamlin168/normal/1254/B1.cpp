#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e6;
int n, a[mxN];
ll ans=1e18;

void test(ll x) {
	ll ca=0;
	ll ar=a[0];
	for(int i=0; i<n; ++i) {
		ll d=ar%x;
		//ca+=min(a[0]%x, x-a[0]%x);
		ca+=min(d, x-d);
		if(i<n)
			ar=a[i+1]+d;
	}
	ans=min(ca, ans);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	ll n2=0;
	for(int i=0; i<n; ++i) {
		cin >> a[i];
		n2+=a[i];
	}
	
	if(n2<2) {
		cout << -1;
		return 0;
	}

	for(ll i=2; i*i<=n2; ++i) {
		if(n2%i)
			continue;
		while(n2%i==0) {
			n2/=i;
		}
		test(i);
	}
	if(n2>1)
		test(n2);
	cout << ans;
}