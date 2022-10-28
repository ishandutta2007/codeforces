#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, x, y;
	string s;
	cin >> n >> s >> x >> y;

	vector<int> psX(n + 1), psY(n + 1);
	for (int i = 0; i < n; ++i) {
		psY[i + 1] = psY[i];
		psX[i + 1] = psX[i];
		if (s[i] == 'U') {
			++psY[i + 1];
		} else if (s[i] == 'D') {
			--psY[i + 1];
		} else if (s[i] == 'R') {
			++psX[i + 1];
		} else {
			--psX[i + 1];
		}
	}

	if (psX[n] == x && psY[n] == y) {
		cout << 0 << '\n';
		return 0;
	}

	int ans = n + 1;
	for (int i = 1; i <= n; ++i) {
		int lb = 0, rb = i;
		while (lb < rb) {
			int mb = (lb + rb + 1) / 2;
			int fX = psX[n] - psX[i] + psX[mb - 1];
			int fY = psY[n] - psY[i] + psY[mb - 1];
			int dX = x - fX;
			int dY = y - fY;
			int dTot = abs(dX) + abs(dY);
			int len = i - mb + 1;
			if (dTot % 2 != len % 2 || dTot > len) {
				rb = mb - 1;
			} else {
				lb = mb;
			}
		}
		if (lb) {
			ans = min(ans, i - lb + 1);
		}
	}
	cout << (ans == n + 1 ? -1 : ans) << '\n';
}