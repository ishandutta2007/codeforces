#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int n, k;

int main() {
	scanf("%d%d", &n, &k);
	int a, b, c, d;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	if (k < n + 1 || n == 4) {
		puts("-1");
	} else {
		vector<int> path;
		for (int i = 1; i <= n; ++i) {
			if (i == a || i == b || i == c || i == d) {
				continue;
			}
			path.push_back(i);
		}
		printf("%d %d ", a, c);
		for (int i = 0; i < n - 4; ++i) {
			printf("%d ", path[i]);
		}
		printf("%d %d\n", d, b);
		printf("%d %d ", c, a);
		for (int i = 0; i < n - 4; ++i) {
			printf("%d ", path[i]);
		}
		printf("%d %d\n", b, d);
	}
	return 0;
}