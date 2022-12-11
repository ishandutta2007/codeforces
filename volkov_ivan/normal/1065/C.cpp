#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 2e5 + 7;
int h[MAX_N];
int cnt[MAX_N];

int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}
	int need = h[0];
	for (int i = 1; i < n; i++) need = min(need, h[i]);
	sort(h, h + n);
	for (int i = MAX_N - 1; i >= 1; i--) {
		int l = -1, r = n, m;
		while (r - l > 1) {
			m = (l + r) / 2;
			if (h[m] >= i) r = m;
			else l = m;
		}
		cnt[i] = n - r;
	}
	int ans = 0, now = k;
	for (int i = MAX_N - 1; i > need; i--) {
		if (now + cnt[i] > k) {
			ans++;
			now = cnt[i];
		} else {
			now += cnt[i];
		}
	}
	cout << ans << endl;
	return 0;
}