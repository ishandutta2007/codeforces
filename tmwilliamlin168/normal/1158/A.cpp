#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	int a[n], b[m];
	for(int i=0; i<n; ++i)
		cin >> a[i];
	sort(a, a+n);
	for(int j=0; j<m; ++j)
		cin >> b[j];
	sort(b, b+m);
	if(a[n-1]>b[0]) {
		cout << -1;
		return 0;
	}
	ll ans=0;
	for(int i=0; i<n; ++i)
		ans+=(ll)m*a[i];
	for(int i=1; i<m; ++i)
		ans+=b[i]-a[n-1];
	if(b[0]>a[n-1])
		ans+=b[0]-a[n-2];
	cout << ans;
}