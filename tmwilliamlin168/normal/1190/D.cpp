#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int n, x[mxN], y[mxN], m, xc[mxN], fs[mxN], ft[mxN+1];
ar<int, 2> a[mxN];

void upd(int i) {
	if(fs[i])
		return;
	fs[i]=1;
	for(++i; i<=m; i+=i&-i)
		++ft[i];
}

int qry(int i) {
	int r=0;
	for(; i; i-=i&-i)
		r+=ft[i];
	return r;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i=0; i<n; ++i) {
		cin >> x[i] >> y[i];
	}
	memcpy(xc, x, 4*n);
	sort(xc, xc+n);
	m=unique(xc, xc+n)-xc;
	for(int i=0; i<n; ++i) {
		x[i]=lower_bound(xc, xc+m, x[i])-xc;
		a[i]={-y[i], x[i]};
	}
	sort(a, a+n);
	ll ans=0;
	for(int i1=0, i2=0; i1<n; i1=i2) {
		for(; i2<n&&a[i2][0]==a[i1][0]; ++i2)
			upd(a[i2][1]);
		//cout << i1 << " " << i2 << endl;
		ll w=qry(m);
		ans+=w*(w+1)/2;
		//cout << ans << endl;
		int l=-1;
		for(int j=i1; j<i2; ++j) {
			w=qry(a[j][1])-qry(l+1);
			ans-=w*(w+1)/2;
			l=a[j][1];
		}
		w=qry(m)-qry(l+1);
		ans-=w*(w+1)/2;
		//cout << ans << endl;
	}
	cout << ans;
}