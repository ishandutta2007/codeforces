#include <bits/stdc++.h>
using namespace std;

#define ar array

const int mxN=5e5;
int n, q, a[mxN];

struct node {
	int ls, rs, ts, cl, cr, mn, mx;
} st[1<<20];

ar<int, 2> aa(ar<int, 2> a, int b) {
	return {a[0]+b, a[1]};
}

ar<int, 2> qryl(int i, int l2, int r2, int l3, int r3, int x) {
	if(l3>r3)
		return {0, x};
	if(l2==r2)
		return x>=st[i].cl?ar<int, 2>{0, x}:ar<int, 2>{1, x};
	int m2=(l2+r2)/2, a=0;
	if(l3<st[i].ls+(st[i].cl>0)&&r3>=st[i].ls) {
		if(st[i].cl&&x>=st[i].cl&&x<=st[i].cr)
			return {st[i].ls-l3, st[i].cr};
		if(st[i].cl?x<st[i].cl:x<st[2*i].mn) {
			a=st[i].ls+(st[i].cl>0)-l3;
			l3=st[i].ls+(st[i].cl>0);
		} else
			r3=st[i].ls-1;
	}
	return r3<st[i].ls?qryl(2*i, l2, m2, l3, r3, x):aa(qryl(2*i+1, m2+1, r2, st[2*i+1].ts-st[i].ts+l3, st[2*i+1].ts-st[i].ts+r3, x), a);
}

ar<int, 2> qryr(int i, int l2, int r2, int l3, int r3, int x) {
	if(l3>r3)
		return {0, x};
	if(l2==r2)
		return x<=st[i].cr?ar<int, 2>{0, x}:ar<int, 2>{1, x};
	int m2=(l2+r2)/2, a=0;
	if(l3<st[i].ls+(st[i].cl>0)&&r3>=st[i].ls) {
		if(st[i].cl&&x>=st[i].cl&&x<=st[i].cr)
			return {r3-st[i].ls, st[i].cl};
		if(st[i].cl?x>st[i].cr:x>st[2*i+1].mx) {
			a=r3-st[i].ls+1;
			r3=st[i].ls-1;
		} else
			l3=st[i].ls+(st[i].cl>0);
	}
	return r3<st[i].ls?aa(qryr(2*i, l2, m2, l3, r3, x), a):qryr(2*i+1, m2+1, r2, st[2*i+1].ts-st[i].ts+l3, st[2*i+1].ts-st[i].ts+r3, x);
}

void upd(int l1, int r1, int i=1, int l2=0, int r2=n-1) {
	if(l2==r2) {
		st[i].cl=st[i].cr=st[i].mn=st[i].mx=a[l2];
		st[i].ts=1;
		return;
	}
	int m2=(l2+r2)/2;
	if(l1<=m2)
		upd(l1, r1, 2*i, l2, m2);
	if(m2<r1)
		upd(l1, r1, 2*i+1, m2+1, r2);
	if(st[2*i].mn>st[2*i+1].mx) {
		st[i].cl=0;
		st[i].ls=st[2*i].ts;
		st[i].rs=st[2*i+1].ts;
	} else {
		ar<int, 2> al=qryl(2*i, l2, m2, 0, st[2*i].ts-1, st[2*i+1].mx), ar=qryr(2*i+1, m2+1, r2, 0, st[2*i+1].ts-1, st[2*i].mn);
		st[i].ls=al[0];
		st[i].cl=ar[1];
		st[i].rs=ar[0];
		st[i].cr=al[1];
	}
	st[i].mn=min(st[2*i].mn, st[2*i+1].mn);
	st[i].mx=max(st[2*i].mx, st[2*i+1].mx);
	st[i].ts=st[i].ls+st[i].rs+(st[i].cl>0);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> q;
	for(int i=0; i<n; ++i)
		cin >> a[i];
	upd(0, n-1);
	for(int i, x; q--; ) {
		cin >> i >> x, --i;
		a[i]=x;
		upd(i, i);
		cout << st[1].ts << "\n";
	}
}