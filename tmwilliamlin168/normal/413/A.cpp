#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, mn, mx;
	cin >> n >> m >> mn >> mx;
	bool h0=0, h1=0, bad=0;
	for(int i=0; i<m; ++i) {
		int t;
		cin >> t;
		if(t==mn)
			h0=1;
		if(t<mn)
			bad=1;
		if(t>mx)
			bad=1;
		if(t==mx)
			h1=1;
	}
	if(bad) {
		cout << "Incorrect";
		return 0;
	}
	if(mn==mx&&m+1<=n) {
	cout << "Correct";
	return 0;}
	cout << (m+(!h0)+(!h1)<=n?"Correct":"Incorrect");
}