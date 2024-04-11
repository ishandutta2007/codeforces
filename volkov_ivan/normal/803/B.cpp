#include <iostream>

using namespace std;

const int INF = 1e9 + 7;

int main() {
	int n;
	cin >> n;
	int a[n], left[n], right[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		left[i] = INF;
		right[i] = INF;
	}
	for (int i = 0; i < n; i++) {
		if (a[i] == 0) {
			left[i] = 0;
		}
		else {
			left[i] = i > 0 ? min(left[i - 1] + 1, INF) : INF;
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		if (a[i] == 0) {
			right[i] = 0;
		}
		else {
			right[i] = i < n - 1 ? min(right[i + 1] + 1, INF) : INF;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << min(left[i], right[i]) << ' ';
	}
	cout << endl;
	return 0;
}