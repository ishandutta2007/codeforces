#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, k, m, st[1<<20], lz[1<<20];

void bld(int i=1, int l2=0, int r2=2*n-2) {
	if(l2==r2) {
		st[i]=l2-n;
		return;
	}
	int m2=(l2+r2)/2;
	bld(2*i, l2, m2);
	bld(2*i+1, m2+1, r2);
	st[i]=max(st[2*i], st[2*i+1]);
}

void app(int i, int x) {
	st[i]+=x;
	lz[i]+=x;
}

void psh(int i) {
	app(2*i, lz[i]);
	app(2*i+1, lz[i]);
	lz[i]=0;
}

void upd(int l1, int r1, int x, int i=1, int l2=0, int r2=2*n-2) {
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
	st[i]=max(st[2*i], st[2*i+1]);
}

int qry(int l1, int r1, int i=1, int l2=0, int r2=2*n-2) {
	if(l1<=l2&&r2<=r1) {
		return st[i];
	}
	int m2=(l2+r2)/2;
	psh(i);
	return max(l1<=m2?qry(l1, r1, 2*i, l2, m2):0, m2<r1?qry(l1, r1, 2*i+1, m2+1, r2):0);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k >> m, --k;
	map<ar<int, 2>, int> mp;
	bld();
	set<ar<int, 3>> s;
	while(m--) {
		int x, y;
		cin >> x >> y, --x, --y;
		ar<int, 2> a={x, y};
			int r=abs(x-k)+y;
		if(mp.find(a)==mp.end()) {
			upd(0, r, 1);
			mp[a]=r;
			s.insert({r, x, y});
		} else {
			upd(0, mp[a], -1);
			mp.erase(a);
			s.erase({r, x, y});
		}
		if(s.empty())
			cout << "0\n";
		else {
			cout << max(qry(0, (*--s.end())[0]), 0) << "\n";
		}
	}
}