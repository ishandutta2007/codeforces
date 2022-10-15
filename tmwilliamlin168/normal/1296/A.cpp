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
		bool h0=0, h1=0;
		for(int i=0, a; i<n; ++i) {
			cin >> a;
			if(a&1)
				h1=1;
			else
				h0=1;
		}
		if(n&1)
			cout << (h1?"YES":"NO") << "\n";
		else
			cout << (h0&&h1?"YES":"NO") << "\n";
	}
}