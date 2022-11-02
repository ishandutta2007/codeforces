#include <bits/stdc++.h>
using namespace std;

string ans[2] = {"sjfnb", "cslnb"};
int n;
int a[100010];

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	bool same = false;
	for (int i = 1; i < n; i++) {
		if (a[i] == a[i + 1]) {
			same = true;
			if (a[i] == 0) {
				cout << ans[1] << endl;
				return 0;
			}
			a[i]--;
			break;
		}
	}
	if (same) {
		for (int i = 1; i < n; i++) {
			if (a[i] == a[i + 1]) {
				cout << ans[1] << endl;
				return 0;
			}
		}
	}
	long long tot = 0;
	for (int i = 1; i <= n; i++)
		tot += a[i];
	tot -= 1LL * n * (n - 1) / 2;
	if (tot % 2 == 0)
		cout << ans[1 ^ same] << endl;
	else
		cout << ans[0 ^ same] << endl;
}