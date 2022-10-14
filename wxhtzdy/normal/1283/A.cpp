#include <bits/stdc++.h>

using namespace std;

int main() {                                 
	int tt;
	cin >> tt;
	while (tt--) {
		int a, b;
		cin >> a >> b;
		cout << 24 * 60 - (a * 60 + b) << endl;	
	}
}