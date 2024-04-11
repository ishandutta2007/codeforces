#include <iostream>

using namespace std;

const int INF = 1e9 + 7;

int main() {
	int n, k;
	cin >> n >> k;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if (k == 1) {
		int mini = a[0];
		for (int i = 1; i < n; i++) {
			if (a[i] < mini) {
				mini = a[i];
			}
		}
		cout << mini << endl;
		return 0;
	}
	if (k == 2) {
		cout << max(a[0], a[n - 1]) << endl;
		return 0;
	}
	int maxi = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] > maxi) {
			maxi = a[i];
		}
	}
	cout << maxi << endl;
	return 0;
}