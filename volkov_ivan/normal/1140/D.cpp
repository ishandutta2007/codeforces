#include <iostream>
#include <cstring>

using namespace std;

signed main() {
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 2; i <= n - 1; i++) ans += i * (i + 1);
	cout << ans << endl;
	return 0;
}