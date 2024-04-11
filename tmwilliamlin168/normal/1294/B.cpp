#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n;
ar<int, 2> a[1000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i=0; i<n; ++i) {
			cin >> a[i][0] >> a[i][1];
		}
		sort(a, a+n);
		bool ok=1;
		for(int i=0; i+1<n; ++i)
			ok&=a[i][0]<=a[i+1][0]&&a[i][1]<=a[i+1][1];
		if(!ok) {
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		int x=0, y=0;
		for(int i=0; i<n; ++i) {
			while(x<a[i][0]) {
				cout << 'R';
				++x;
			}
			while(y<a[i][1]) {
				cout << 'U';
				++y;
			}
		}
		cout << "\n";
	}
}