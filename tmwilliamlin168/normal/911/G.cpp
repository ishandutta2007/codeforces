#include <bits/stdc++.h>
using namespace std;

int *a;
int segtree[1<<19][101];

inline void push(int i) {
	if(i>=1<<18)
		return;
	for(int j=1; j<=100; ++j) {
		segtree[2*i][j]=segtree[i][segtree[2*i][j]];
		segtree[2*i+1][j]=segtree[i][segtree[2*i+1][j]];
	}
	for(int j=1; j<=100; ++j)
		segtree[i][j]=j;
}

void upd(int i, int l1, int r1, int l2, int r2, int x, int y) {
	if(l2<=l1&&r1<=r2) {
		for(int j=1; j<=100; ++j)
			if(segtree[i][j]==x)
				segtree[i][j]=y;
		return;
	}
	push(i);
	int m=(l1+r1)/2;
	if(l2<=m)
		upd(2*i, l1, m, l2, r2, x, y);
	if(m<r2)
		upd(2*i+1, m+1, r1, l2, r2, x, y);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	for(int i=1; i<1<<19; ++i)
		for(int j=1; j<=100; ++j)
			segtree[i][j]=j;
	int n, q;
	cin >> n;
	a = new int[n];
	for(int i=0; i<n; ++i)
		cin >> a[i];
	cin >> q;
	while(q--) {
		int l, r, x, y;
		cin >> l >> r >> x >> y;
		upd(1, 0, (1<<18)-1, l-1, r-1, x, y);
	}
	for(int i=1; i<1<<18; ++i)
		push(i);
	for(int i=0; i<n; ++i)
		cout << segtree[(1<<18)+i][a[i]] << " ";
}