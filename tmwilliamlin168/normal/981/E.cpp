#include <bits/stdc++.h>
using namespace std;

const int mxN=1e4;
int n, q, l, r, x, k;
vector<int> st[1<<15];
bitset<mxN+1> a1;

void add(int l1, int r1, int x, int i=1, int l2=0, int r2=n-1) {
	if(l1<=l2&&r2<=r1) {
		st[i].push_back(x);
		return;
	}
	int m2=(l2+r2)/2;
	if(l1<=m2)
		add(l1, r1, x, 2*i, l2, m2);
	if(m2<r1)
		add(l1, r1, x, 2*i+1, m2+1, r2);
}

void b(bitset<mxN+1> bs, int i=1, int l2=0, int r2=n-1) {
	for(int vi : st[i])
		bs|=bs<<vi;
	if(l2==r2) {
		a1|=bs;
		return;
	}
	int m2=(l2+r2)/2;
	b(bs, 2*i, l2, m2);
	b(bs, 2*i+1, m2+1, r2);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> q;
	while(q--) {
		cin >> l >> r >> x, --l, --r;
		add(l, r, x);
	}
	b(bitset<mxN+1>(1));
	for(int i=1; i<=n; ++i)
		k+=a1[i];
	cout << k << "\n";
	for(int i=1; i<=n; ++i)
		if(a1[i])
			cout << i << " ";
}