#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mxM=1e5;
int n, k, l, m, a[mxM];
ll ans;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k >> l;
	m=n*k;
	for(int i=0; i<m; ++i)
		cin >> a[i];
	sort(a, a+m);
	ans=a[0];
	--n;
	int i=0;
	while(i+1<m&&a[i+1]-a[0]<=l)
		++i;
	if(i<n) {
		cout << 0;
		return 0;
	}
	int l=0, j=1;
	while(n&&j<m) {
		if(j-l>=k||j>=i-n+1) {
			ans+=a[j];
			l=j;
			--n;
		}
		++j;
	}
	cout << ans;
}