#include <bits/stdc++.h>
using namespace std;

const int mxN1=1e5, mxN2=1<<18, INF=1e9;

struct dat {
	int len=0, max;
	vector<pair<int, int>> pref, suf;
} tree[mxN2];

int n, q, qt;
string ss[mxN1];

inline void cmb(dat &d, dat &a, dat &b) {
	d.len=a.len+b.len;
	d.max=max(a.max, b.max);
	for(int i1=0, i2=0; i1<a.suf.size()-1;) {
		if(a.suf[i1].first<=b.pref[i2].first) {
			d.max=max(a.suf[i1].first*(a.suf[i1].second+b.pref[i2].second+1), d.max);
			++i1;
		} else {
			d.max=max(b.pref[i2].first*(a.suf[i1].second+b.pref[i2].second+1), d.max);
			++i2;
		}
	}
	int i1=0, i2=0;
	d.pref.clear();
	if(a.pref[0].second==a.len)
		for(; b.pref[i2].first<a.pref[0].first; ++i2)
			d.pref.push_back(make_pair(b.pref[i2].first, a.len+b.pref[i2].second));
	for(; i1<a.pref.size();) {
		if(a.pref[i1].first<=b.pref[i2].first) {
			d.pref.push_back(make_pair(a.pref[i1].first, a.pref[i1].second==a.len?a.len+b.pref[i2].second:a.pref[i1].second));
			++i1;
		} else
			++i2;
	}
	i1=0, i2=0;
	d.suf.clear();
	if(b.suf[0].second==b.len)
		for(; a.suf[i2].first<b.suf[0].first; ++i2)
			d.suf.push_back(make_pair(a.suf[i2].first, b.len+a.suf[i2].second));
	for(; i1<b.suf.size();) {
		if(b.suf[i1].first<=a.suf[i2].first) {
			d.suf.push_back(make_pair(b.suf[i1].first, b.suf[i1].second==b.len?b.len+a.suf[i2].second:b.suf[i1].second));
			++i1;
		} else
			++i2;
	}
}

void bld(int l, int r, int i) {
	if(l==r) {
		int j=0;
		for(; j<ss[l].size()&&j<ss[l+1].size()&&ss[l][j]==ss[l+1][j]; ++j);
		tree[i].len=1;
		tree[i].max=max(j*2, (int)max(ss[l].size(), ss[l+1].size()));
		tree[i].pref={make_pair(j, 1), make_pair(INF, 0)};
		tree[i].suf={make_pair(j, 1), make_pair(INF, 0)};
	} else {
		int m=(l+r)/2;
		bld(l, m, 2*i);
		bld(m+1, r, 2*i+1);
		cmb(tree[i], tree[2*i], tree[2*i+1]);
	}
}

void upd(int i2, int i, int l, int r) {
	if(l==r) {
		int j=0;
		for(; j<ss[l].size()&&j<ss[l+1].size()&&ss[l][j]==ss[l+1][j]; ++j);
		tree[i].max=max(j*2, (int)max(ss[l].size(), ss[l+1].size()));
		tree[i].pref[0].first=tree[i].suf[0].first=j;
	} else {
		int m=(l+r)/2;
		if(i2<=m)
			upd(i2, 2*i, l, m);
		else
			upd(i2, 2*i+1, m+1, r);
		cmb(tree[i], tree[2*i], tree[2*i+1]);
	}
}

dat qry(int l2, int r2, int i, int l, int r) {
	if(l2<=l&&r<=r2)
		return tree[i];
	dat res;
	int m=(l+r)/2;
	bool lc=l2<=m, rc=m<r2;
	if(lc&&rc) {
		dat lr=qry(l2, r2, 2*i, l, m), rr=qry(l2, r2, 2*i+1, m+1, r);
		cmb(res, lr, rr);
	} else if(lc)
		res=qry(l2, r2, 2*i, l, m);
	else
		res=qry(l2, r2, 2*i+1, m+1, r);
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> q;
	for(int i=0; i<n; ++i)
		cin >> ss[i];
	if(n>1)
		bld(0, n-2, 1);
	while(q--) {
		cin >> qt;
		if(qt==1) {
			int a, b;
			cin >> a >> b;
			--a, --b;
			cout << (a==b?ss[a].size():qry(a, b-1, 1, 0, n-2).max) << "\n";
		} else {
			int x;
			cin >> x;
			--x;
			cin >> ss[x];
			if(n>1) {
				if(x)
					upd(x-1, 1, 0, n-2);
				upd(x, 1, 0, n-2);
			}
		}
	}
}