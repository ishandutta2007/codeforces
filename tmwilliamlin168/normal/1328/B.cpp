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
		ll k;
		cin >> n >> k, --k;
		int p1, p2;
		for(int i=n-2; ~i; --i) {
			if(k<n-1-i) {
				p1=i;
				p2=n-1-k;
				break;
			}
			k-=n-1-i;
		}
		for(int i=0; i<n; ++i) {
			if(i==p1||i==p2)
				cout << 'b';
			else
				cout << 'a';
		}
		cout << "\n";
	}
}