#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, m;
string s[20], t[20];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i=0; i<n; ++i) {
		cin >> s[i];
	}
	for(int j=0; j<m; ++j) {
		cin >> t[j];
	}
	int q;
	cin >> q;
	while(q--) {
		int y;
		cin >> y, --y;
		cout << s[y%n] << t[y%m] << "\n";
	}
}