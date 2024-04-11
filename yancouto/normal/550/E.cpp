#ifndef ONLINE_JUDGE
#define debug(args...) fprintf(stderr, "%d: ", __LINE__); fprintf(stderr, args);
#else
#define debug(args...) //
#endif

#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;

void nop() {
	puts("NO");
	exit(0);
}

int main() {
	int n, i, j;
	int a[100005];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	if(a[n - 1] == 1) nop();
	if(n == 1) { printf("YES\n0\n"); return 0; }
	if(a[n - 2] == 1) {
		puts("YES");
		for(i = 0; i < n - 2; i++)
			printf("%d->", a[i]);
		printf("1->0\n");
		return 0;
	}
	for(i = n - 3; i >= 0 && a[i] == 1; i--);
	if(i == -1) nop();
	printf("YES\n(");
	for(j = 0; j < i; j++)
		printf("%d->", a[j]);
	printf("(0->(");
	for(j = i + 1; j < n - 2; j++)
		printf("1->");
	printf("0)))->0");
	return 0;	
}