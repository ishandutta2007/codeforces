#include<iostream>

using namespace std;

const int N = 5005;

int n, m, k;

int c[N], lastc[N], r[N], lastr[N];

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m >> k;
	for (int i = 0; i < k; ++i) {
		int type, id, col;
		cin >> type >> id >> col;
		--id;
		if (type == 1) {
			r[id] = col;
			lastr[id] = i + 1;
		} else {
			c[id] = col;
			lastc[id] = i + 1;
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int ans = 0;
			if (lastc[j] != 0) {
				ans = c[j];
			}
			if (lastr[i] != 0 && lastr[i] > lastc[j]) {
				ans = r[i];
			}
			cout << ans;
			if (j != m - 1) {
				cout << ' ';
			}
		}
		cout << endl;
	}
	return 0;
}