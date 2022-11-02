#include <iostream>
#include <vector>

using namespace std;

int main() {
	int k, n;
	cin >> n >> k;
	vector<string> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<vector<int>> cnt(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j + k <= n) {
				bool can = true;
				for (int o = 0; o < k; o++) {
					if (a[i][j + o] == '#') {
						can = false;
						break;
					}
				}
				if (can) {
					for (int o = 0; o < k; o++) {
						++cnt[i][j + o];
					}
				}
			}
			if (i + k <= n) {
				bool can = true;
				for (int o = 0; o < k; o++) {
					if (a[i + o][j] == '#') {
						can = false;
						break;
					}
				}
				if (can) {
					for (int o = 0; o < k; o++) {
						++cnt[i + o][j];
					}
				}
			}
		}
	}
	int maxCnt = -1;
	int posX = 0, posY = 0;
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			if (cnt[x][y] > maxCnt) {
				posX = x;
				posY = y;
				maxCnt = cnt[x][y];
			}
		}
	}
	cout << posX + 1 << " " << posY + 1 << endl;
	return 0;
}