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
		int n, m;
		cin >> n >> m;
		cout << "W";
		for(int i=0; i<n; ++i) {
			for(int j=!i; j<m; ++j) {
				cout << "B";
			}
			cout << "\n";
		}
	}
}