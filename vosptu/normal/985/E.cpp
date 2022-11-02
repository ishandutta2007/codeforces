#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstdlib>
#include <ctime>
#include <deque>
using namespace std;

#define N 510000
int n, k, d, a[N], dp[N], b[N];

void modify(int x, int y) {
	x += 1;
	for (; x <= n + 1; x += x & -x)
		b[x] += y;
}

int query(int x) {
	x += 1;
	int sum = 0;
	for (; x; x -= x & -x)
		sum += b[x];
	return sum;
}

int main() {
	scanf("%d%d%d", &n, &k, &d);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	dp[0] = 1;
	modify(0, 1);
	int pre = 0;
	for (int i = 1; i <= n; i++) {
		while (abs(a[pre + 1] - a[i]) > d)
			pre += 1;
		// i - k
		int tmp = 0;
		if (pre <= i - k) {
			if (pre == 0)
				tmp = query(i - k);
			else
				tmp = query(i - k) - query(pre - 1);
		}
		if (tmp > 0)
			dp[i] = 1, modify(i, 1);
	}
	if (dp[n])
		printf("YES\n");
	else
		printf("NO\n");
}