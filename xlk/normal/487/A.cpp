#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
int h1, a1, d1, h2, a2, d2, h, a, d;
int da, dd, ans = 0x3f3f3f3f;
int main() {
	cin >> h1 >> a1 >> d1;
	cin >> h2 >> a2 >> d2;
	cin >> h >> a >> d;
	for (int i = 0; i < 220; i++) {
		for (int j = 0; j < 220; j++) {
			da = a1 - d2;
			dd = a2 - d1;
			da += i;
			dd -= j;
			if (da <= 0) {
				continue;
			}
			if (dd < 0) {
				dd = 0;
			}
			int times = (h2 + da - 1) / da;
			int needhp = times * dd;
			int needbuy = needhp - h1 + 1;
			if (needbuy < 0) {
				needbuy = 0;
			}
			int cost = needbuy * h + i * a + j * d;
			if (cost < ans) {
				ans = cost;
			}
		}
	}
	cout << ans << endl;
	return 0;
}