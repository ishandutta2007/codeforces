#include <bits/stdc++.h>
using namespace std;

int a[1000][1000];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < n; ++i) {
		int x = (i == 0);
		int y = x + 1 + (i == 1);
		long long sqr = 1LL * a[i][x] * a[i][y] / a[x][y];
		cout << int(round(sqrt(sqr))) << " ";
	}
	cout << "\n";
}