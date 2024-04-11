#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	vector<bool> was(n, false);
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (was[i] == true) {
			continue;
		}
		for (int j = i + 1; j < n; j++) {
			if (a[j] % a[i] == 0) {
				was[j] = true;
			}
		}
		cnt++;
	}
	cout << cnt;
	return 0;
}