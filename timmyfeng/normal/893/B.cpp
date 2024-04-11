#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int ans = 0;
	for (int k = 1; k <= 10; ++k) {
		int a = ((1 << k) - 1) << (k - 1);
		if (n % a == 0) {
			ans = a;
		}
	}
	cout << ans << '\n';
}