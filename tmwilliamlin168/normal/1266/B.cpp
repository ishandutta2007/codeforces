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
		ll x;
		cin >> x;
		cout << (x>14&&x%14>0&&x%14<7?"YES":"NO") << "\n";
	}
}