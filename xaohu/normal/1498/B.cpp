#include <bits/stdc++.h>

using namespace std;

int t, n, w, cnt[20];

bool solve(long long k) {
	long long s = 0;
	for (int i = 19; 0 <= i; i--) {
		s = 2 * s + cnt[i];
		if (s > k * (w / (1 << i)))
			return false;
	}
	return true;
}

int main() {
	cin >> t;
	while (t--) {
		memset(cnt, 0, sizeof cnt);
		cin >> n >> w;
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			cnt[(int)log2(x)]++;
		}
		int l = 1, r = n;
		while (l < r) {
			int m = (l + r) / 2;
			if (solve(m)) 
				r = m;
			else
				l = m + 1;
		}
		cout << l << "\n";
	}
		
	return 0;
}