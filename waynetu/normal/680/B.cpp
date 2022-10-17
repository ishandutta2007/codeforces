#include <iostream>
using namespace std;

int c[101];

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> c[i];
	}
	int sum = 0;
	sum += c[m];
	int idx = 1;
	while (m - idx >= 1 && m + idx <= n) {
		if (c[m - idx] == c[m + idx]) {
			sum += c[m - idx] + c[m + idx];
		}
		idx++;
	}
	while (m - idx >= 1) {
		sum += c[m - idx];
		idx++;
	}
	while (m + idx <= n) {
		sum += c[m + idx];
		idx++;
	}
	cout << sum << endl;
	return 0;
}