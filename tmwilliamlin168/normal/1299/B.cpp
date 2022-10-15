#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, x[100000], y[100000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i=0; i<n; ++i) {
		cin >> x[i] >> y[i];
	}
	if(n&1) {
		cout << "NO\n";
		return 0;
	}
	for(int i=0; i+1<n/2; ++i) {
		if(x[i]+x[i+n/2]!=x[i+1]+x[i+1+n/2]||y[i]+y[i+n/2]!=y[i+1]+y[i+1+n/2]) {
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
}