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
		int n, k;
		cin >> n >> k;
		int a[n], b[n];
		for(int i=0; i<n; ++i)
			cin >> a[i];
		for(int i=0; i<n; ++i)
			cin >> b[i];
		while(k--) {
			sort(a, a+n);
			sort(b, b+n);
			if(b[n-1]>a[0]) {
				swap(a[0], b[n-1]);
			} else
				break;
		}
		int s=0;
		for(int i=0; i<n; ++i)
			s+=a[i];
		cout << s << "\n";
	}
}