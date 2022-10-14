#include<bits/stdc++.h>

using namespace std;

int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		long long n, k;
		cin >> n >> k;
		for (int i = 0; i < k - 1; i++) {
			long long a = n;
			long long mini = 10, maxa = 0;
			bool ok = false;
			while(a > 0) {
				long long digit = a % 10;
				if (digit == 0) {
					ok = true;
					break;
				}
				mini = min(mini, digit);
				maxa = max(maxa, digit);
				a /= 10;
			}
			if (ok == true) {
				break;
			}
			n += mini * maxa;
		}
		cout << n << endl;
	}
}