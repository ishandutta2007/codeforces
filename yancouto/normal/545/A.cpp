#include <cstdio>

int main() {
	int good = 0;
	int g[102];
	int n, a;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		bool ok = true;
		for(int j = 0; j < n; j++) {
			scanf("%d", &a);
			if(a == 1 || a == 3) ok = false;
		}
		if(ok) g[good++] = i;
	}
	printf("%d\n", good);
	if(good > 0) printf("%d", g[0] + 1);
	for(int i = 1; i < good; i++)
		printf(" %d", g[i] + 1);
	if(good > 0) putchar('\n');
	return 0;
}