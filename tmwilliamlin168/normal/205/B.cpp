#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int a[n];
	ll ans=0;
	for(int i=0; i<n; ++i) {
		cin >> a[i];
		if(i)
			ans+=max(a[i-1]-a[i], 0);
	}
	cout << ans;
}