#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int b[100100], pos[100100] = {1};

int main () {
	int n; scanf("%d", &n);
	int i, j, p1 = 0, p2 = 0;
	for (i = 2; i <= n; i++) {
		printf("XOR 1 %d\n", i); fflush(stdout);
		scanf("%d", &b[i]);
		if (pos[b[i]]) p1 = pos[b[i]], p2 = i;
		else pos[b[i]] = i;
	}
	if (p1) {
		printf("AND %d %d\n", p1, p2); fflush(stdout);
		int x; scanf("%d", &x);
		printf("! ");
		for (i = 1; i <= n; i++) {
			printf("%d ", b[i] ^ b[p1] ^ x);
		}
		fflush(stdout); return 0;
	}
	int x = 0, y;
	printf("AND %d %d\n", 1, pos[1]); fflush(stdout);
	scanf("%d", &x); if (x & 1) --x;
	printf("AND %d %d\n", 1, pos[2]); fflush(stdout);
	scanf("%d", &y);
	if (y & 1) ++x;
	printf("! ");
	for (i = 1; i <= n; i++) printf("%d ", b[1] ^ b[i] ^ x);
	fflush(stdout);
	return 0;
}