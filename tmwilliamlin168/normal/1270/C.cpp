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
		int n;
		cin >> n;
		vector<ll> a;
		ll s=0, x=0;
		for(int i=0; i<n; ++i) {
			ll ai;
			cin >> ai;
			a.push_back(ai);
			s+=ai;
			x^=ai;
		}
		cout << "2\n" << x << " " << s+x << "\n";
	}
}