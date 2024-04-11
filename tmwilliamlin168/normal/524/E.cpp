#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5, mxQ=2e5;
int n, m, k, q, st[2*mxN];
ar<int, 2> b[mxQ];
ar<int, 5> c[mxQ];
bool a[mxQ];

void upd(int i, int x, int n) {
	for(st[i+=n]=x; i/=2; )
		st[i]=max(st[2*i], st[2*i+1]);
}

int qry(int l, int r, int n) {
	int a=0;
	for(l+=n, r+=n+1; l<r; ++l/=2, r/=2) {
		if(l&1)
			a=max(a, st[l]);
		if(r&1)
			a=max(a, st[r-1]);
	}
	return a;
}

void solve(int n) {
	sort(b, b+k);
	sort(c, c+q);
	memset(st, 0x3f, 8*n);
	for(int i=q-1, j=k-1; ~i; --i) {
		while(~j&&b[j][0]>=c[i][0]) {
			upd(b[j][1], b[j][0], n);
			--j;
		}
		a[c[i][4]]|=qry(c[i][1], c[i][3], n)<=c[i][2];
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k >> q;
	for(int i=0; i<k; ++i)
		cin >> b[i][0] >> b[i][1], --b[i][0], --b[i][1];
	for(int i=0; i<q; ++i) {
		cin >> c[i][0] >> c[i][1] >> c[i][2] >> c[i][3], --c[i][0], --c[i][1], --c[i][2], --c[i][3];
		c[i][4]=i;
	}
	solve(m);
	for(int i=0; i<k; ++i)
		swap(b[i][0], b[i][1]);
	for(int i=0; i<q; ++i) {
		swap(c[i][0], c[i][1]);
		swap(c[i][2], c[i][3]);
	}
	solve(n);
	for(int i=0; i<q; ++i)
		cout << (a[i]?"YES":"NO") << "\n";
}