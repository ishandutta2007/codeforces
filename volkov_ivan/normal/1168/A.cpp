#include <iostream>

using namespace std;

int main() {
	//freopen("Desktop/input.txt", "r", stdin);
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	int a[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	int left = -1, right = m, mid;
	while (right - left > 1) {
		mid = (left + right) / 2;
		int cur = 0;
		bool flag = 1;
		for (int i = 0; i < n; i++) {
			int nxt;
			if (a[i] >= cur) {
				nxt = a[i];
				if (a[i] + mid >= m && (a[i] + mid) % m >= cur) nxt = cur;
				cur = nxt;
				continue;
			} else {
				if (a[i] + mid < cur) {
					flag = 0;
					break;
				}
			}
		}
		if (flag) right = mid;
		else left = mid;
	}
	cout << right << endl;
	return 0;
}