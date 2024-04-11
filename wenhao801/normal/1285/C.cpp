#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

#define int long long

inline int read () {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
	return ret * t;
}

int n;

int gcd (int x, int y) { if (!y) return x; return gcd(y, x % y); }

signed main () {
	n = read();
	int rua = sqrt(n);
	int ans =1;
	for (int i = 2; i <= rua; i++) {
		if (n % i != 0) continue;
		if (gcd(i, n / i) == 1) ans = i;
	}
	cout << ans << ' ' << n / ans << endl;
	return 0;
}