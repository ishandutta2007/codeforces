#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN=2e5;
int n, ft[mxN+2], a[mxN+1];
ll t, ps[mxN+1], rs, ans;

void upd(int i) {
	for(++i; i<=n+1; i+=i&-i)
		++ft[i];
}

int qry(int i) {
	int r=0;
	for(; i; i-=i&-i)
		r+=ft[i];
	return r;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> t, t=-t;
	for(int i=0; i<n; ++i) {
		cin >> a[i], a[i]=-a[i];
		ps[i+1]=a[i]+ps[i];
	}
	sort(ps, ps+n+1);
	for(int i=0; i<=n; rs+=a[i], ++i) {
		ans+=qry(upper_bound(ps, ps+n+1, rs-t-1)-ps);
		upd(lower_bound(ps, ps+n+1, rs)-ps);
	}
	cout << ans;
}