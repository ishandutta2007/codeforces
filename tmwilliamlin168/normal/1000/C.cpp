#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN=2e5;
int n, a[2*mxN];
ll l[mxN], r[mxN], pts[2*mxN], ans[mxN+1];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i=0; i<n; ++i) {
		cin >> l[i] >> r[i];
		pts[2*i]=l[i];
		pts[2*i+1]=r[i]+1;
	}
	sort(pts, pts+2*n);
	for(int i=0; i<n; ++i) {
		++a[lower_bound(pts, pts+2*n, l[i])-pts];
		--a[upper_bound(pts, pts+2*n, r[i])-pts];
	}
	for(int i=0; i<2*n-1; ++i) {
		ans[a[i]]+=pts[i+1]-pts[i];
		a[i+1]+=a[i];
	}
	for(int i=1; i<=n; ++i)
		cout << ans[i] << " ";
}