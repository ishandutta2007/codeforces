#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=4e5;
int q, x, c[mxN];
set<ll> s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> q >> x;
	for(int i=0; i<x; ++i)
		s.insert(i);
	while(q--) {
		int y;
		cin >> y;
		y%=x;
		s.erase((ll)c[y]*x+y);
		++c[y];
		s.insert((ll)c[y]*x+y);
		cout << (*s.begin()) << "\n";
	}
}