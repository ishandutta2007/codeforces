#pragma comment(linker, "/STACK:1000000000")

#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <cstring>
#include <string>
#include <set>
#include <cstdlib>
#include <memory.h>
#include <cassert>
#include <queue>
#include <ctime>

using namespace std;

const int maxn = (int)2e5 + 10;

long double pw[maxn];
int x[maxn];
int y[maxn];

int gcd(int a, int b) {
	return (b == 0 ? a : gcd(b, a % b));
}

long double go(int i, int j) {
	long double ax = x[i], ay = y[i], bx = x[j], by = y[j];
	
	return ax * by - ay * bx;
}

int main() {
	int n;
	
	cin >> n;
	
	pw[0] = 1;
	
	for (int i = 1; i < maxn; i++) {
		pw[i] = pw[i - 1] * 0.5;
	}
	
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &x[i], &y[i]);
	}
	
	long double cnt = 0;

	for (int i = n; i < 2 * n; i++) {
		x[i] = x[i - n];
		y[i] = y[i - n];
	}

	for (int i = 0; i < n; i++) {
		cnt += go(i, i + 1);
	}

	cnt = abs(cnt);
	
	for (int i = 0; i < n; i++) {
		cnt -= gcd(abs(x[i] - x[i + 1]), abs(y[i] - y[i + 1]));
	}

	cnt *= 0.5;
	cnt++;

	long double sum = 0;

	long double z = 1 - pw[n] * (1 + n + (long double)n * (n - 1) * 0,5);

	for (int i = 0; i < n; i++) {
		long long last = 0;
		for (int j = 1; j < min(n - 1, 70); j++) {
			int k = i + j + 1;

			long long x1 = x[k] - x[i];
			long long x2 = x[k - 1] - x[i];
			long long y1 = y[k] - y[i];
			long long y2 = y[k - 1] - y[i];

			long long s = x1 * y2 - x2 * y1;
			s = abs(s);

			long long g = gcd(abs(x[k] - x[i]), abs(y[k] - y[i])) + gcd(abs(x[k - 1] - x[i]), abs(y[k - 1] - y[i])) + gcd(abs(x[k] - x[k - 1]), abs(y[k] - y[k - 1]));

			last += s - g + 2;
			last += 2 * gcd(abs(x[k] - x[i]), abs(y[k] - y[i])) - 2;

			int now = k - i - 1;
			now = n - 2 - now;

			if (n > 50) {
				sum += (pw[n - now] - pw[n]) * 0.5 * last / z;
			} else {
				sum += (pow(2.0, (double)now) - 1.0) * 0.5 * last / (pow(2.0, (double)n) - 1 - n - n * (n - 1) / 2);
			}
		}
	}

	cout.precision(100);

	cout << cnt - sum << endl;

	return 0;
}