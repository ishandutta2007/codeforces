#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <string>
using namespace std;
int n, minp, maxp, a[105];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
		if (a[i] == 1) minp = i;
		if (a[i] == n) maxp = i;
	}
	int ans = max(max(minp - 1, n - minp), max(maxp - 1, n - maxp));
	printf("%d\n", ans);
}