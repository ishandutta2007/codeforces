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
		for(int i=0; i<n; ++i)
			cin >> a[i];
		if(n<3) {
			cout << 0 << endl;
			continue;
		}
		sort(a, a+n);
		cout << min(n-2, a[n-2]-1) << endl;
	}
}