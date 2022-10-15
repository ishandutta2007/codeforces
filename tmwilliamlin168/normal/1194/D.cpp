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
		if(k%3)
			cout << (n%3?"Alice":"Bob") << "\n";
		else {
			ll a=n%(k+1);
			cout << (a%3||a==k?"Alice":"Bob") << "\n";
		}
	}
}