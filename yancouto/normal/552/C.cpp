#include <cstdio>
#include <cstdlib>

typedef unsigned long long ull;

void imp() {
	puts("NO");
	exit(0);
}

int a[103];
// int b[103];
int main() {
	int ww, mm, i;
	scanf("%d %d", &ww, &mm);
	int dg = 0;
	while(mm) {
		int c = (mm % ww);
		a[dg++] = c;
		// printf("%d ", c);
		if(dg > 101) imp();
		mm /= ww;
	}
	// putchar('\n');
	for(i = 0; i < dg; i++) {
		// printf("%d^%d * %d \n", ww, i, a[i]);
		if(a[i] == ww) { a[i + 1]++; a[i] = 0; }
		else if(a[i] == 1) a[i] = 1;
		else if(a[i] == ww - 1) { a[i] = -1; a[i + 1]++; }
		else if(a[i]) imp();
	}
	if(a[101]) imp();
	for(i = 0; i <= 100; i++) {
		// printf("a[%d] = %d\n", i, a[i]);
		if(a[i] != 0 && a[i] != 1 && a[i] != -1)
			imp();
	}
	puts("YES");
	return 0;
}