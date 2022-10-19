#include <bits/stdc++.h>
using namespace std;

void rmain() {
	int n;
	cin >> n;
	if(n % 2 == 0) {
		cout << n / 2 <<' ' << n / 2  - 1 << ' ' << 1 << endl;
	} else {
		for(int d = 2; ; d += 2) {
			int a = (n + d - 1) / 2;
			if(a - d <= 1) throw;
			if(a & 1) {
				cout << a <<" " << a - d <<' ' << 1 << endl;
				return;
			} else continue;
		}
	}
}

int main() {
	int t; for(cin >> t; t --;) rmain();
}