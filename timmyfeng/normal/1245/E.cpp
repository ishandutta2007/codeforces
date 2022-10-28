#include <bits/stdc++.h>
using namespace std;
double mv[100];
int lad[100];

int coordInt(int r, int c) {
	return r * 10 + (r % 2 ? 9 - c : c);
}
int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			int a;
			cin >> a;
			lad[coordInt(i, j)] = coordInt(i - a, j);
		}
	}
	fill(mv, mv + 100, 1e9);
	mv[0] = 0.0;
	mv[1] = mv[2] = mv[3] = mv[4] = mv[5] = 6.0;
	for (int i = 6; i < 100; ++i) {
		double res = 1.0;
		for (int j = 1; j <= 6; ++j) {
			res += min(mv[lad[i - j]], mv[i - j]) / 6;
		}
		mv[i] = min(res, mv[i]);
	}
	cout << fixed << setprecision(12) << mv[99] << '\n';
}