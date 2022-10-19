#include <bits/stdc++.h>
using namespace std;

#define int long long

main(void) {
	int n , m ;
	cin >> n >> m;
	if(n >= 31) {
		cout << m;
	}
	else {
		cout << m % (1 << n);
	}
}