#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int a, b;
	cin >> a >> b;

	int ans = 0;
	for (int i = 1, j; i <= a + b; i = j + 1) {
		int cnt = (a + b) / i;
		j = (a + b) / cnt;

		int alo = (a - 1) / (cnt + 1) + 1;
		int ahi = a / cnt;
		int blo = (b - 1) / (cnt + 1) + 1;
		int bhi = b / cnt;

		if (alo <= ahi && blo <= bhi) {
			ans += max(0, min(j, bhi + ahi) - max(i, blo + alo) + 1);
		}
	}
	cout << ans << '\n';
}