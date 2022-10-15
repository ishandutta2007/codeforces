#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int q;
	cin >> q;
	while(q--) {
		ll n;
		cin >> n;
		int ans=0;
		while(n>1) {
			if(n%2==0)
				n/=2;
			else if(n%3==0) {
				n/=3;
				++ans;
			} else if(n%5==0) {
				n/=5;
				ans+=2;
			} else {
				ans=-1;
				break;
			}
			++ans;
		}
		cout << ans << "\n";
	}
}