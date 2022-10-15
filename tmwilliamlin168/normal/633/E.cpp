#include <bits/stdc++.h>
using namespace std;

const int mxN=1e6;
int n, k, v[mxN], c[mxN], a[mxN];
double ans, cp=1;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	for(int i=0; i<n; ++i)
		cin >> v[i], v[i]*=100;
	for(int i=0; i<n; ++i)
		cin >> c[i];
	a[n-1]=min(v[n-1], c[n-1]);
	for(int i=n-2; i>=0; --i)
		a[i]=min(max(v[i], a[i+1]), c[i]);
	sort(a, a+n);
	for(int i=0; i<=n-k; cp=cp*(n-k-i)/(n-1-i), ++i)
		ans+=(double)a[i]*cp;
	cout << fixed << setprecision(9) << ans*k/n;
}