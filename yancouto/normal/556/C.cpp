#include <cstdio>
#ifndef ONLINE_JUDGE
#	define debug(args...) fprintf(stderr, "%d: ", __LINE__); fprintf(stderr, args);
#else
#	define debug(args...) //
#endif

int main() {
	int n, k, first = 1, i, j, size, x, y;
	scanf("%d %d", &n, &k);
	int cost = 0;
	for(i = 0; i < k; i++) {
		scanf("%d %d", &size, &x);
		bool go = (x == 1);
		for(j = 1; j < size; j++) {
			scanf("%d", &y);
			if(go && (y == j + 1)) first++;
			else {
				go = false;
				cost++;
			}
		}
	}
	printf("%d\n", cost + (n - first));
	return 0;
}