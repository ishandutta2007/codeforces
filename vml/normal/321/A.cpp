#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <cmath>

using namespace std;

int main() {
	long long x, y;
	scanf("%I64d %I64d\n", &x, &y);
	string s;
	getline(cin, s);
	if (x == 0 && y == 0) {
		printf("Yes");
		return 0;
	}
	vector <pair <long long, long long> > delta(s.size());
	long long dx = 0, dy = 0;
	for (int i = 0; i < (int)s.size(); i++) {
		if (s[i] == 'U') {
			dy++;
		} else if (s[i] == 'D') {
			dy--;
		} else if (s[i] == 'R') {
			dx++;
		} else {
			dx--;
		}
		delta[i] = make_pair(dx, dy);
	}
	for (int i = 0; i < (int)s.size(); i++) {
		long long k = -1;
		if (dx == 0) {
			if (delta[i].first != x) {
				continue;
			}
		} else {
			if ((x - delta[i].first) % dx != 0 || (x - delta[i].first) / dx < 0) {
				continue;
			} else {
				k = (x - delta[i].first) / dx;
			}
		}
		if (dy == 0) {
			if (delta[i].second != y) {
				continue;
			}
		} else {
			if ((y - delta[i].second) % dy != 0 || (y - delta[i].second) / dy < 0 || ((y - delta[i].second) / dy != k && k != -1)) {
				continue;
			}
		}
		printf("Yes");
		return 0;
	}
	printf("No");
	return 0;
}