#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	int c[n], r[n];
	for (int i = 0; i < n; i++) {
		c[i] = 0;
		r[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) {
			if (s[j] == 'C') {
				c[i]++;
				r[j]++;
			}
		}
	}
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		ans += (c[i] * (c[i] - 1)) / 2;
		ans += (r[i] * (r[i] - 1)) / 2;
	}
	cout << ans;
}