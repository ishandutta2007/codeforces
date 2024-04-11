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
		ll a, b, n;
		cin >> a >> b >> n;
		int ans=0;
		while(max(a, b)<=n) {
			if(a<b)
				a+=b;
			else
				b+=a;
			++ans;
		}
		cout << ans << "\n";
	}
}