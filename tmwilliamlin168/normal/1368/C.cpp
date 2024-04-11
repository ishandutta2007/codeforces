#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	cout << 4+3*n << "\n";
	cout << "0 0\n0 1\n1 0\n1 1\n";
	for(int i=0; i<n; ++i) {
		cout << i+1 << " " << i+2 << "\n";
		cout << i+2 << " " << i+2 << "\n";
		cout << i+2 << " " << i+1 << "\n";
	}
}