#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int ans = 0, maxi = 0;
	for (int i = 1; i <= n; i++) {
		if (i - 1 == maxi) ans++;
		int t;
		cin >> t;
		maxi = max(maxi, t);
	}
	cout << ans << endl;
	return 0;
}