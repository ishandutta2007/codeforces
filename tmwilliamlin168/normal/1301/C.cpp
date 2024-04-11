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
		ll n, m;
		cin >> n >> m;
		ll a=(n-m)/(m+1), b=(m+1)*a*(a+1)/2;
		b+=(a+1)*((n-m)%(m+1));
		cout << n*(n+1)/2-b << "\n";
	}
}