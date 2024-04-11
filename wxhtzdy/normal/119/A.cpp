#include <bits/stdc++.h>

using namespace std;

int main() {                                 
	int a, b, n;
	cin >> a >> b >> n;
	int cnt = 0;
	while (true && n > 0) {
	 	int x = 0;
	 	if (cnt % 2 == 0) {
	 		x = __gcd(a, n);	 	
	 	} else {
	 		x = __gcd(b, n);
	 	}
	 	if (x > n) {
	 	 	break;
	 	} else {
	 	 	cnt = 1 - cnt;
	 	 	n -= x;
	 	}
	}
	cout << 1 - cnt;
}