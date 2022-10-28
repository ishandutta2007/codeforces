#include <bits/stdc++.h>
using namespace std;
const int MX = 1e5;
int a[MX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a, a + n);

	long long y = 0, x = 0;
	for (int i = 0; i < n / 2; ++i) {
		y += a[i];
	}
	for (int i = n / 2; i < n; ++i) {
		x += a[i];
	}
	cout << y * y + x * x << '\n';
}