#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int n, p[mxN], q[mxN], a[mxN];
ll st[1<<19], lz[1<<19];

void app(int i, ll x) {
	st[i]+=x;
	lz[i]+=x;
}

void psh(int i) {
	app(2*i, lz[i]);
	app(2*i+1, lz[i]);
	lz[i]=0;
}

void upd(int l1, int r1, ll x, int i=1, int l2=0, int r2=n-2) {
	if(l1>r1)
		return;
	if(l1<=l2&&r2<=r1) {
		app(i, x);
		return;
	}
	int m2=(l2+r2)/2;
	psh(i);
	if(l1<=m2)
		upd(l1, r1, x, 2*i, l2, m2);
	if(m2<r1)
		upd(l1, r1, x, 2*i+1, m2+1, r2);
	st[i]=min(st[2*i], st[2*i+1]);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i=0; i<n; ++i) {
		cin >> p[i], --p[i];
		q[p[i]]=i;
	}
	for(int i=0; i<n; ++i) {
		cin >> a[i];
		upd(i, n-2, a[i]);
	}
	ll ans=st[1];
	for(int i=0; i<n; ++i) {
		int j=q[i];
		upd(0, j-1, a[j]);
		upd(j, n-2, -a[j]);
		ans=min(ans, st[1]);
	}
	cout << ans;
}