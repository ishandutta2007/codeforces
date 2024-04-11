#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
int n;
pair<int, int> a[200020];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		a[i].first = x - y;
		a[i].second = x + y;
	}
	sort(a, a + n);
	int ans = 0, right = -2000000000;
	for (int i = 0; i < n; i++) {
		if (a[i].first >= right) {
			ans++;
			right = a[i].second;
		} else {
			right = min(right, a[i].second);
		}
	}
	printf("%d\n", ans);
	return 0;
}