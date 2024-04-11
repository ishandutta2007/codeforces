#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n;
ar<int, 2> a[200000];
vector<int> v;

struct node {
	bool lc, rc, ac;
	int ans, lz;
} st[1<<20];

void cmb(int i) {
	if(st[i].lz)
		return;
	if(st[2*i].ac&&st[2*i+1].ac) {
		st[i].ac=1;
		st[i].ans=0;
	} else {
		st[i].ac=0;
		st[i].lc=st[2*i].ac||st[2*i].lc;
		st[i].rc=st[2*i+1].ac||st[2*i+1].rc;
		st[i].ans=st[2*i].ans+st[2*i+1].ans+(!st[2*i].ac&&!st[2*i+1].ac&&(st[2*i].rc||st[2*i+1].lc));
	}
}

void bld(int i=1, int l2=0, int r2=v.size()-1) {
	st[i].lz=0;
	if(l2==r2) {
		st[i].ac=1;
		//st[i].lc=st[i].rc=0;
		st[i].ans=0;
		return;
	}
	int m2=(l2+r2)/2;
	bld(2*i, l2, m2);
	bld(2*i+1, m2+1, r2);
	cmb(i);
}

void app(int i, int x, int l2, int r2) {
	st[i].lz+=x;
	if(st[i].lz) {
		st[i].lc=st[i].rc=st[i].ac=0;
		st[i].ans=0;
	} else {
		if(l2==r2) {
			st[i].ac=1;
			st[i].ans=0;
		} else {
			cmb(i);
		}
	}
}

void upd(int l1, int r1, int x, int i=1, int l2=0, int r2=v.size()-1) {
	if(l1<=l2&&r2<=r1) {
		app(i, x, l2, r2);
		return;
	}
	int m2=(l2+r2)/2;
	if(l1<=m2)
		upd(l1, r1, x, 2*i, l2, m2);
	if(m2<r1)
		upd(l1, r1, x, 2*i+1, m2+1, r2);
	cmb(i);
}

int vf(int x) {
	return lower_bound(v.begin(), v.end(), x)-v.begin();
}

void solve() {
	cin >> n;
	v.clear();
	for(int i=0; i<n; ++i) {
		cin >> a[i][0] >> a[i][1];
		a[i][0]*=2, a[i][1]*=2;
		v.push_back(a[i][0]);
		v.push_back(a[i][1]+1);
	}
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end())-v.begin());
	bld();
	for(int i=0; i<n; ++i)
		upd(vf(a[i][0]), vf(a[i][1]+1)-1, 1);
	int ans=-1e9;
	for(int i=0; i<n; ++i) {
		upd(vf(a[i][0]), vf(a[i][1]+1)-1, -1);
		ans=max(ans, st[1].ans);
		upd(vf(a[i][0]), vf(a[i][1]+1)-1, 1);
	}
	cout << ans+1 << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--)
		solve();
}