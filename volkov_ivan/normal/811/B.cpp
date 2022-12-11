#include <iostream>

using namespace std;

int main () {
	int n, m, l, r, x, cnt;
	cin >> n >> m;
	int perm[n + 1];
	for (int i = 1; i <= n; i ++) {
		cin >> perm[i];
	}
	for (int i = 0; i < m; i ++) {
		cin >> l >> r >> x;
		cnt = 0;
		for (int j = l; j <= r; j ++) {
			if (perm[j] < perm[x]) {
				cnt ++;
			}
		}
		if (l + cnt == x) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}
	return 0;
}