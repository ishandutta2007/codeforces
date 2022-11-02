#include <cstdio>
#ifndef ONLINE_JUDGE
#	define debug(args...) fprintf(stderr, "%d: ", __LINE__); fprintf(stderr, args);
#else
#	define debug(args...) //
#endif

int main() {
	int n, i; char c;
	char stack[200009];
	int p = 0;
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		scanf(" %c", &c);
		if(p == 0 || stack[p - 1] == c)
			stack[p++] = c;
		else
			p--;
	}
	printf("%d\n", p);
	return 0;
}