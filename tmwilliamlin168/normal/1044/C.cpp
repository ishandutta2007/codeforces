#include <bits/stdc++.h>
using namespace std;

const int mxN=3e5;
int n, x[mxN], y[mxN], mnx=1e9, mxx=-1e9, mny=1e9, mxy=-1e9, a1;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i=0; i<n; ++i) {
		cin >> x[i] >> y[i];
		mnx=min(x[i], mnx);
		mxx=max(x[i], mxx);
		mny=min(y[i], mny);
		mxy=max(y[i], mxy);
	}
	for(int i=0; i<n; ++i) {
		a1=max(x[i]-mnx+y[i]-mny, a1);
		a1=max(x[i]-mnx+mxy-y[i], a1);
		a1=max(mxx-x[i]+y[i]-mny, a1);
		a1=max(mxx-x[i]+mxy-y[i], a1);
	}
	cout << 2*a1;
	for(int i=4; i<=n; ++i)
		cout << " " << 2*(mxx-mnx+mxy-mny);
}