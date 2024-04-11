#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	map<int, int> xc, yc;
	map<pair<int, int>, int> xyc;
	ll t=0;
	for(int i=0; i<n; ++i) {
		int x, y;
		cin >> x >> y;
		t+=xc[x]+yc[y]-xyc[{x, y}];
		++xc[x], ++yc[y], ++xyc[{x, y}];
	}
	cout << t;
}