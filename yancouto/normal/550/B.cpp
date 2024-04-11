#ifndef ONLINE_JUDGE
#define debug(args...) fprintf(stderr, "%d: ", __LINE__); fprintf(stderr, args);
#else
#define debug(args...) //
#endif

#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
	int n, l, r, x, i, j;
	int c[17];
	scanf("%d %d %d %d", &n, &l, &r, &x);
	for(i = 0; i < n; i++)
		scanf("%d", &c[i]);
	int maxn = (1 << n);
	int total = 0;
	for(i = 1; i < maxn; i++) {
		int max_v, min_v, sum;
		max_v = INT_MIN;
		min_v = INT_MAX;
		sum = 0;
		for(j = 0; j < n; j++)
			if((1 << j) & i) {
				max_v = max(max_v, c[j]);
				min_v = min(min_v, c[j]);
				sum += c[j];
			}
		if(sum >= l && sum <= r && (max_v - min_v) >= x)
			total++;
	}
	printf("%d\n", total);
	return 0;
}