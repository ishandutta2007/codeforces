#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxQ=3e5;

int n, q, ql[mxQ], qr[mxQ], qk[mxQ], coords[mxQ*2+2];

int treeA[1<<21], treeL[1<<21];
inline void push(int i, int l, int r) {
	if(treeL[i]==-1)
		return;
	treeA[i]=(coords[min(r+1, 2*q+1)]-coords[l])*treeL[i];
	if(l<r)
		treeL[2*i]=treeL[2*i+1]=treeL[i];
	treeL[i]=-1;
}
void upd(int i, int l, int r, int l2, int r2, int x) {
	if(l2<=l&&r<=r2) {
		treeL[i]=x;
		push(i, l, r);
	} else {
		int m=(l+r)/2;
		push(2*i, l, m);
		push(2*i+1, m+1, r);
		if(l2<=m)
			upd(2*i, l, m, l2, r2, x);
		if(m<r2)
			upd(2*i+1, m+1, r, l2, r2, x);
		treeA[i]=treeA[2*i]+treeA[2*i+1];
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> q;
	for(int i=0; i<q; ++i) {
		cin >> ql[i] >> qr[i] >> qk[i];
		--ql[i], --qk[i];
		coords[i*2]=ql[i];
		coords[i*2+1]=qr[i];
	}
	coords[q*2]=n;
	sort(coords, coords+q*2+2);
	upd(1, 0, q*2+1, 0, q*2+1, 1);
	for(int i=0; i<q; ++i) {
		upd(1, 0, q*2+1, lower_bound(coords, coords+q*2+2, ql[i])-coords, lower_bound(coords, coords+q*2+2, qr[i])-coords-1, qk[i]);
		cout << treeA[1] << "\n";
	}
}