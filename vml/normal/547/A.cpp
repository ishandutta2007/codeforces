//#pragma comment (linker, "/STACK:1000000000")
 
#include <iostream>
#include <ctime>
#include <time.h>
#include <string>
#include <map>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <set>
#include <stdio.h>
 
using namespace std;

const int maxn = (int)1e6 + 10;

bool used[maxn];

long long phi(long long a) {
	long long p = a;
	for (long long i = 2; i * i <= a; i++) {
		if (a % i == 0) {
			p /= i;
			p *= (i - 1);

			while (a % i == 0) {
				a /= i;
			}
		}
	}

	if (a != 1) {
		p /= a;
		p *= (a - 1);
	}

	return p;
}

long long my_pow(long long a, long long b, long long c) {
	if (b == 0) {
		return 1;
	}

	if (b % 2 == 1) {
		return (a * my_pow(a, b - 1, c)) % c;
	}

	long long t = my_pow(a, b / 2, c);

	return (t * t) % c;
}

long long gcd(long long a, long long b) {
	if (b == 0) {
		return a;
	}

	return gcd(b, a % b);
}
 
int main() {
	long long m;

	cin >> m;

	long long h1, a1, h2, a2, x1, y1, x2, y2;

	cin >> h1 >> a1 >> x1 >> y1 >> h2 >> a2 >> x2 >> y2;

	used[h1] = true;
	long long t = 0;

	while (true) {
		h1 = (x1 * h1 + y1) % m;
		h2 = (x2 * h2 + y2) % m;
		t++;
		
		if (h1 == a1) {
			break;
		}

		if (used[h1]) {
			printf("-1");
			exit(0);
		}

		used[h1] = true;
	}
	
	if (h1 == a1 && h2 == a2) {
		cout << t;
		exit(0);
	}

	memset(used, 0, sizeof used);

	used[h1] = true;
	long long d = 0;

	while (true) {
		h1 = (h1 * x1 + y1) % m;
		d++;

		if (h1 == a1) {
			break;
		}

		if (used[h1]) {
			printf("-1");
			exit(0);
		}

		used[h1] = true;
	}

	memset(used, 0, sizeof used);
	used[h2] = true;
	long long d1 = 0;

	while (true) {
		h2 = (h2 * x2 + y2) % m;
		d1++;

		if (h2 == a2) {
			break;
		}

		if (used[h2]) {
			printf("-1");
			exit(0);
		}

		used[h2] = true;
	}

	if (d1 % d == 0) {
		cout << t + d1 << endl;
		exit(0);
	}

	memset(used, 0, sizeof used);
	used[h2] = true;
	long long d2 = 0;

	while (true) {
		h2 = (h2 * x2 + y2) % m;
		d2++;

		if (h2 == a2) {
			break;
		}

		if (used[h2]) {
			printf("-1");
			exit(0);
		}

		used[h2] = true;
	}

	long long c = -d1;
	c %= d;
	c += d;
	c %= d;

	long long g = gcd(d2, d);
	long long buf = d2;

	if (c % g != 0) {
		printf("-1");
		exit(0);
	}

	c /= g;
	d2 /= g;
	d /= g;

	long long ans = (c * my_pow(d2, phi(d) - 1, d)) % d;

	ans *= buf;
	ans += d1;

	cout << t + ans << endl;

	return 0;
}