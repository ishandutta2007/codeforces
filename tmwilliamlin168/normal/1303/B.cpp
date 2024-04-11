#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--) {
		ll n, g, b;
		cin >> n >> g >> b;
		ll m=(n+1)/2;
		ll ans=(m-1)/g*(g+b)+(m%g?m%g:g);
		cout << max(ans, n) << "\n";
	}
}