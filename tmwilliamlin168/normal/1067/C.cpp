#include <bits/stdc++.h>
using namespace std;

int n, x, y;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i=0; i<n; ++i) {
		cout << x << " " << y << "\n";
		swap(x, y);
		x=-x;
		if(i%4==0)
			++x;
	}
}