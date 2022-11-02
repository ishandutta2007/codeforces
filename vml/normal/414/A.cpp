#pragma comment (linker, "/STACK:1000000000")

#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cstring>

using namespace std;

const int maxn = 10010;

int a = 1, b = 2;

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	if (k < n / 2) {
		printf("-1");
		return 0;
	}
	if (n == 1 && k != 0) {
		cout << "-1";
		return 0;
	}
	if (n == 1 && k == 0) {
		cout << "1";
		return 0;
	}
	int d = k - n / 2 + 1;
	a *= d;
	b *= d;
	printf("%d %d", a, b);
	int it = 1;
	for (int i = 2; 2 * i <= n; i++) {
		while (it == a || it == b || it + 1 == a || it + 1 == b) {
			it++;
		}
		printf(" %d %d", it, it + 1);
		it += 2;
	}

	if (n % 2 != 0) {
		cout << " 1000000000";
	}

	return 0;
}