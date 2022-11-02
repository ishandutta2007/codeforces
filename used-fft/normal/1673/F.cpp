#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl << endl

const int Z = 34;

int a[2][Z];

signed main() {
	ios::sync_with_stdio(0), cin.tie(0);

	for(int i = 1; i <= 32; ++i) {
		int d = __lg(i&-i);
		a[0][i] = (1<<(2*d));
		a[1][i] = (1<<(2*d+1));
	}

	map<int, int> b[2][40];

	for(int i = 1; i <= 32; ++i) {
		b[0][i][0] = i;
		b[1][i][0] = i;
	}
	for(int i = 1; i < 32; ++i) {
		int cur[2] {};
		for(int j = i + 1; j <= 32; ++j) {
			for(int k : {0, 1}) {
				cur[k] ^= a[k][j-1];
				b[k][i][cur[k]] = j;
				b[k][j][cur[k]] = i;
			}
		}
	}

	int n, k; cin >> n >> k;
	for(int i = 0; i < n; ++i) {
		for(int j = 1; j < n; ++j) cout << a[0][j] << ' ';
		cout nl;
	}
	for(int i = 1; i < n; ++i) {
		for(int j = 0; j < n; ++j) cout << a[1][i] << ' ';
		cout nl;
	}

	int i = 1, j = 1;
	while(k--) {
		int w; cin >> w;

		int ww[2] {};
		for(int bb = 0; bb < 20; ++bb) {
			ww[bb % 2] ^= w & (1<<bb);
		}

		int x = b[1][i][ww[1]];
		int y = b[0][j][ww[0]];
		i = x;
		j = y;
		cout << i << ' ' << j nl;
	}
}