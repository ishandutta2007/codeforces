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

int gcd(int x, int y) {
	if (!x)
		return y;
	else
		return gcd(y % x, x);
}

int main() {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	int x = gcd(n, k);
	n /= x;
	k /= x;
	int y = gcd(m, k);
	m /= y;
	k /= y;
	if (k > 2) {
		printf("NO\n");
	}else {
		if (k == 1) {
			if (x > 1)
				n *= 2;
			else
				m *= 2;
		}
		printf("YES\n%d %d\n%d %d\n%d %d\n", 0, 0, n, 0, 0, m);
	}
	return 0;
}