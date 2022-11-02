#include<cstdio>
int main() {
	int n;
	scanf("%d", &n);
	if( (n-2) % 3 == 0 )
		printf("1 2 %d\n", n-3);
	else printf("1 1 %d\n", n-2);
}