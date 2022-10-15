#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e6, M=998244353;
int n, c[mxN];
vector<int> a[mxN];

ll pm(ll b, int p) {
	ll r=1;
	while(p) {
		if(p&1)
			r=r*b%M;
		p/=2;
		b=b*b%M;
	}
	return r;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i=0; i<n; ++i) {
		int k;
		cin >> k;
		a[i]=vector<int>(k);
		for(int j=0; j<k; ++j) {
			cin >> a[i][j], --a[i][j];
			++c[a[i][j]];
		}
	}
	ll ans=0, in=pm(n, M-2);
	for(int i=0; i<n; ++i) {
		ll ca=0;
		for(int j=0; j<a[i].size(); ++j)
			ca=(ca+c[a[i][j]]*in)%M;
		ans=(ans+ca*pm(a[i].size(), M-2))%M;
	}
	cout << ans*in%M;
}