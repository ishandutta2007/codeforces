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
		int r, g, b;
		cin >> r >> g >> b;
		if(r>g)
			swap(r, g);
		if(g>b)
			swap(g, b);
		if(r>g)
			swap(r, g);
		cout << (b-1<=r+g?"Yes":"No") << "\n";
	}
}