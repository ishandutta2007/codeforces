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
		int a[n];
		bool b0=0, b1=0;
		for(int i=0; i<n; ++i) {
			cin >> a[i];
			if(a[i]&1)
				b1=1;
			else
				b0=1;
		}
		cout << (b0&&b1?"NO":"YES") << "\n";
	}
}