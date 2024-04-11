#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define array a

const int mxN=3e5;
int n, m, p[mxN], ui, vi;
ll x[mxN], y[mxN], ans[mxN], px[mxN+1], py[mxN+1];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i=0; i<n; ++i) {
		cin >> x[i] >> y[i];
		p[i]=i;
	}
	sort(p, p+n, [&](const int &i, const int &j) {
		return x[i]-y[i]<x[j]-y[j];
	});
	for(int i=0; i<n; ++i)
		px[i+1]=px[i]+x[p[i]];
	for(int i=n-1; i>=0; --i)
		py[i]=py[i+1]+y[p[i]];
	for(int i=0; i<n; ++i)
		ans[p[i]]=px[i]+py[i+1]+i*y[p[i]]+(n-1-i)*x[p[i]];
	while(m--) {
		cin >> ui >> vi, --ui, --vi;
		ll s=min(x[ui]+y[vi], x[vi]+y[ui]);
		ans[ui]-=s;
		ans[vi]-=s;
	}
	for(int i=0; i<n; ++i)
		cout << ans[i] << " ";
}