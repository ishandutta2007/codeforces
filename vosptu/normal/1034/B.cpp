#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cassert>
#include <ctime>
#include <map>
#include <queue>
#include <set>
#include <cmath>
#include <list>
using namespace std;

int main() {
	int n, m;
	scanf("%d%d", &n, &m);

	if (n > m)
		swap(n, m);
	if (n == 1) {
		int ans;
		if (m % 6 == 0) {
			ans = m;
		}else if (m % 6 < 3) {
			ans = m / 6 * 6;
		}else {
			ans = m / 6 * 6 + ((m % 6) - 3) * 2;
		}
		printf("%d\n", ans);
	}else if (n == 2) {
		int ans;
		if (m == 2) {
			ans = 0;
		}else if (m == 3) {
			ans = 4;
		}else if (m == 7) {
			ans = 12;
		}else {
			ans = 2 * m;
		}
		printf("%d\n", ans);
	}else {
		printf("%I64d\n", 1LL * n * m / 2 * 2);
	}
}