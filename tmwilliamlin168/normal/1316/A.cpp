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
		int n, m;
		cin >> n >> m;
		ll s=0;
		for(int i=0; i<n; ++i) {
			int a;
			cin >> a;
			s+=a;
		}
		cout << min(s, (ll)m) << "\n";
	}
}