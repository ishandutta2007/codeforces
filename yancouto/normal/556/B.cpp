#include <cstdio>
#ifndef ONLINE_JUDGE
#	define debug(args...) fprintf(stderr, "%d: ", __LINE__); fprintf(stderr, args);
#else
#	define debug(args...) //
#endif

int main() {
	int n, i, k, a0;
	bool possible = true;
	scanf("%d\n", &n);
	scanf("%d", &a0);
	k = (n - a0) % n;
	for(i = 1; i < n; i++) { 
		scanf("%d", &a0);
		if((i & 1) && ((a0 - k + n) % n) != i)
			possible = false;
		if(!(i & 1) && ((a0 + k) % n) != i)
			possible = false;
	}
	printf("%s\n", possible? "Yes" : "No");
	return 0;
}