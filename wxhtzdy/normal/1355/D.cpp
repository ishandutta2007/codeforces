#include<bits/stdc++.h>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	if(k < 2 * n) {
		cout << "NO" << endl;
		return 0;
	} else {
		cout << "YES" << endl;
	}
	for(int i = 0; i < n - 1; i++) {
		cout << 2 << " ";
	}
	cout << k - (n - 1) * 2 << endl << 1;
}