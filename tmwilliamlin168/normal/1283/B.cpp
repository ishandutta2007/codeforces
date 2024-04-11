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
		ll n, k;
		cin >> n >> k;
		ll e=n%k;
		e=min(e, k/2);
		cout << n/k*k+e << endl;
	}
}