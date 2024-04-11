#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define fi first
#define se second

const int mxN=2e5;
int n, s, a[mxN];
ll ans;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> s;
	for(int i=0; i<n; ++i)
		cin >> a[i];
	sort(a, a+n);
	ans+=abs(a[n/2]-s);
	a[n/2]=s;
	for(int i=n/2+1; i<n&&a[i]<s; ++i) {
		ans+=abs(a[i]-s);
		a[i]=s;
	}
	for(int i=n/2-1; i>=0&&a[i]>s; --i) {
		ans+=abs(a[i]-s);
		a[i]=s;
	}
	cout << ans;
}