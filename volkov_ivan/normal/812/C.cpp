#include <iostream>
#include <algorithm>

using namespace std;

long long a[100001], a1[100001], n, s;

long long poss(int k) {
	for (int i = 0; i < n; i ++) {
		a1[i] = a[i] + k * (i + 1);
	}
	sort(a1, a1 + n);
	long long summa = 0;
	for (int i = 0; i < k; i ++) {
		summa += a1[i];
	}
	if (summa <= s) {
		return summa;
	}
	return 0;
}

int main() {
	cin >> n >> s;
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
	}
	int left = 0, right = n + 1, mid;
	while (right - left > 1) {
		mid = (right + left) / 2;
		if (poss(mid) > 0) {
			left = mid;
		}
		else {
			right = mid;
		}
	}
	cout << left << ' ' << poss(left) << endl;
	return 0;
}