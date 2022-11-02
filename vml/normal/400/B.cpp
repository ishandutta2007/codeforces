#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <set>
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

int sum[1010];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("\n");
		int sweet;
		int gnom;
		for (int j = 0; j < m; j++) {
			char c;
			scanf("%c", &c);
			if (c == 'G') {
				gnom = j;
			} else if (c == 'S') {
				sweet = j;
			}
		}
		if (gnom > sweet) {
			printf("-1");
			return 0;
		}
		sum[i] = sweet - gnom;
	}
	int count = 0;
	while (true) {
		int min_element = 1000000000;
		for (int i = 0; i < n; i++) {
			if (sum[i] != 0) {
				min_element = min(min_element, sum[i]);
			}
		}
		if (min_element == 1000000000) {
			break;
		}
		count++;
		for (int i = 0; i < n; i++) {
			if (sum[i] != 0) {
				sum[i] -= min_element;
			}
		}
	}
	printf("%d", count);
	return 0;
}