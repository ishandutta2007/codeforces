#ifndef ONLINE_JUDGE
#define debug(args...) fprintf(stderr, "%d: ", __LINE__); fprintf(stderr, args);
#else
#define debug(args...) //
#endif

#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;

void print_stuff(int c, int k) {
	int i, j;
	for(i = 2; i <= k; i++)
		printf("%d %d\n", 1 + c, i + c);
	for(i = 2; i <= k; i++)
		for(j = k + 1; j < 2 * k; j++)
			printf("%d %d\n", i + c, j + c);
	for(i = k + 1; i < 2 * k; i += 2)
		printf("%d %d\n", i + c, i + 1 + c);
}

int main() {
	int k;
	scanf("%d", &k);
	if((k % 2) == 0) { puts("NO"); return 0; }
	puts("YES");
	printf("%d %d\n", 4 * k - 2, 2 * ((k - 1) * (k - 1) + (k - 1) / 2 + k - 1) + 1);
	print_stuff(0, k);
	printf("%d %d\n", 1, 2 * k);
	print_stuff(2 * k - 1, k);
	return 0;
}