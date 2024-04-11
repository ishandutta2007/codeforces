#include <iostream>

using namespace std;

int main() {
	int n;
	long long k;
	cin >> n >> k;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if (k >= n - 1) {
		cout << n << endl;
		return 0;
	}
	int maxi = -1, j, cnt;
	for (int i = 0; i < n; i++) {
		if (a[i] > maxi) {
			maxi = a[i];
			j = i + 1;
			while (j < n && a[j] < a[i]) {
				j++;
			}
			cnt = (j - i);
			if (i == 0) cnt--;
			if (j == n || cnt >= k) {
				cout << a[i] << endl;
				return 0;
			}
		}
	}
	return 0;
}