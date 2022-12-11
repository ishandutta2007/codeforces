#include <iostream>
#include <algorithm>
#define int long long

using namespace std;

signed main() {
	//freopen("Desktop/input.txt", "r", stdin); 
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	int a[n], suff[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	suff[n - 1] = a[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		suff[i] = suff[i + 1] + a[i];
	}
	int ans = suff[0];
	sort(suff + 1, suff + n);
	int pos = n - 1;
	for (int i = 1; i < k; i++) {
		ans += suff[pos];
		pos--;
	}
	cout << ans << endl;
	return 0;
}