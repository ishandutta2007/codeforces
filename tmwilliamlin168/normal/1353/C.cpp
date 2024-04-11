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
		ll n;
		cin >> n;
		ll ans=0;
		for(int i=1; i<=(n-1)/2; ++i) {
			ans+=8ll*i*i;
		}
		cout << ans << "\n";
	}
}