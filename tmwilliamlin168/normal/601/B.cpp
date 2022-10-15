#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5;
int n, q, a[mxN], b[mxN], nl[mxN], nr[mxN];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> q;
	for(int i=0; i<n; ++i) {
		cin >> a[i];
		if(i)
			b[i]=abs(a[i]-a[i-1]);
	}
	while(q--) {
		int l, r;
		cin >> l >> r, --l, --r;
		ll ans=0;
		for(int i=l+1; i<=r; ++i) {
			nl[i]=i-1;
			while(nl[i]>l&&b[nl[i]]<b[i])
				nl[i]=nl[nl[i]];
		}
		for(int i=r; i>l; --i) {
			nr[i]=i+1;
			while(nr[i]<=r&&b[nr[i]]<=b[i])
				nr[i]=nr[nr[i]];
			ans+=(ll)(i-nl[i])*(nr[i]-i)*b[i];
		}
		cout << ans << "\n";
	}
}