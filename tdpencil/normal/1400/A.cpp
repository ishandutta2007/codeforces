#include <bits/stdc++.h>
using namespace std;


void solve() {
	int n; cin >> n;
	string s; cin >> s;

	for(int i=0; i < 2*n-1; i+=2)
		cout << s[i];
	cout << "\n";
}

int main() {
	int t; cin >> t; while(t--) solve();
}