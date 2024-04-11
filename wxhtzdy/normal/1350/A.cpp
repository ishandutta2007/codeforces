#include<bits/stdc++.h>
using namespace std;
int main() {
	int tt;
	cin >> tt;
	while(tt--) {
		int n, k;
		cin >> n >> k;
		int ans = 0;
		for (int i = 2; i * i <= n; i++) {
			if (n % i == 0) {
				ans = i;
				break;
			}
		}
		if (ans == 0) {
			ans = n;
		}
		n += ans;
		cout << n + (k - 1) * 2 << "\n";
	}
}