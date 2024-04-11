#include <bits/stdc++.h>
using namespace std;

#define int long long

main(void) {
	int x;
	cin >> x;
	++ x;
	if(x == 1) {
		cout << 0 << endl;
		return 0;
	}
	if(x % 2)
	cout << x << endl;
	else cout << x / 2;
}