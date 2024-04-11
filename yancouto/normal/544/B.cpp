#ifndef ONLINE_JUDGE
#define debug(args...) fprintf(stderr, "%d: ", __LINE__); fprintf(stderr, args);
#else
#define debug(args...) //
#endif

#include <cstdio>

int main() {
	int n, k, i, j;
	scanf("%d %d", &n, &k);
	int s[2];
	s[0] = (n + 1) / 2;
	s[1] = n / 2;
	int count = 0;
	for(i = 0; i < n; i++) count += s[i % 2];
	if(count < k) { puts("NO"); return 0; }
	puts("YES"); count = 0;
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			char c = ((i % 2) == (j % 2))? 'L' : 'S'; 
			if(count < k) putchar(c);
			else putchar('S');
			if(c == 'L') count++;
		}
		putchar('\n');
	}
	return 0;
}