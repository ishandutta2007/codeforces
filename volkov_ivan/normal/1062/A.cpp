#include <iostream>

using namespace std;

int main() {	
	//freopen("/Users/ivanvolkov/Desktop/inp.in", "r", stdin);
	int n;
	cin >> n;
	int arr[n + 3];
	for (int i = 1; i <= n; i++) cin >> arr[i];
	if (n == 1) {
		cout << 0 << endl;
		return 0;
	}
	/*if (n == 2) {
		if (a[1] == 1 && a[2] == 2) cout << 1 << endl;
		else if (a[1] == 999 && a[2] == 1000) cout << 1 << endl;
		else cout << 0 << endl;
		return 0;
	}*/
	int last = -2, ans = 0, pref = -1, suff = -1;
	for (int i = 2; i <= n; i++) {
		//cout << last << ' ' << ans << endl;
		if (arr[i] == arr[i - 1] + 1) {
			if (last == -2) last = i - 1;
		} else {
			if (last != -2) {ans = max(ans, i - last - 2); if (last == 1) pref = ans;}
			last = -2;
		}
	}
	//cout << ans << endl;
	if (last != -2) ans = max(ans, n - last - 1), suff = n - last - 1;
	//cout << ans << ' ' << suff << endl;
	if (last == 1) pref = n - 2;
	if (arr[1] == 1 && arr[2] == 2) pref++;
	//cout << ans << endl;
	if (arr[n] == 1000 && arr[n - 1] == 999) suff++;
	ans = max(ans, pref);
	ans = max(ans, suff);
	if (ans == n) ans--;
	if (n == 1000) ans++;
	cout << ans << endl;
	return 0;
}