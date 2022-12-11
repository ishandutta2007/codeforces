#include <iostream>

using namespace std;

int main() {
	int a[6], sum1 = 0, sum2 = 0;
	bool used[6] = {0, 0, 0, 0, 0, 0};
	char now;
	for (int i = 0; i < 6; i++) {
		cin >> now;
		a[i] = now - '0';
		if (i < 3) {
			sum1 += a[i];
		} else {
			sum2 += a[i];
		}
	}
	int summ = (sum1 - sum2);
	int c = 0, cnt = 0, last = 0;
	while (summ != 0) {
		c = 0;
		for (int i = 0; i < 6; i++) {
			if (used[i]) {
				continue;
			}
			if ((i < 3 && summ > 0) || (i >= 3 && summ < 0)) {
				if (a[i] > c) {
					c = a[i];
					last = i;
				}
			} else {
				if (9 - a[i] > c) {
					c = 9 - a[i];
					last = i;
				}
			}
		}
		used[last] = 1;
		if (summ > 0) {
			summ -= min(summ, c);
		} else {
			summ += min(-summ, c);
		}
		cnt++;
	}
	cout << cnt << endl;
}