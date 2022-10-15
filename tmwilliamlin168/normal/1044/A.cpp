#include <bits/stdc++.h>
using namespace std;

const int mxN=1e5;
int n, m, a[mxN+1], x1, x2, y, b[mxN], k, ans=1e6;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i=0; i<n; ++i)
		cin >> a[i];
	a[n]=1e9;
	sort(a, a+n+1);
	for(int i=0; i<m; ++i) {
		cin >> x1 >> x2 >> y;
		if(x1>1)
			continue;
		b[k++]=x2;
	}
	sort(b, b+k);
	for(int i1=0, i2=0; i1<=n; ++i1) {
		while(i2<k&&b[i2]<a[i1])
			++i2;
		ans=min(i1+k-i2, ans);
	}
	cout << ans;
}