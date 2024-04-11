#include <bits/stdc++.h>

using namespace std;

int t, n, cnt[1 << 20];

int main() {
	for (int i = 1; 2020 * i <= 1000000; i++) {
		int x = 2020 * i;
		cnt[x]++;
		cnt[x + i + 1]--;
	}
	for (int i = 1; i <= 1000000; i++)
		cnt[i] += cnt[i - 1];
	cin >> t;
	while (t--) {
		cin >> n;
		cout << (cnt[n] ? "YES\n" : "NO\n");
	}
	return 0;
}