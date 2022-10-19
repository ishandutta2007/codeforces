#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, m, i, o = 0, e = 0, ans = 0,a;
	cin >> n >> m;
	for (i = 0; i < n; i++) {
		cin >> a;
		if (a % 2 == 0)
			e++;
		else
			o++;
	}
	for (i = 0; i < m; i++) {
		cin >> a;
		if (a % 2 == 0) {
			if (o > 0) {
				o--;
				ans++;
			}
		}
		else {
			if (e > 0) {
				e--;
				ans++;
			}
		}
	}
	cout << ans << endl;
}