#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()

#define F_OR(i, a, b, s) for (int i = (a); ((s) > 0 ? i < (b) : i > (b)); i += (s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)

const int mxN=5e5;
int n, q;
string s;

struct node {
	int len, pre[2], suf[2], ans[2], pre2[2], suf2[2];
} st[1<<20];
bool lz[1<<20];

node cmb(node l, node r) {
	node a;
	a.len=l.len+r.len;
	for(int k : {0, 1}) {
		a.pre[k]=l.pre[k]==l.len?l.len+r.pre[k]:l.pre[k];
		a.suf[k]=r.suf[k]==r.len?r.len+l.suf[k]:r.suf[k];
		a.ans[k]=max({l.ans[k], r.ans[k], l.suf2[k]+r.pre[k], l.suf[k]+r.pre2[k]});
	}
	for(int k : {0, 1}) {
		a.pre2[k]=l.suf[k]==l.len?l.len+r.pre2[k]:(l.pre2[k]==l.len?l.len+r.pre[k]:l.pre2[k]);
		a.suf2[k]=r.pre[k]==r.len?r.len+l.suf2[k]:(r.suf2[k]==r.len?r.len+l.suf[k]:r.suf2[k]);
	}
	return a;
}

void pr(int i) {
	//return;
	cout << "n " << i << endl;
	cout << st[i].len << endl;
	for(int k : {0, 1}) {
		cout << st[i].pre[k] << " " << st[i].suf[k] << " " << st[i].pre2[k] << " " << st[i].suf2[k] << " " << st[i].ans[k] << endl;
	}
}

void bld(int i=1, int l2=0, int r2=n-1) {
	if(l2==r2) {
		st[i].len=1;
		int k=s[l2]!='<';
		st[i].pre[k]=1;
		st[i].suf[k^1]=1;
		for(int j : {0, 1})
			st[i].pre2[j]=st[i].suf2[j]=st[i].ans[j]=1;
		return;
	}
	int m2=(l2+r2)/2;
	bld(2*i, l2, m2);
	bld(2*i+1, m2+1, r2);
	st[i]=cmb(st[2*i], st[2*i+1]);
	//pr(i);
}

void app(int i, bool x) {
	if(x) {
		swap(st[i].pre[0], st[i].pre[1]);
		swap(st[i].suf[0], st[i].suf[1]);
		swap(st[i].pre2[0], st[i].pre2[1]);
		swap(st[i].suf2[0], st[i].suf2[1]);
		swap(st[i].ans[0], st[i].ans[1]);
	}
	lz[i]^=x;
}

void psh(int i) {
	app(2*i, lz[i]);
	app(2*i+1, lz[i]);
	lz[i]=0;
}

void upd(int l1, int r1, int i=1, int l2=0, int r2=n-1) {
	if(l1<=l2&&r2<=r1) {
		app(i, 1);
		return;
	}
	int m2=(l2+r2)/2;
	psh(i);
	if(l1<=m2)
		upd(l1, r1, 2*i, l2, m2);
	if(m2<r1)
		upd(l1, r1, 2*i+1, m2+1, r2);
	st[i]=cmb(st[2*i], st[2*i+1]);
	//pr(i);
}

node qry(int l1, int r1, int i=1, int l2=0, int r2=n-1) {
	if(l1<=l2&&r2<=r1)
		return st[i];
	int m2=(l2+r2)/2;
	psh(i);
	if(r1<=m2)
		return qry(l1, r1, 2*i, l2, m2);
	if(m2<l1)
		return qry(l1, r1, 2*i+1, m2+1, r2);
	return cmb(qry(l1, r1, 2*i, l2, m2), qry(l1, r1, 2*i+1, m2+1, r2));
}

void pr2(int i=1, int l2=0, int r2=n-1) {
	pr(i);
	if(l2<r2) {
		int m2=(l2+r2)/2;
		pr2(2*i, l2, m2);
		pr2(2*i+1, m2+1, r2);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> q >> s;
	bld();
	while(q--) {
		int l, r;
		cin >> l >> r, --l, --r;
		upd(l, r);
		//pr2();
		cout << qry(l, r).ans[0] << "\n";
	}
}