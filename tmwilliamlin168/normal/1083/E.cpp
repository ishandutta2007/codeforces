#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e6;
const ll INF=1e18;
int n, qh, qt, d[mxN];
ll x[mxN], y[mxN], p[mxN], a[mxN+1], b[mxN+1], ans;

void al(ll ai, ll bi) {
	while(qt-qh>=2&&(b[qt-1]-b[qt-2])/(a[qt-2]-a[qt-1])>=(bi-b[qt-1])/(a[qt-1]-ai))
		--qt;
	a[qt]=ai, b[qt]=bi;
	++qt;
}

ll qry(ll xi) {
	while(qt-qh>=2&&a[qh]*xi+b[qh]<=a[qh+1]*xi+b[qh+1])
		++qh;
	return a[qh]*xi+b[qh];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i=0; i<n; ++i)
		cin >> x[i] >> y[i] >> p[i], d[i]=i;
	sort(d, d+n, [&](const int &i, const int &j) {
		return x[i]<x[j];
	});
	al(0, 0);
	for(int i=0; i<n; ++i) {
		int j=d[i];
//		cout << j << endl;
//		cout << qry(-y[j]) << endl;
		ll dp=max(qry(-y[j])+x[j]*y[j]-p[j], -INF);
		al(x[j], dp);
//		cout << dp << endl;
		ans=max(dp, ans);
	}
	cout << ans;
}