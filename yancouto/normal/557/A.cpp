#include <cstdio>
#ifndef ONLINE_JUDGE
#	define debug(args...) fprintf(stderr, "%d: ", __LINE__); fprintf(stderr, args);
#else
#	define debug(args...) //
#endif
#include <algorithm>
using namespace std;

int main() {
	int i, n, mx[3], mn[3], dips[3];
	scanf("%d", &n);
	for(i = 0; i < 3; i++) {
		scanf("%d %d", &mn[i], &mx[i]);
		n -= mn[i];
		dips[i] = mn[i];
	}
	for(i = 0; i < 3; i++) {
		int num = min(n, mx[i] - mn[i]);
		n -= num;
		dips[i] += num;
	}
	printf("%d %d %d\n", dips[0], dips[1], dips[2]);
	return 0;
}