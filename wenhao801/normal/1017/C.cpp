#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

inline int read () {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
	return ret * t;
}

int main () {
	int n = read(), k = 1, i, j = n + 1;
	for (i = 2; i <= n /2; i++) {
		if ((n / i) + (bool(n % i)) + i < j)
			k = i, j = (n / i) + (bool(n % i)) + i; //, cout << (n / i) + (bool(n % i)) + (n % i) << ' ' << i << endl;
	}
	for (i = k; 1; i += k) {
		int lo = i - k, br = 0;
		if (i >= n) i = n, br = 1;
		for (j = i; j > lo; j--) cout << j << ' ';
		if (br) break;
	}
	return 0;
}