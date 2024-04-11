#include <iostream>
#define int long long 

using namespace std;

signed main() {
//	freopen("Desktop/input.txt", "r", stdin);
	int a, b, c;
	cin >> a >> b >> c;
	int t = min(a, b);
	int ans = 2 * (c + t);
	if (a > t) ans++;
	if (b > t) ans++;
	cout << ans << endl;
	return 0;
}