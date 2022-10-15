#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int r, c;
	cin >> r >> c;
	if(r==1&&c==1) {
		cout << 0;
		return 0;
	}
	if(c==1) {
		for(int i=0; i<r; ++i)
			cout << i+2 << "\n";
		return 0;
	}
	for(int i=0; i<r; ++i) {
		for(int j=0; j<c; ++j)
			cout << (i+1)*(r+1+j) << " ";
		cout << "\n";
	}
}